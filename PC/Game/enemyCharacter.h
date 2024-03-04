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

        Coordonnee getPosition();
        Coordonnee getWeaponPosition() override;
        //Projectile EnemyShoot(Projectile* projectile);
        void setWeaponPosition(Coordonnee weaponPosition) override;
        Projectile* createEnemyProjectile();
    private:
        Coordonnee WeaponPosition;
};

#endif