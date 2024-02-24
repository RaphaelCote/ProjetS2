//canonball.h
#ifndef CANONBALL_H
#define CANONBALL_H
#include "projectile.h"
#include <iostream>
class Canonball: public Projectile{
    private:
        int damage=10; //le dégat le + petit que il peux faire (si hit les pieds par exemple)
        //Velocity projectileSpeed;
        int canonballMaxSpeed=2828;
    public:
        Canonball(Character& character):Projectile(character) {}
        int getDamage() override
        {
            return damage;
        }

        int getProjectileMaxSpeed() override
        {
           return canonballMaxSpeed;
        }
    
};
#endif