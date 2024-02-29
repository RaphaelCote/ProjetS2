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
        
        PlayerCharacter(int posx,int posy);
        ~PlayerCharacter();
        int findBulletPositionY(float puissance,float angledeg,int deltax);
        int findBulletPositionX(float puissance,float angledeg,int deltay);
        
        
        Coordonnee getWeaponPosition() override{
            return WeaponPosition;
        }
        void setWeaponPosition(Coordonnee WeaponPosition) override
        {
            this->WeaponPosition=WeaponPosition;
        }
        float Aim(float angle) override;
    private:
        Coordonnee WeaponPosition;
}; 
#endif