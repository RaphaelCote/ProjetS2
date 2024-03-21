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
        EnemyCharacter(Coordonnee position, Hitbox hitbox, int image);
        ~EnemyCharacter();
        Coordonnee getPosition();
        Coordonnee getWeaponPosition() override;
        void setWeaponPosition(Coordonnee weaponPosition) override;
        Projectile* createEnemyProjectile();
    private:
        Coordonnee WeaponPosition;
};

#endif