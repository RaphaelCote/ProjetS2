// projectile.h
#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "utility.h"
#include "character.h"
#include "../Vecteur.h"
//c'est le "#include "../raftWars.h"" qui fait chier le pain
#include "../Scenes/maping.h"

// #include "niveau.h"
#include <iostream>
#include <cmath>
#include <typeinfo>

#include "utility.h"
#include "character.h"

const float g = -1000;

const double  PI = 3.14159;
const float masseProjectile = 0.05; // en kg
const float dampingProjectile = 0.8;
class Projectile {

public:
    Projectile(Character &character);
    Projectile(Coordonnee bulletStartPosition);
    Projectile(Coordonnee bulletStartPosition, Hitbox hitboxset);
    float getPuissance();
    void setPuissance(float puissance);
    float getAngleDegre();
    void setAngleDegre(float angledeg);
    Coordonnee getbulletStartPosition();
    void setbulletStartPosition(Coordonnee bulletStartPosition);
    Coordonnee getBulletEndPosition();
    virtual int getProjectileMaxSpeed() = 0;
    void checkIfCharacterHit(Vecteur<Character*> character);
    virtual int damageReceived(Character &character) = 0;
    Hitbox hitbox;

    Coordonnee bulletCurrentPosition;
    Coordonnee bulletStartPosition; // coordonnée de départ du projectile
    Coordonnee bulletEndPosition;   // coordonnée de fin du projectile

    int findBulletPositionX(int positionY);
    int findBulletPositionY(int positionX);
    int findBulletPositionYTime(float time);
    int findBulletPositionYAngle(float angle);// pas utilisé présentement 
    float findNegativeAngleBulletPositionY(int positionY);//pour les rebond vertical courbe bleu
    float findPositiveAngleBulletPositionY(int positionY);//la courbe verte
    float angledeg;
    float rad;
    float V0;
    //-----------BOUNCE-----------//
    //void ScanHitboxes();
    
    void BounceHorizontal(Niveau* activeLevel);
    void BounceVerticale(Niveau* activeLevel);
    void CheckerBounce(Niveau* activeLevel);
        

protected:
    // time_t temps;

    float puissance;
};

#endif