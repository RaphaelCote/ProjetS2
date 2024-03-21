//projectile.h
#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "utility.h"
#include "character.h"
#include "../Vecteur.h"
//c'est le "#include "../raftWars.h"" qui fait chier le pain

#include "../Scenes/game.h"
// #include "niveau.h"
#include <iostream>
#include <cmath>
#include <typeinfo>

// je define des hauteurs de bateau ici, mais il va falloir utiliser des méthode
//comme getBoatHitbox() pour les avoirs 
#define hauteurBateau 50
#define largeurBateau 300
const float g=-1000;

const double  PI = 3.14159;
const float masseProjectile = 0.05; // en kg
const float dampingProjectile = 0.8;
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
        //void checkIfCharacterHit(Vecteur<Character> character); 
        void checkIfCharacterHit(Character& character); 
        virtual int damageReceived(Character& character)=0;
        //-----------BOUNCE-----------//
        void ScanHitboxes();
        void BounceHorizontal();
        void BounceVerticale();
        void CheckerBounce();
        int findBulletPositionX(int positionY);
        int findBulletPositionYAngle(float angle);// pas utilisé présentement 
        float findNegativeAngleBulletPositionY(int positionY);//pour les rebond vertical courbe bleu
        float findPositiveAngleBulletPositionY(int positionY);//la courbe verte
        int findBulletPositionY(int positionX);
        int findBulletPositionYTime(float time);

        Coordonnee bulletCurrentPosition;
        
    protected:
        //time_t temps;
        Coordonnee bulletStartPosition;//coordonnée de départ du projectile
        Coordonnee bulletEndPosition;//coordonnée de fin du projectile
        Vecteur<Hitbox> allHitboxObject;
        //std::vector<std::vector<Hitbox>> allHitboxObject;
        float puissance;
        float angledeg;
        float V0;
        float Vf;
        float rad;
        
        
};

#endif