#ifndef CANONBALL_H
#define CANONBALL_H

#include "projectile.h"
#include <iostream>

class Canonball : public Projectile{
    private:
        int canonballMaxSpeed=2828;

    public:
        Canonball(Character& character):Projectile(character) {}
        Canonball(Coordonnee positionInitialeTir):Projectile( positionInitialeTir){}
        int getProjectileMaxSpeed() override;
        int damageReceived(Character& character) override;
};

#endif