#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "../Game/niveau.h"
#include "../Game/projectile.h"
#include "../controls/EventParameters.h"
#include "scene.h"
#include "../Game/gameloader.h"
#include "../Game/character.h"
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
    bool doOnce;
    bool isNewLevel;
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
    friend void OnGameBackCall(EventParameters);

    void ChangeProjectileType(int typeDef);
    void ChangeProjectileStrength(float strength);
    void ChangeProjectileAngle(float type);
    void ToggleZoomedOut();

    void OnDisable();
    void OnEnable();

    void Update();
    void PlayTurn();
    void PlayerShoot();
    void PauseGame();
    void EndGame();
    int PayPlayer();
    void StoreShield();
    void StopGame();
    bool CheckEndCondition();
    bool CheckAvailableProjectile(int type);
    void ShowGameInfo();
    void UpdateWeaponInfo();
    Character* FirstAlivePlayer();
    void AnimationVersPersonnage(Character* character);
    void AnimationProjectile(Projectile *projectile);
    void AnimationExplosion(Projectile* projectile);
};

#endif