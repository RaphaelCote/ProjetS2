// character.h
#ifndef CHARACTER_H
#define CHARACTER_H
#include "utility.h"
#include "shield.h"
// #include "projectile.h"
#include <iostream>

using namespace std;

class Character
{
public:
    Character(int posx, int posy);
    ~Character();

    int getHealthPoint();
    void setHealthPoint(int healthPoint);
    Coordonnee getPosition();
    virtual Coordonnee getWeaponPosition() = 0;
    virtual void setWeaponPosition(Coordonnee WeaponPosition) = 0;
    int getHitboxWidth();
    int getHitboxHeight();
<<<<<<< HEAD
    void applyShield(Shield& shield);
=======
    Coordonnee* PointeurPosition();
>>>>>>> Branche-de-magouille(ur)

    virtual float Aim(float angle);
    void ShowInfo();

protected:
    int healthPoint;
    Coordonnee position;
    Coordonnee WeaponPosition;
    Hitbox hitbox;
    Shield shield;
};

#endif