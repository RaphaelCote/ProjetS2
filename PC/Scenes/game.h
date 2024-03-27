#ifndef GAME_H
#define GAME_H

#include "../Game/projectile.h"
#include "../vecteur.h"
#include "../Game/niveau.h"

#include "../controls/EventParameters.h"
#include "scene.h"
#include <iostream>
#include "../Game/gameloader.h"

using namespace std;
//class Projectile;       //  À CHANGER : potentiellement source de problème (segmentation fault)
class Game : public Scene
{
private:
    bool isPause;
    int turn;
    int currentLevelIndex;
    bool isPlayerTurn;
    int projectileType;
    Projectile *projectile;
    Gameloader gameloader;

    /*PERSONNAGE 1 ET PERSONNAGE 2*/
    /*ne pas oublier d'inclure vecteur et le const (si nécessaire)*/
public:
    bool isNewLevel;
    Vecteur<Hitbox> allHitboxObject;
    Niveau *activeLevel;
    Game();
    int GetLevelIndex();
    void SetLevelIndex(int level);

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
    void ScanHitboxes();
};

#endif