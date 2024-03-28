//grenade.h
#ifndef GRENADE_H
#define GRENADE_H
#include "projectile.h"
#include <iostream>
#define RayonCercleExplosion 175
#define MaxDamage 120
#define HauteurEau 100
const float TempsGrenade =2.5;
class Grenade : public Projectile{
    private: 
        
        int grenadeMaxSpeed=2828;
       
    public:
        Grenade(Character& character):Projectile(character) {}
        Grenade(Coordonnee positionInitialeTir):Projectile( positionInitialeTir){}
        int damageReceived(Character& character) override; 
        bool zoneGrenade(int h,int k,int x,int y);
        int pythagore(int xi, int xf, int yi, int yf);
        int getProjectileMaxSpeed() override;
};
#endif
