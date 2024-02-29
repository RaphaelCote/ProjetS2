#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "../vecteur.h"
#include "niveau.h"
#include "projectile.h"
#include "../controls/EventParameters.h"

using namespace std;

class Game
{
private:
    bool isActive;
    int currentLevel;
    int turn;
    bool isPlayerTurn;
    int projectileType;
    Projectile *projectile;

    /*PERSONNAGE 1 ET PERSONNAGE 2*/
    /*ne pas oublier d'inclure vecteur et le const (si nécessaire)*/
public:
    bool isPause;
    Vecteur<Niveau *> levels;
    Game();

    friend void OnGameMainActionCall(EventParameters);
    friend void OnGameNextSelectionCall(EventParameters);
    friend void OnGamePreviousSelectionCall(EventParameters);
    friend void OnGameJoystickCall(EventParameters);
    friend void OnGameAngleCall(EventParameters);
    friend void OnGameMenuCall(EventParameters);

    void ChangeProjectileType(int type);
    void ChangeProjectileStrength(float strength);
    void ChangeProjectileAngle(float type);

    void OnDisable();
    void OnEnable();

    bool CreateLevels();
    bool PlayGame();
    void PauseGame();
    bool NextLevel();
    bool EndGame();
    void PlayTurn();
    void PlayerShoot();
    bool CheckWinCondition();
    bool CheckLoseCondition();
    void ShowGameInfo();
};

#endif