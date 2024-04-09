// character.h
#ifndef CHARACTER_H
#define CHARACTER_H
#include "utility.h"
// #include "projectile.h"
#include <iostream>


class Character
{
public:
    Character(int posX, int posY);
    Character(Coordonnee position, Hitbox hitbox, std::string image);
    ~Character();

    int getHealthPoint();
    void setHealthPoint(int healthPoint);
    Coordonnee getPosition();
    Coordonnee *PointeurPosition();
    int* GetPointeurX();
    int* GetPointeurY();
    virtual Coordonnee getWeaponPosition() = 0;
    virtual void setWeaponPosition(Coordonnee WeaponPosition) = 0;
    int getHitboxWidth();
    int getHitboxHeight();
    virtual float Aim(float angle);
    void ShowInfo();
    std::string getimage();
    void setPosition(Coordonnee coor);

    std::string imagecharacter;
protected:
    int healthPoint;

    Coordonnee WeaponPosition;
    Hitbox hitbox;
    
    Coordonnee position;
};

#endif