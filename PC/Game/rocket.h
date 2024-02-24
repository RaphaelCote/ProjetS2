//rocket.h
#ifndef ROCKET_H
#define ROCKET_H
#include "projectile.h"
#include <iostream>
class Rocket: public Projectile{
    private:
        int damage=20; //le dégat le + petit que il peux faire (si hit les pieds par exemple)
        //Velocity projectileSpeed;
        int rocketMaxSpeed=3000;
    public:
        Rocket(Character& character):Projectile(character) {}
        int getDamage() override{
            return damage;
        }
        int getProjectileMaxSpeed() override {
            return rocketMaxSpeed;
        }
};
#endif