//playerCharacter.cpp
#include "playerCharacter.h"
#include "projectile.h"
#include "canonball.h"
#include "rocket.h"
#include "grenade.h"
using namespace std;
// Projectile* createProjectile(ProjectileType type) {
//     switch (type) {
//         case ProjectileType::CANNONBALL:
//             return new Canonball();
//         case ProjectileType::GRENADE:
//             return new Grenade();
//         case ProjectileType::ROCKET:
//             return new Rocket();
//         default:
//             return nullptr;  // Gérer le cas par défaut selon vos besoins
//     }
// }


PlayerCharacter::PlayerCharacter(int posx,int posy):Character(posx, posy){
        //std::cout<< "creation d'un player"<<std::endl;
    WeaponPosition.x=posx+hitbox.width;
    WeaponPosition.y=posy+hitbox.height/2;
};


PlayerCharacter::~PlayerCharacter()
{
    //std::cout<< "destruction d'un player"<<std::endl;
}


 
void PlayerCharacter::playerShoot(Projectile* projectile) {
    //on y passe *projectile en paramètre d'entré seulement, le reste on le scrap, on fait juste mettre a true (launch) pis la position du gun
    //cette fonction prépare un projectile (pointeur) qui est passer en paramètre, pour l'instant le damage 
            //dire au projectile que sa position initiale est weaponPosition
    // projectile->positionInitiale.x=WeaponPosition.x;
    // projectile->positionInitiale.y=WeaponPosition.y;
    //projectile->launch = true;
    
   projectile->setPositionInitiale(WeaponPosition);
    //projectile->setPositionInitiale(getWeaponPosition());
    projectile->setLaunch(true);
    
}
float PlayerCharacter:: Aim(float angledeg){
    //éventuellement, ce sera la méthode qui calculera l'angle a partir de l'accéléromètre, et qui le retournera en rad
    //présentement, nous allons simplement prendre pour aquis qu'on reçoit un angle en deg et on le convertie en rad
    float rad=angledeg*PI/180;
    return rad;

}




