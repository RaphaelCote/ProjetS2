//playerCharacter.cpp
#include "playerCharacter.h"
#include "projectile.h"
#include "canonball.h"
#include "rocket.h"
#include "grenade.h"
using namespace std;


PlayerCharacter::PlayerCharacter(int posx,int posy):Character(posx, posy){
    WeaponPosition.x=posx+hitbox.width;
    WeaponPosition.y=posy+hitbox.height/2;
};


PlayerCharacter::~PlayerCharacter(){}


 
void PlayerCharacter::playerShoot(Projectile* projectile) {
    
    //cette fonction prépare un projectile (pointeur) qui est passer en paramètre, pour l'instant le damage 
    // projectile->positionInitiale.x=WeaponPosition.x;
    // projectile->positionInitiale.y=WeaponPosition.y;
    //projectile->launch = true;
    
    projectile->setbulletStartPosition(WeaponPosition);
    projectile->setLaunch(true);
    
}
float PlayerCharacter:: Aim(float angledeg){
    //éventuellement, ce sera la méthode qui calculera l'angle a partir de l'accéléromètre, et qui le retournera en rad
    //présentement, nous allons simplement prendre pour aquis qu'on reçoit un angle en deg et on le convertie en rad
    float rad=angledeg*PI/180;
    return rad;

}




