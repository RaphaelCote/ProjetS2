//character.h
#ifndef CHARACTER_H
#define CHARACTER_H
#include "utility.h"
//#include "projectile.h"
#include <iostream>

enum class ProjectileType {
    CANNONBALL,
    GRENADE,
    ROCKET
};
class Character{
    public:
        Character(int posx,int posy);
        ~Character();
        // ProjectileType getProjectileType();
        //void setProjectileType(ProjectileType projectile);
        int getHealthPoint();
        void setHealthPoint(int healthPoint);
        Coordonnee getPosition();
        int getHitboxWidth();
        int getHitboxHeight();
        virtual float Aim(float angle);
        ProjectileType getProjectileType();
        void setProjectileType(ProjectileType projectile);
        virtual Coordonnee getWeaponPosition()=0;
        virtual void setWeaponPosition(Coordonnee WeaponPosition)=0;
        //bool didPlayerHit(float puissance,float angle, EnemyCharacter& enemy)
    protected:
        int healthPoint;
        Coordonnee position;   
        Coordonnee WeaponPosition;
        ProjectileType projectile;
        Hitbox hitbox;
        //ProjectileType projectile;
        //Porjectile ammo; //compositon de projectile quand elle va être créer
        

    
};
// #include "projectile.h"
// #include "canonball.h"
// #include "rocket.h"
// #include "grenade.h"


#endif