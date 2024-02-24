//grenade.h
#ifndef GRENADE_H
#define GRENADE_H
#include "projectile.h"
#include <iostream>

class Grenade : public Projectile{
    private: 
        int damage=5; //pour l'instant j'ai mis 5, mais ça ne va pas seulement fonctionner comme ça
                    /*quand elle frape qqun, elle fait 5, et après en fonction de ou
                    elle est quand elle explose, il y a un facteur qui augmente en avec la proximité du                         joueur*/
        int grenadeMaxSpeed=2828;
       
    public:
        Grenade(Character& character):Projectile(character) {}
        int getDamage() override{
            return damage;
        }
        int getProjectileMaxSpeed() override{
            return grenadeMaxSpeed;
        }
};
#endif
