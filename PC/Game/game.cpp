#include "game.h"
#include "../raftWars.h"

#define MAX_LEVEL 5
/*Méthodes*/
/*Constructeur (État Initial)*/
Game::Game()
{
    Active = false;
    actualLevel = 1;
    actualTurn = true;
    Pause = false;
    levels[0] = new Niveau;
    levels[1] = new Niveau;
    levels[2] = new Niveau;
}

void Game::OnDisable()
{
}

void Game::OnEnable()
{
}

bool Game::StartGame()
{
    Active = true;

    cout << "Stating game ..." << endl;

    system("PAUSE");

    return Active;
}

bool Game::PauseGame()
{
    Pause = true;
    return Pause;
}

bool Game::NextLevel()
{
    if (actualLevel < MAX_LEVEL)
    {
        actualLevel = actualLevel + 1;
    }

    else
    {
        cout << "Vous etes au niveau maximal. Veuillez entrer un niveau plus bas que" << MAX_LEVEL << endl;
    }
}

bool Game::EndGame()
{
    Active = false;
    return Active;
}

void Game::PlayTurn()
{
    /*Voir avec la classe Personnage*/
    actualTurn = true;
}

bool Game::CreateLevels()
{
}

bool Game::CheckWinCondition()
{
    /*Voir avec la classe Personnage*/
}

bool Game::CheckLoseCondition()
{
    /*Voir avec la classe Personnage*/
}