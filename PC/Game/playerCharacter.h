//playerCharacter.h
#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H
#include "character.h"
#include "projectile.h"

#include <cmath>
#include <iostream> 

#define PI 3.14159265358979323846
class PlayerCharacter : public Character{
    public:
        
        PlayerCharacter(int posx,int posy,int width,int height, int image);
        ~PlayerCharacter();
        Coordonnee getWeaponPosition() override;
        void setWeaponPosition(Coordonnee WeaponPosition);
        float Aim(float angle) override;
    private:
        Coordonnee WeaponPosition;
}; 
#endif