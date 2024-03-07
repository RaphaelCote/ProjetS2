#include <cmath>

#include "game.h"
#include "../raftWars.h"
#include "../Game/rocket.h"
#include "../Game/canonball.h"
#include "../Game/grenade.h"
#include "../Game/enemyCharacter.h"

/*Méthodes*/
/*Constructeur (État Initial)*/
Game::Game()
{
    currentLevel = 0;
    turn = 0;
    isPlayerTurn = true;
    isPause = false;
    isNewLevel = true;
    projectileType = 0;
    CreateLevels();
    Niveau *level = levels[currentLevel];
    projectile = new Canonball(level->characters[0]->getWeaponPosition());
}

int Game::GetLevel()
{
    return currentLevel;
}

void Game::SetLevel(int level)
{
    currentLevel = level;
}

void OnGameMainActionCall(EventParameters ep)
{
    Game *game = (Game *)scenes->get(1);
    game->PlayerShoot();
}

void OnGameNextSelectionCall(EventParameters ep)
{
    Game *game = (Game *)scenes->get(1);
    game->ChangeProjectileType(1);
}

void OnGamePreviousSelectionCall(EventParameters ep)
{
    Game *game = (Game *)scenes->get(1);
    game->ChangeProjectileType(-1);
}

void OnGameJoystickCall(EventParameters ep)
{
    Game *game = (Game *)scenes->get(1);
    float a = ep.parameter1;
    float strength = sqrt(a * a);
    game->ChangeProjectileStrength(strength);
}

void OnGameAngleCall(EventParameters ep)
{
    Game *game = (Game *)scenes->get(1);
    game->ChangeProjectileAngle(ep.parameter1);
}

void OnGameMenuCall(EventParameters ep)
{
    Game *game = (Game *)scenes->get(1);
    game->PauseGame();
}

void Game::ChangeProjectileType(int typeDif)
{
    if (typeDif > 0)
    {
        for (int i = projectileType; i <= 2; i++)
        {
            if (CheckAvailableProjectile(i))
            {
                projectileType = i;
            }
        }
    }
    else if (typeDif < 0)
    {
        for (int i = projectileType; i >= 0; i--)
        {
            if (CheckAvailableProjectile(i))
            {
                projectileType = i;
            }
        }
    }

    float angle = projectile->getAngleDegre();
    float puissance = projectile->getPuissance();

    Niveau *level = levels[currentLevel];

    if (projectileType == 0)
    {
        projectile = new Canonball(level->characters[0]->getWeaponPosition());
    }
    else if (projectileType == 1)
    {
        projectile = new Rocket(level->characters[0]->getWeaponPosition());
    }
    else if (projectileType == 2)
    {
        projectile = new Grenade(level->characters[0]->getWeaponPosition());
    }

    projectile->setAngleDegre(angle);
    projectile->setPuissance(puissance);
}

void Game::ChangeProjectileStrength(float strength)
{
    projectile->setPuissance(strength);
}

void Game::ChangeProjectileAngle(float angle)
{
    projectile->setAngleDegre(angle);
}

void Game::OnEnable()
{
    eventManager->on("MainAction", OnGameMainActionCall);
    eventManager->on("NextSelection", OnGameNextSelectionCall);
    eventManager->on("PreviousSelection", OnGamePreviousSelectionCall);
    eventManager->on("Joystick", OnGameJoystickCall);
    eventManager->on("Angle", OnGameAngleCall);
    eventManager->on("Menu", OnGameMenuCall);
}

void Game::OnDisable()
{
    eventManager->off("MainAction", OnGameMainActionCall);
    eventManager->off("NextSelection", OnGameNextSelectionCall);
    eventManager->off("PreviousSelection", OnGamePreviousSelectionCall);
    eventManager->off("Joystick", OnGameJoystickCall);
    eventManager->off("Angle", OnGameAngleCall);
    eventManager->off("Menu", OnGameMenuCall);
}

void Game::Update()
{
    OnEnable();

    if (isNewLevel)
    {
        // Load level from start
        turn == 0;
        isPlayerTurn = true;
        projectileType = 0;
        CreateLevels();

        // Ajouter le shield au joueur
        Niveau *level = levels[currentLevel];
        // cout << "Shield : " << inventory->getShield() << endl;
        int newHealthPoints = level->characters[0]->getHealthPoint() + inventory->getShield();
        // cout << "newHealthPoints : " << newHealthPoints << endl;
        level->characters[0]->setHealthPoint(newHealthPoints);
        // cout << "Current healthPoints : " << level->characters[0]->getHealthPoint() << endl;
        // system("PAUSE");
    }

    isNewLevel = false;
    PlayTurn();
}

void Game::CreateLevels()
{
    levels[0] = new Niveau;
    levels[1] = new Niveau;
    levels[2] = new Niveau;
}

void Game::PlayTurn()
{
    turn++;
    Niveau *level = levels[currentLevel];
    if (isPlayerTurn)
    {
        system("cls");
        ShowGameInfo();

        cout << endl;
        cout << "Inventaire : " << inventory->getRockets() << " rockets, " << inventory->getGrenade() << " grenades" << endl;

        cout << "Projectile selectionne : ";
        if (projectileType == 0)
        {
            cout << "Balle" << endl;
        }
        else if (projectileType == 1)
        {
            cout << "Rocket" << endl;
        }
        else if (projectileType == 2)
        {
            cout << "Grenade" << endl;
        }

        cout << endl;

        cout << "Votre angle : " << projectile->getAngleDegre() << " | Votre puissance : " << projectile->getPuissance() << endl;

        cout << "\n"
                "-------FORMULE DE LA PARABOLE-------"
             << endl;
        cout << "y = g"
             << "x^2 / (2(" << projectile->getPuissance() << "Vmax)^2 . cos^2(" << projectile->getAngleDegre() * PI / 180 << ") ) + xtan(" << projectile->getAngleDegre() * PI / 180 << ")"
             << "\n"
             << endl;
        controls->ListenForControls();
    }
    else
    {
        system("PAUSE");

        system("cls");
        ShowGameInfo();
        cout << "Tour enemi :" << endl;

        EnemyCharacter *ec = (EnemyCharacter *)level->characters[1];
        Projectile *enemyProjectile = ec->createEnemyProjectile();

        cout << "Angle : " << enemyProjectile->getAngleDegre() << " | Puissance : " << enemyProjectile->getPuissance() << endl;

        if (enemyProjectile->checkIfCharacterHit(*(level->characters[0])))
        {
            cout << " (" << enemyProjectile->getBulletEndPosition().x << ", " << enemyProjectile->getBulletEndPosition().y << ")" << endl;
        }
        else
        {
            cout << "Le projectile ne vous a pas atteint. Il a atteri a la position: (" << enemyProjectile->getBulletEndPosition().x;
            cout << ", " << enemyProjectile->getBulletEndPosition().y << ")" << endl;
        }

        system("PAUSE");
        isPlayerTurn = true;
        projectile = new Canonball(level->characters[0]->getWeaponPosition());
    }

    if (CheckEndCondition())
    {
        EndGame();
    }
}

void Game::PlayerShoot()
{
    if (!isPlayerTurn)
    {
        return;
    }

    Niveau *level = levels[currentLevel];

    if (projectile->checkIfCharacterHit(*(level->characters[1])))
    {
        cout << " (" << projectile->getBulletEndPosition().x << ", " << projectile->getBulletEndPosition().y << ")" << endl;
    }
    else
    {
        cout << "Le projectile n'a pas atteint l'adversaire. Il a atteri a la position: (" << projectile->getBulletEndPosition().x;
        cout << ", " << projectile->getBulletEndPosition().y << ")" << endl;
    }

    // Remove special projectiles if fired, and if no more special projectiles are available, change to previous type
    if (projectileType == 1)
    {
        inventory->removeRockets();
        if (inventory->getRockets() == 0)
        {
            ChangeProjectileType(-1);
        }
    }
    else if (projectileType == 2)
    {
        inventory->removeGrenade();
        if (inventory->getGrenade() == 0)
        {
            ChangeProjectileType(-1);
        }
    }

    isPlayerTurn = false;
}

void Game::PauseGame()
{
    OnDisable();
    activeScene = 4;
}

void Game::EndGame()
{
    PayPlayer();
    system("PAUSE");
    OnDisable();
    StopGame();
    activeScene = 3;
}

void Game::PayPlayer()
{
    Niveau *level = levels[currentLevel];

    if (level->characters[0]->getHealthPoint() == 0)
    {
        // Player dead
        inventory->addGold(200);
        cout << "-------------------------------------------------------------------" << endl;
        cout << "Vous avec recu 200$" << endl;
        cout << "-------------------------------------------------------------------" << endl;
    }
    else
    {
        // Enemy dead
        inventory->addGold(1200);
        cout << "-------------------------------------------------------------------" << endl;
        cout << "Vous avec recu 1200$" << endl;
        cout << "-------------------------------------------------------------------" << endl;
    }
}

void Game::StoreShield()
{
    Niveau *level = levels[currentLevel];

    int playerHealth = level->characters[0]->getHealthPoint();

    if (playerHealth > 100)
    {
        inventory->setShield(playerHealth - 100);
    }
}

void Game::StopGame()
{
    StoreShield();
}

bool Game::CheckEndCondition()
{
    Niveau *level = levels[currentLevel];

    if (level->characters[0]->getHealthPoint() == 0 || level->characters[1]->getHealthPoint() == 0)
    {
        return true;
    }

    return false;
}

bool Game::CheckAvailableProjectile(int type)
{
    if (type == 0)
    {
        return true;
    }
    else if (type == 1)
    {
        if (inventory->getRockets() > 0)
        {
            return true;
        }
    }
    else if (type == 2)
    {
        if (inventory->getGrenade() > 0)
        {
            return true;
        }
    }

    return false;
}

void Game::ShowGameInfo()
{
    // Show player positions and health
    cout << "-------Niveau " << currentLevel + 1 << "-------" << endl;
    levels[currentLevel]->ShowCharacterInfo(cout);
}