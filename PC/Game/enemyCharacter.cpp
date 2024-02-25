#include "enemyCharacter.h"
#include "projectile.h"
#include "canonball.h"
#include "rocket.h"
#include "grenade.h"

EnemyCharacter:: EnemyCharacter(int posx,int posy): Character(posx,posy){
   
    WeaponPosition.x=posx;
     WeaponPosition.y=posy+hitbox.height/2;
}

EnemyCharacter::~EnemyCharacter(){}


void EnemyCharacter::enemyShoot(Projectile* projectile) {
    //cette fonction prépare un projectile (pointeur) qui est passer en paramètre, pour l'instant le damage 
           
    // projectile->positionInitiale.x=WeaponPosition.x;
    // projectile->positionInitiale.y=WeaponPosition.y;
    
    //int random_number = 25 + (rand() % (63 - 25 + 1));

    projectile->setbulletStartPosition(WeaponPosition);
    projectile->setLaunch(true);

}
