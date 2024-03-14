// character.h
#ifndef CHARACTER_H
#define CHARACTER_H
#include "utility.h"
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
    Coordonnee *PointeurPosition();
    virtual Coordonnee getWeaponPosition() = 0;
    virtual void setWeaponPosition(Coordonnee WeaponPosition) = 0;
    int getHitbox(); 
    int getHitboxWidth();
    int getHitboxHeight();
    virtual float Aim(float angle);
    void ShowInfo();

protected:
    int healthPoint;
    Coordonnee position;
    Coordonnee WeaponPosition;
    Hitbox hitbox;
};

#endif