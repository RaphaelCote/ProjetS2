//playerCharacter.cpp
#include "playerCharacter.h"
#include "projectile.h"
#include "canonball.h"
#include "rocket.h"
#include "grenade.h"
using namespace std;


PlayerCharacter::PlayerCharacter(int posx,int posy, int width,int height, int image):Character(posx, posy){
    WeaponPosition.x=posx+hitbox.width;
    WeaponPosition.y=posy+hitbox.height/2;
};


PlayerCharacter::~PlayerCharacter(){}

 

float PlayerCharacter:: Aim(float angledeg){
    //éventuellement, ce sera la méthode qui calculera l'angle a partir de l'accéléromètre, et qui le retournera en rad
    //présentement, nous allons simplement prendre pour aquis qu'on reçoit un angle en deg et on le convertie en rad
    float rad=angledeg*PI/180;
    return rad;

}




