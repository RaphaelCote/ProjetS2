#include <cmath>

#include "game.h"
#include "../raftWars.h"
#include "../raftWars.h"
#include "rocket.h"
#include "canonball.h"

/*Méthodes*/
/*Constructeur (État Initial)*/
Game::Game()
{
    currentLevel = 0;
    turn = 0;
    isActive = false;
    isPlayerTurn = true;
    isPause = false;
    projectileType = 0;
    CreateLevels();
}

void OnGameMainActionCall(EventParameters ep)
{
    game->PlayerShoot();
}

void OnGameNextSelectionCall(EventParameters ep)
{
    game->ChangeProjectileType(1);
}

void OnGamePreviousSelectionCall(EventParameters ep)
{
    game->ChangeProjectileType(0);
}

void OnGameJoystickCall(EventParameters ep)
{
    float a = ep.parameter1;
    float strength = sqrt(a * a);
    game->ChangeProjectileStrength(strength);
}

void OnGameAngleCall(EventParameters ep)
{
    game->ChangeProjectileAngle(ep.parameter1);
}

void OnGameMenuCall(EventParameters ep)
{
    game->PauseGame();
}

void Game::ChangeProjectileType(int type)
{
    if (type == 0)
    {
        Niveau *level = levels[currentLevel];
        projectile = new Canonball(level->characters[0]->getPosition());
        projectileType = 0;
    }
    else if (type == 1)
    {
        Niveau *level = levels[currentLevel];
        projectile = new Rocket(level->characters[0]->getPosition());
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

bool Game::CreateLevels()
{
    levels[0] = new Niveau;
    levels[1] = new Niveau;
    levels[2] = new Niveau;
}

bool Game::PlayGame()
{
    isActive = true;
    isPause = false;

    cout << "Stating game ..." << endl;

    system("PAUSE");

    // 1 boucle = 1 tour
    while (isActive)
    {
        PlayTurn();
    }

    return isActive;
}

void Game::PauseGame()
{
    OnDisable();
    isPause = true;
    while (isPause)
    {
        menu->menuController(1);
    }
}

bool Game::NextLevel()
{
    if (currentLevel < levels.getSize())
    {
        currentLevel++;
    }
}

bool Game::EndGame()
{
    isActive = false;
    return isActive;
}

void Game::PlayTurn()
{
    OnEnable();
    projectileType = 0;
    Niveau *level = levels[currentLevel];
    projectile = new Canonball(level->characters[0]->getPosition());
    while (isPlayerTurn)
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
        controls->ListenForControls();
    }
    system("PAUSE");

    system("cls");
    ShowGameInfo();
    cout << "Tour enemi :" << endl;

    system("PAUSE");
    isPlayerTurn = true;
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

bool Game::CheckWinCondition()
{
    /*Voir avec la classe Personnage*/
}

bool Game::CheckLoseCondition()
{
    /*Voir avec la classe Personnage*/
}

void Game::ShowGameInfo()
{
    // Show player positions and health
    levels[currentLevel]->ShowCharacterInfo();
}