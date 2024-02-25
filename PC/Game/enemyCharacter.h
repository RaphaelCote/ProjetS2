//enemyCharacter.h
#ifndef ENEMYCHARACTER_H
#define ENEMYCHARACTER_H
#include "character.h"
#include "projectile.h"
#include <iostream> 
//faire un randomize pour savoir s'il hit ou pas 
class EnemyCharacter : public Character
{
    public:
        EnemyCharacter(int posx,int posy);
        ~EnemyCharacter();
        void enemyShoot(Projectile* projectile);
        //void playerShoot(Projectile* projectile);

        Coordonnee getPosition(){
            return position;
        }
         
        Coordonnee getWeaponPosition() override{
            return WeaponPosition;
        }
        void setWeaponPosition(Coordonnee WeaponPosition) override
        {
            this->WeaponPosition=WeaponPosition;
        }
    private:
        Coordonnee WeaponPosition;
};

#endif