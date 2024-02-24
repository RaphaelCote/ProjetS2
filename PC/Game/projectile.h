//projectile.h
#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "utility.h"
#include "character.h"
// #include "canonball.h"
// #include "grenade.h"
// #include "rocket.h"
#include <iostream>
#include <cmath>
#include <typeinfo>
const double g=-1000;
#define VITESSEMAX 2000
#define PI 3.14159265358979323846
// enum class ProjectileType {
//     CANNONBALL,
//     GRENADE,
//     ROCKET
// };
class Projectile{

//isPlayerHit
    public:
            Projectile(Character& character);
         
            virtual int getDamage() = 0;
            
            bool checkIfCharacterHit(Character& character); 
            //float damageReceived(Projectile& projectile, int impactX, int impactY);// a changer pour int le type de retour
            float damageReceived(Projectile& projectile, Character& character);
            float damageMultiplier(int impactY);// en fonction de la hauteur ou on touche l'ennemie
            virtual int getProjectileMaxSpeed() = 0;
            Coordonnee getBulletEndPosition();
            // void setLastShooter(Character& character);
            // Character& getLastShooter() const;
            //get/set des variables publiques
            float getPuissance(){
                    return puissance;
            }
            void setPuissance(float puissance){
                    this->puissance=puissance;
            }
            float getAngleDegre(){
                    return angledeg;
            }
            void setAngleDegre(float angledeg){
                    this->angledeg=angledeg;
            }
            Coordonnee getPositionInitiale(){
                    return positionInitiale;
            }
            void setPositionInitiale(Coordonnee PositionInitiale){
                    this->positionInitiale=PositionInitiale;
            }
            bool getLaunch(){
                    return launch;
            }
            void setLaunch(bool launch){
                    this->launch=launch;
            }
            
    protected:
            //time_t temps
            // Character& lastShooter;
            
            //Coordonnee position;
            Coordonnee positionInitiale;//coordonnée de départ du projectile
            
            Coordonnee bulletEndPosition;//coordonnée de fin du projectile

            int damage;
            int findBulletPositionX(int positionY);
            int findBulletPositionY(int positionX);
            
            float puissance;
            float angledeg;
            float V0;
            float rad;

            bool launch; // on le met a true dans playerShoot et on le remet directement a false dans didPlayerHit. on l'utilise dans le code plus tard
            //Velocity vitesse; //LA VELOCITY EST LA PUISSANCE ET L'ANGLE
                
};
#include "canonball.h"
#include "grenade.h"
#include "rocket.h"
#endif