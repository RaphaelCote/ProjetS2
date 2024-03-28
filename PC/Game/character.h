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
    Character(int posX, int posY);
    Character(Coordonnee position, Hitbox hitbox, int image);
    ~Character();

    int getHealthPoint();
    void setHealthPoint(int healthPoint);
    Coordonnee getPosition();
    Coordonnee *PointeurPosition();
    virtual Coordonnee getWeaponPosition() = 0;
    virtual void setWeaponPosition(Coordonnee WeaponPosition) = 0;
    Hitbox getHitbox(); 
    int getHitboxWidth();
    int getHitboxHeight();
    virtual float Aim(float angle);
    void ShowInfo();
    int getimage();
    void setPosition(Coordonnee coor);

protected:
    int healthPoint;

    Coordonnee WeaponPosition;
    Hitbox hitbox;
    int imagecharacter;
    Coordonnee position;
};

#endif