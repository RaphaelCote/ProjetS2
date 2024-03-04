#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "../vecteur.h"
#include "../Game/niveau.h"
#include "../Game/projectile.h"
#include "../controls/EventParameters.h"
#include "scene.h"

using namespace std;

class Game : public Scene
{
private:
    bool isPause;
    int turn;
    int oldLevel;
    bool isPlayerTurn;
    int projectileType;
    Projectile *projectile;

    /*PERSONNAGE 1 ET PERSONNAGE 2*/
    /*ne pas oublier d'inclure vecteur et le const (si nécessaire)*/
public:
    int currentLevel;
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

    void Update();
    bool CreateLevels();
    void PlayTurn();
    void PlayerShoot();
    void PauseGame();
    void EndGame();
    bool CheckEndCondition();
    void ShowGameInfo();
};

#endif