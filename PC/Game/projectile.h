//projectile.h
#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "utility.h"
#include "character.h"

#include <iostream>
#include <cmath>
#include <typeinfo>
const double g=-1000;

#define PI 3.14159265358979323846

class Projectile{

    public:
            Projectile(Character& character);
            Projectile(Coordonnee bulletStartPosition);
         
            
            Projectile(){};
            bool checkIfCharacterHit(Character& character); 
            virtual int damageReceived(Character& character)=0;
            virtual int getProjectileMaxSpeed() = 0;
            Coordonnee getBulletEndPosition();
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
            Coordonnee getbulletStartPosition(){
                    return bulletStartPosition;
            }
            void setbulletStartPosition(Coordonnee bulletStartPosition){
                    this->bulletStartPosition=bulletStartPosition;
            }
            bool getLaunch(){
                    return launch;
            }
            void setLaunch(bool launch){
                    this->launch=launch;
            }
            
    protected:
            //time_t temps
            Coordonnee bulletStartPosition;//coordonnée de départ du projectile
            
            
            Coordonnee bulletEndPosition;//coordonnée de fin du projectile
            int findBulletPositionX(int positionY);
            int findBulletPositionY(int positionX);
            
            float puissance;
            float angledeg;
            float V0;
            float rad;

            bool launch; // on le met a true dans playerShoot et on le remet directement a false dans didPlayerHit. on l'utilise dans le code plus tard
           
                
};
#include "canonball.h"
#include "grenade.h"
#include "rocket.h"
#endif