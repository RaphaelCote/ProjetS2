//playerCharacter.h
#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H
#include "character.h"
#include "projectile.h"

#include <cmath>
#include <iostream> 

const float PI = 3.14159;
class PlayerCharacter : public Character{
    public:
        
        PlayerCharacter(int posx,int posy);
        ~PlayerCharacter();
        Coordonnee getWeaponPosition() override;
        void setWeaponPosition(Coordonnee WeaponPosition);
        float Aim(float angle) override;
    private:
        Coordonnee WeaponPosition;
}; 
#endif