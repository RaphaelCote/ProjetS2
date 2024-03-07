#include "enemyCharacter.h"
#include "projectile.h"
#include "canonball.h"
#include "rocket.h"
#include "grenade.h"
#include "utility.h"
using namespace std;

EnemyCharacter::~EnemyCharacter() {}

EnemyCharacter::EnemyCharacter(int posx, int posy, int width,int height, int image) : Character(posx, posy)
{
    WeaponPosition.x = posx;
    WeaponPosition.y = posy + hitbox.height / 2;
}

Projectile *EnemyCharacter::createEnemyProjectile()
{
    Projectile *p;

    p = new Canonball(this->getWeaponPosition());

    srand(time(0));
    float random_angledeg = (float)(90.0 + (rand() % (15))) / 100;
    srand(time(0) + 071234263);
    float random_puissance = (float)(90.0 + (rand() % (15))) / 100;
    cout << "random angleDeg : " << random_angledeg << endl;
    cout << "random puissance : " << random_puissance << endl;
    p->setAngleDegre(-45.0 * random_angledeg);
    p->setPuissance(0.5 * random_puissance);

    
    return p;
}

// Projectile EnemyCharacter::EnemyShoot(Projectile* projectile){
//     //on inverse l'angle et on fait le randomizer
// }
