//enemyCharacter.h
#ifndef ENEMYCHARACTER_H
#define ENEMYCHARACTER_H
#include "character.h"
#include "projectile.h"

#include <iostream> 
#include <cmath>
//faire un randomize pour savoir s'il hit ou pas 
class EnemyCharacter : public Character
{
    public:
        EnemyCharacter(Coordonnee position, Hitbox hitbox, std::string image);
        ~EnemyCharacter();
        Coordonnee getPosition();
        Coordonnee getWeaponPosition() override;
        void setWeaponPosition(Coordonnee weaponPosition) override;
        Projectile* createEnemyProjectile(bool isControllerControls, int randomSeed);
        float findV0withAngle(float angledeg, Character* character);
private:
    private:
        Coordonnee WeaponPosition;
};

#endif