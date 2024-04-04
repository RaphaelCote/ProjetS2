// projectile.h
#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <iostream>
#include <cmath>
#include <typeinfo>
#include "utility.h"
#include "../vecteur.h"
#include "character.h"
#define DirectionDroite 1
#define DirectionGauche -1
#define longeurMap 3000
const float g = -1000;

const double PI = 3.1415926;
const float dampingProjectile = 0.5;
const int HitboxCharacter =1;
const int HitboxBoat =2;
const int HAUTEUR_EAU = 100;
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
    void checkVecteurAllCharacters( Vecteur<Vecteur<Character*> > allCharacters);//pt inutile
    virtual int damageReceived(Character* character) = 0;
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
    Vecteur<Character*> targetCharacters;// vecteur de personnages que le projectile vise (ex, si projectile joueur, characters = tous les ennemis)
    void bubbleSortInfoHitbox(bool CharacterType);//if bool CharacterType==true, we sort the vector in ascending order, otherwise we sort the vector in descending order
    //-----------BOUNCE-----------//
    //void ScanHitboxes();
    
    bool BounceHorizontal(infoHitbox* hitbox);
    bool BounceVerticale(infoHitbox* hitbox);
    void CheckerBounce();

protected:
    // time_t temps;
    bool characterType;
    int direction;//1= va a droite dans le vecteur de targetCharacters, -1 = va a gauche dans le targetCharacter, 0 = continue de regarder ce character dans targetCharacters
    int ballDirection;//-1 = la balle va continuer sa trajectoire a gauche, 1= la balle continue sa trajectoire a droite 
    int currentCharacter;
    float puissance;
};

#endif