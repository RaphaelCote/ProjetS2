//character.cpp
#include "character.h"
Character::Character(int posx,int posy){
    this->position.x=posx;
    this->position.y=posy;
    this->healthPoint=100;
    
    this->hitbox.height=100;//px
    this->hitbox.width=100;//px
    //std::cout<< "creation d'un Character"<<std::endl;
}
Character::~Character(){
    //std::cout<< "destruction d'un Character"<<std::endl;
}
 
int Character::getHealthPoint(){
 return healthPoint;
}
// void Character::setProjectileType(ProjectileType projectile){
//     this->projectile=projectile;
// }
void Character::setHealthPoint(int healthPoint){
    this->healthPoint=healthPoint;
}
int Character::getHitboxWidth(){
    return hitbox.width;
}
int Character::getHitboxHeight(){
    return hitbox.height;
}
ProjectileType Character::getProjectileType(){
    return projectile;
}
void Character::setProjectileType(ProjectileType projectile){
    this->projectile=projectile;
}
float Character:: Aim(float angledeg){
    //éventuellement, ce sera la méthode qui calculera l'angle a partir de l'accéléromètre, et qui le retournera en rad
    //présentement, nous allons simplement prendre pour aquis qu'on reçoit un angle en deg et on le convertie en rad
    float rad=angledeg*3.14/180;
    return rad;

}
Coordonnee Character::getPosition(){
    return position;
}
