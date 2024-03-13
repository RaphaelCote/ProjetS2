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
    int currentLevel;
    bool isPlayerTurn;
    int projectileType;
    Projectile *projectile;

    /*PERSONNAGE 1 ET PERSONNAGE 2*/
    /*ne pas oublier d'inclure vecteur et le const (si nécessaire)*/
public:
    bool isNewLevel;
    Vecteur<Niveau *> levels;
    Game();
    int GetLevel();
    void SetLevel(int level);

    friend void OnGameMainActionCall(EventParameters);
    friend void OnGameNextSelectionCall(EventParameters);
    friend void OnGamePreviousSelectionCall(EventParameters);
    friend void OnGameJoystickCall(EventParameters);
    friend void OnGameAngleCall(EventParameters);
    friend void OnGameMenuCall(EventParameters);

    void ChangeProjectileType(int typeDef);
    void ChangeProjectileStrength(float strength);
    void ChangeProjectileAngle(float type);

    void OnDisable();
    void OnEnable();

    void Update();
    void CreateLevels();
    void PlayTurn();
    void PlayerShoot();
    void PauseGame();
    void EndGame();
    void PayPlayer();
    void StoreShield();
    void StopGame();
    bool CheckEndCondition();
    bool CheckAvailableProjectile(int type);
    void ShowGameInfo();
};

#endif