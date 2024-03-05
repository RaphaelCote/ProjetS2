#include <cmath>

#include "game.h"
#include "../raftWars.h"
#include "../Game/rocket.h"
#include "../Game/canonball.h"
#include "../Game/enemyCharacter.h"

/*Méthodes*/
/*Constructeur (État Initial)*/
Game::Game()
{
    currentLevel = 0;
    turn = 0;
    isPlayerTurn = true;
    isPause = false;
    projectileType = 0;
    CreateLevels();
    Niveau *level = levels[currentLevel];
    projectile = new Canonball(level->characters[0]->getWeaponPosition());
}

void OnGameMainActionCall(EventParameters ep)
{
    Game *game = (Game *)scenes->get(1);
    game->PlayerShoot();
}

void OnGameNextSelectionCall(EventParameters ep)
{
    Game *game = (Game *)scenes->get(1);
    int newType = game->projectileType;
    if (newType < 1)
    {
        newType++;
    }

    game->ChangeProjectileType(newType);
}

void OnGamePreviousSelectionCall(EventParameters ep)
{
    Game *game = (Game *)scenes->get(1);
    int newType = game->projectileType;
    if (newType > 0)
    {
        newType--;
    }

    game->ChangeProjectileType(newType);
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

void Game::ChangeProjectileType(int type)
{
    if (type == 0)
    {
        Niveau *level = levels[currentLevel];
        projectile = new Canonball(level->characters[0]->getWeaponPosition());
        projectileType = 0;
    }
    else if (type == 1)
    {
        Niveau *level = levels[currentLevel];
        projectile = new Rocket(level->characters[0]->getWeaponPosition());
        projectileType = 1;
    }
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

    if (isPause)
    {
        // Load level from start
        turn == 0;
    }
    isPause = false;
    // Else, just continu with active level

    PlayTurn();
}

bool Game::CreateLevels()
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

        if (projectileType == 0)
        {
            cout << "Votre projectile : balle" << endl;
        }
        else
        {
            cout << "Votre projectile : rocket" << endl;
        }
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

    isPlayerTurn = false;
}

void Game::PauseGame()
{
    OnDisable();
    isPause = true;
    activeScene = 4;
}

void Game::EndGame()
{
    OnDisable();
    activeScene = 3;
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

void Game::ShowGameInfo()
{
    // Show player positions and health
    levels[currentLevel]->ShowCharacterInfo(cout);
}