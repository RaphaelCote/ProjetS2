//projectile.h
#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <iostream>
#include <cmath>
#include <typeinfo>

#include "utility.h"
#include "character.h"

const int HAUTEUR_EAU = 100;

const float g=-1000;

const double  PI = 3.14159265358979323846;

class Projectile {

    public:
        Projectile(Character& character);
        Projectile(Coordonnee bulletStartPosition);

        float getPuissance();
        void setPuissance(float puissance);
        float getAngleDegre();
        void setAngleDegre(float angledeg);
        Coordonnee getbulletStartPosition();
        void setbulletStartPosition(Coordonnee bulletStartPosition);
        Coordonnee getBulletEndPosition();
        virtual int getProjectileMaxSpeed() = 0;
        bool checkIfCharacterHit(Character& character); 
        virtual int damageReceived(Character& character)=0;
        
    protected:
        //time_t temps;
        Coordonnee bulletStartPosition;//coordonnée de départ du projectile
        Coordonnee bulletEndPosition;//coordonnée de fin du projectile
        
        float puissance;
        float angledeg;
        float V0;
        float rad;
        
        int findBulletPositionX(int positionY);
        int findBulletPositionY(int positionX);
        int findBulletPositionYTime(float time);
};

#endif