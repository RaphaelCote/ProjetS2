//playerCharacter.cpp
#include "playerCharacter.h"
using namespace std;


PlayerCharacter::PlayerCharacter(int posx,int posy):Character(posx, posy){
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
Coordonnee PlayerCharacter::getWeaponPosition()
{
    return WeaponPosition;
}
void PlayerCharacter::setWeaponPosition(Coordonnee WeaponPosition)
{
    this->WeaponPosition=WeaponPosition;
}




