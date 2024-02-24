#include "enemyCharacter.h"
#include "projectile.h"
#include "canonball.h"
#include "rocket.h"
#include "grenade.h"

EnemyCharacter:: EnemyCharacter(int posx,int posy): Character(posx,posy){
    //std::cout<< "creation d'un ennemi"<<std::endl;
    WeaponPosition.x=posx;
     WeaponPosition.y=posy+hitbox.height/2;
}
EnemyCharacter::~EnemyCharacter(){
     //std::cout<< "destruction d'un ennemi"<<std::endl;
}
Coordonnee EnemyCharacter::getPosition(){
    return position;
}
void EnemyCharacter::enemyShoot(Projectile* projectile) {
    //on y passe *projectile en paramètre d'entré seulement, le reste on le scrap, on fait juste mettre a true (launch) pis la position du gun
    //cette fonction prépare un projectile (pointeur) qui est passer en paramètre, pour l'instant le damage 
            //dire au projectile que sa position initiale est weaponPosition
    // projectile->positionInitiale.x=WeaponPosition.x;
    // projectile->positionInitiale.y=WeaponPosition.y;
    //projectile->launch = true;
    projectile->setPositionInitiale(WeaponPosition);
    projectile->setLaunch(true);

}
