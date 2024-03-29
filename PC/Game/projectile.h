// projectile.h
#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <iostream>
#include <cmath>
#include <typeinfo>
#include "utility.h"
#include "../vecteur.h"
#include "character.h"

const float g = -1000;

const double PI = 3.1415926;
const float dampingProjectile = 0.8;
//class Niveau;

class Projectile
{

public:
    Projectile(Character &character);
    Projectile(Coordonnee bulletStartPosition);
    Projectile(Coordonnee bulletStartPosition, Hitbox hitboxset);
    ~Projectile();
    float getPuissance();
    void setPuissance(float puissance);
    float getAngleDegre();
    void setAngleDegre(float angledeg);
    Coordonnee getbulletStartPosition();
    void setbulletStartPosition(Coordonnee bulletStartPosition);
    Coordonnee getBulletEndPosition();
    virtual int getProjectileMaxSpeed() = 0;
    bool checkIfCharacterHit(Character* character);
    void checkVecteurCharacters(Vecteur<Character*> character);
    virtual int damageReceived(Character &character) = 0;
    Hitbox hitbox;

    Coordonnee bulletCurrentPosition;
    Coordonnee bulletStartPosition; // coordonnée de départ du projectile
    Coordonnee bulletEndPosition;   // coordonnée de fin du projectile

    int findBulletPositionX(int positionY);
    int findBulletPositionY(int positionX);
    int findBulletPositionYTime(float time);
    float findPositiveAngleBulletPositionY(int positionY);//la courbe verte
    float findNegativeAngleBulletPositionY(int positionY);//pour les rebond vertical courbe bleu
    int findHalfTrajectoryBulletPosition();
    float angledeg;
    float rad;
    float V0;
    float Vf;
    void AjouterInfoHitbox (infoHitbox infohitbox);
    Vecteur<infoHitbox*> vecteurInfohitbox;
    void bubbleSortInfoHitbox(bool CharacterType);//if bool CharacterType==true, we sort the vector in ascending order, otherwise we sort the vector in descending order
    //-----------BOUNCE-----------//
    //void ScanHitboxes();
    
    void BounceHorizontal();
    void BounceVerticale();
    void CheckerBounce();

protected:
    // time_t temps;
    bool characterType;
    float puissance;
};

#endif