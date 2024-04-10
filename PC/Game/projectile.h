// projectile.h
#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <iostream>
#include <cmath>
#include <typeinfo>

#include "utility.h"
#include "character.h"

const float g = -1000;

const double PI = 3.14159265358979323846;

class Projectile
{

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
    bool checkIfCharacterHit(Character &character);
    void checkIfCharactersHit(std::vector<Character*> characters);
    virtual int damageReceived(Character &character) = 0;
    Hitbox hitbox;

    Coordonnee bulletCurrentPosition;
    Coordonnee bulletStartPosition; // coordonnée de départ du projectile
    Coordonnee bulletEndPosition;   // coordonnée de fin du projectile
    float angleRotationProjectile;

    int findBulletPositionX(int positionY);
    int findBulletPositionY(int positionX);
    int findBulletPositionYTime(float time);
    float angledeg;
    float rad;
    float V0;

protected:
    // time_t temps;

    float puissance;
};

#endif