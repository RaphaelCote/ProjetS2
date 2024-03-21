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
        EnemyCharacter(int posx,int posy, int width,int height, int image);
        EnemyCharacter(int posx,int posy);
        ~EnemyCharacter();
        Coordonnee getPosition();
        Coordonnee getWeaponPosition() override;
        void setWeaponPosition(Coordonnee weaponPosition) override;
        Projectile* createEnemyProjectile();
    private:
        Coordonnee WeaponPosition;
};

#endif