//grenade.h
#ifndef GRENADE_H
#define GRENADE_H
#include "projectile.h"
#include <iostream>

class Grenade : public Projectile{
    private: 
        
        int grenadeMaxSpeed=2828;
       
    public:
        Grenade(Character& character):Projectile(character) {}
        Grenade(Coordonnee positionInitialeTir):Projectile( positionInitialeTir){}
        int damageReceived(Character& character) override; 
        int getProjectileMaxSpeed() override;
};
#endif
