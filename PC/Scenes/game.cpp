#include <cmath>

#include "game.h"
#include "../raftWars.h"
#include "../Game/rocket.h"
#include "../Game/canonball.h"
#include "../Game/grenade.h"
#include "../Game/enemyCharacter.h"

std::chrono::_V2::system_clock::time_point startAnimation;
std::chrono::duration<double, std::milli> currentclockAnimation;
std::chrono::duration<double, std::milli> lastClockAnimation;
std::chrono::duration<double, std::milli> rcvSerialTimerAnimation;

/*Méthodes*/
/*Constructeur (État Initial)*/
Game::Game()
{
    currentLevelIndex = 0;
    turn = 0;
    isPlayerTurn = true;
    isPause = false;
    isNewLevel = true;
    projectileType = 0;
}

int Game::GetLevelIndex()
{
    return currentLevelIndex;
}

void Game::SetLevelIndex(int level)
{
    currentLevelIndex = level;
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
        for (int i = projectileType + 1; i <= 2; i++)
        {
            if (CheckAvailableProjectile(i))
            {
                projectileType = i;
                break;
            }
        }
    }
    else if (typeDif < 0)
    {
        for (int i = projectileType - 1; i >= 0; i--)
        {
            if (CheckAvailableProjectile(i))
            {
                projectileType = i;
                break;
            }
        }
    }

    float angle = projectile->getAngleDegre();
    float puissance = projectile->getPuissance();

    if (projectileType == 0)
    {
        projectile = new Canonball(activeLevel->playerBoats[0]->characters[0]->getWeaponPosition());
    }
    else if (projectileType == 1)
    {
        projectile = new Rocket(activeLevel->playerBoats[0]->characters[0]->getWeaponPosition());
    }
    else if (projectileType == 2)
    {
        projectile = new Grenade(activeLevel->playerBoats[0]->characters[0]->getWeaponPosition());
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
        // Load level currentLevelIndex
        activeLevel = gameloader.getLevelFromJson(levelGetter->levels[currentLevelIndex]);

        projectile = new Canonball(activeLevel->playerBoats[0]->characters[0]->getWeaponPosition());

        // Ajouter le shield au joueur
        for (int i = 0; i < activeLevel->playerBoats.getSize(); i++)
        {
            for (int j = 0; j < activeLevel->playerBoats[i]->characters.getSize(); j++)
            {
                int newHealthPoints = activeLevel->playerBoats[i]->characters[j]->getHealthPoint() + inventory->getShield();
                activeLevel->playerBoats[i]->characters[j]->setHealthPoint(newHealthPoints);
            }
        }

        activeLevel->MatWater();
        activeLevel->MatNuage();
        activeLevel->MatRaft();
        activeLevel->MatCharacter();
        activeLevel->MatEnemy();
    }

    isNewLevel = false;
    PlayTurn();
}

void Game::PlayTurn()
{
    turn++;
    if (isPlayerTurn)
    {
        // system("cls");
        // ShowGameInfo();

        // cout << endl;
        // cout << "Inventaire : " << inventory->getRockets() << " rockets, " << inventory->getGrenade() << " grenades" << endl;

        // cout << "Projectile selectionne : ";
        if (projectileType == 0)
        {
            // cout << "Balle" << endl;
        }
        else if (projectileType == 1)
        {
            // cout << "Rocket" << endl;
        }
        else if (projectileType == 2)
        {
            // cout << "Grenade" << endl;
        }

        // cout << endl;

        // cout << "Votre angle : " << projectile->getAngleDegre() << " | Votre puissance : " << projectile->getPuissance() << endl;

        // cout << "\n"
        //         "-------FORMULE DE LA PARABOLE-------"
        //      << endl;
        // cout << "y = g"
        //      << "x^2 / (2(" << projectile->getPuissance() << "Vmax)^2 . cos^2(" << projectile->getAngleDegre() * PI / 180 << ") ) + xtan(" << projectile->getAngleDegre() * PI / 180 << ")"
        //      << "\n"
        //      << endl;
    }
    else
    {
        // system("PAUSE");

        // system("cls");
        // ShowGameInfo();
        // cout << "Tour enemi :" << endl;

        EnemyCharacter *ec = (EnemyCharacter *)activeLevel->enemyBoats[0]->characters[0];
        Projectile *enemyProjectile = ec->createEnemyProjectile();

        // cout << "Angle : " << enemyProjectile->getAngleDegre() << " | Puissance : " << enemyProjectile->getPuissance() << endl;

        activeLevel->MatBalle(enemyProjectile);
        
        enemyProjectile->checkIfCharacterHit(*(activeLevel->playerBoats[0]->characters[0]));

        AnimationProjectile(enemyProjectile);


        isPlayerTurn = true;
        // projectile = new Canonball(activeLevel->playerBoats[0]->characters[0]->getWeaponPosition());
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

    if (projectileType == 0)
    {
        activeLevel->MatBalle(projectile);
    }
    else if (projectileType == 1)
    {
        activeLevel->MatRocket(projectile);
    }
    else if (projectileType == 2)
    {
        activeLevel->MatGrenade(projectile);
    }

    projectile->checkIfCharacterHit(*(activeLevel->enemyBoats[0]->characters[0]));
    
    AnimationProjectile(projectile);


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
    OnDisable();
    StopGame();
    activeScene = 3;
}

void Game::PayPlayer()
{
    bool isAllPlayerDead = true;

    for (int i = 0; i < activeLevel->playerBoats.getSize(); i++)
    {
        for (int j = 0; j < activeLevel->playerBoats[i]->characters.getSize(); j++)
        {

            if (activeLevel->playerBoats[i]->characters[j]->getHealthPoint() > 0)
            {
                isAllPlayerDead = false;
            }
        }
    }

    // Check if all players are dead
    if (isAllPlayerDead)
    {
        // Player dead
        inventory->addGold(200);
        // cout << "-------------------------------------------------------------------" << endl;
        // cout << "Vous avec recu 200$" << endl;
        // cout << "-------------------------------------------------------------------" << endl;
    }
    else
    {
        // Enemy dead
        inventory->addGold(1200);
        // cout << "-------------------------------------------------------------------" << endl;
        // cout << "Vous avec recu 1200$" << endl;
        // cout << "-------------------------------------------------------------------" << endl;
    }
}

void Game::StoreShield()
{
    int totalHealth = 0;
    int nbPlayer = 0;

    for (int i = 0; i < activeLevel->playerBoats.getSize(); i++)
    {
        for (int j = 0; j < activeLevel->playerBoats[i]->characters.getSize(); j++)
        {
            totalHealth += activeLevel->playerBoats[i]->characters[j]->getHealthPoint();
            nbPlayer++;
        }
    }

    int averageHealth = totalHealth / nbPlayer;

    if (averageHealth > 100)
    {
        inventory->setShield(averageHealth - 100);
    }
}

void Game::StopGame()
{
    StoreShield();
}

bool Game::CheckEndCondition()
{
    for (int i = 0; i < activeLevel->playerBoats.getSize(); i++)
    {
        for (int j = 0; j < activeLevel->playerBoats[i]->characters.getSize(); j++)
        {
            bool isAllPlayerDead = true;
            if (activeLevel->playerBoats[i]->characters[j]->getHealthPoint() > 0)
            {
                isAllPlayerDead = false;
            }

            if (isAllPlayerDead)
            {
                return true;
            }
        }
    }

    for (int i = 0; i < activeLevel->enemyBoats.getSize(); i++)
    {
        for (int j = 0; j < activeLevel->enemyBoats[i]->characters.getSize(); j++)
        {
            bool isAllEnemyDead = true;
            if (activeLevel->enemyBoats[i]->characters[j]->getHealthPoint() > 0)
            {
                isAllEnemyDead = false;
            }

            if (isAllEnemyDead)
            {
                return true;
            }
        }
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
    // cout << "-------Niveau " << currentLevelIndex + 1 << "-------" << endl;
    activeLevel->ShowLevelInfo(cout);
}



void Game::AnimationProjectile(Projectile* projectile)
{
    bool animation = true;
    Coordonnee currentPosition = projectile->bulletStartPosition;
    Coordonnee endPosition = projectile->bulletEndPosition;
    float time = 0.0f;
    bool coterAnimationGauche;

    //Pour debug
    //endPosition.x = 1000;
    ////////////////////////////////////////////////////////////////////////////////



    if (currentPosition.x - endPosition.x <= 0)
        coterAnimationGauche = true;
    else
        coterAnimationGauche = false;

    startAnimation = std::chrono::high_resolution_clock::now();


    while(animation)
    {
        lastClockAnimation = currentclockAnimation;
        const auto now = std::chrono::high_resolution_clock::now();
        currentclockAnimation = now - startAnimation;

        if ((currentclockAnimation.count() - rcvSerialTimerAnimation.count()) > 10000)
        {
            time += 0.0005;

            currentPosition.y = projectile->findBulletPositionYTime(time);
            // currentPosition.x = projectile->findBulletPositionX(currentPosition.y);
            currentPosition.x++;
            currentPosition.y = projectile->findBulletPositionY(currentPosition.x);
            projectile->bulletCurrentPosition = currentPosition;
            cons->Mincolums = (currentPosition.x - (cons->MaxColumns*10 - cons->Mincolums*10)/2)/10;//je fais * 10 pcq c l'affichage console

            cons->SupprimerObjet("text");
            cons->SupprimerObjet("text2");
            cons->SupprimerObjet("text3");
            cons->SupprimerObjet("text4");

            cons->AfficherTexte(std::cout, "BulletPositionX: " + to_string(projectile->bulletCurrentPosition.x), cons->Mincolums*10+(cons->MaxColumns*10 - cons->Mincolums*10)/2, 150, "text");
            cons->AfficherTexte(std::cout, "BulletEndPositionX: " + to_string(projectile->bulletEndPosition.x), cons->Mincolums*10+(cons->MaxColumns*10 - cons->Mincolums*10)/2, 140, "text2");
            cons->AfficherTexte(std::cout, "BulletAngle: " + to_string(projectile->angledeg), cons->Mincolums*10+(cons->MaxColumns*10 - cons->Mincolums*10)/2, 130, "text3");
            cons->AfficherTexte(std::cout, "Time: " + to_string(time), cons->Mincolums*10+(cons->MaxColumns*10 - cons->Mincolums*10)/2, 120, "text4");

            if (coterAnimationGauche)
            {
                if(currentPosition.x >= endPosition.x)
                    animation = false;
            }
            else
            {
                if(currentPosition.x <= endPosition.x)
                    animation = false;
            }
        }

        Sleep(1);



    }

}