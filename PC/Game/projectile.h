//projectile.h
#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <iostream>
#include <cmath>
#include <typeinfo>

#include "utility.h"
#include "character.h"
#include "canonball.h"
#include "grenade.h"
#include "rocket.h"

const double g=-1000;

#define PI 3.14159265358979323846

class Projectile{

        public:
                Projectile(){};
                Projectile(Character& character);
                Projectile(Coordonnee bulletStartPosition);
        
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
                Coordonnee getBulletEndPosition();
                virtual int getProjectileMaxSpeed() = 0;

                bool checkIfCharacterHit(Character& character); 
                virtual int damageReceived(Character& character)=0;
            
        protected:
                //time_t temps
                Coordonnee bulletStartPosition;//coordonnée de départ du projectile
                
                
                Coordonnee bulletEndPosition;//coordonnée de fin du projectile
                
                
                float puissance;
                float angledeg;
                float V0;
                float rad;
                
                int findBulletPositionX(int positionY);
                int findBulletPositionY(int positionX);
};

#endif