//rocket.h
#ifndef ROCKET_H
#define ROCKET_H
#include "projectile.h"
#include <iostream>
class Rocket: public Projectile{
    private:
        
        int rocketMaxSpeed=3000;
    public:
        Rocket(Character& character):Projectile(character) {}
        Rocket(Coordonnee positionInitialeTir):Projectile( positionInitialeTir){}
        Rocket(Coordonnee positionInitialeTir, Hitbox hitbox):Projectile(positionInitialeTir, hitbox){}
        int damageReceived(Character& character) override;
        int getProjectileMaxSpeed();
};
#endif