#include "enemyCharacter.h"
#include "projectile.h"
#include "canonball.h"
#include "rocket.h"
#include "grenade.h"
#include "utility.h"
using namespace std;

EnemyCharacter:: EnemyCharacter(int posx,int posy): Character(posx,posy)
{
    WeaponPosition.x=posx;
    WeaponPosition.y=posy+hitbox.height/2;
}

Projectile* EnemyCharacter::createEnemyProjectile()
{
	random_device r;
	default_random_engine generator(r());
	uniform_int_distribution<int> coor(70, 130);// marquer en int les bornes et diviser par après /100
    Projectile* p;

    p= new Canonball(this->getWeaponPosition());

    float random_angledeg=(float)(coor(generator))/100.0;
    float random_puissance=(float)(coor(generator))/100.0;
    p->setAngleDegre(-45.0*random_angledeg);
    p->setPuissance(0.5*random_puissance);
    return p;
    
}
EnemyCharacter::~EnemyCharacter(){}


// Projectile EnemyCharacter::EnemyShoot(Projectile* projectile){
//     //on inverse l'angle et on fait le randomizer 
// }


