#include "enemyCharacter.h"
#include "projectile.h"
#include "canonball.h"
#include "rocket.h"
#include "grenade.h"
#include "utility.h"
using namespace std;

EnemyCharacter::~EnemyCharacter() {}

EnemyCharacter::EnemyCharacter(Coordonnee position, Hitbox hitboxsset, int image) : Character(position, hitboxsset, image)
{
    WeaponPosition.x = position.x;
    WeaponPosition.y = position.y + hitbox.height / 2;
}

Projectile *EnemyCharacter::createEnemyProjectile()
{
    Projectile *p;

    p = new Canonball(this->getWeaponPosition());

    srand(time(0));
    //float random_angledeg = (float)(97.0 + (rand() % (6))) / 100;
    srand(time(0) + 071234263);
    //float random_puissance = (float)(97.0 + (rand() % (6))) / 100;
    float random_angledeg=1;
    float random_puissance=1;
    cout << "random angleDeg : " << random_angledeg << endl;
    cout << "random puissance : " << random_puissance << endl;
    p->setAngleDegre(-45.0 * random_angledeg);
    p->setPuissance(0.5245 * random_puissance);

    return p;
}

Coordonnee EnemyCharacter::getPosition()
{
    return position;
}
Coordonnee EnemyCharacter::getWeaponPosition()
{
    return WeaponPosition;
}
void EnemyCharacter::setWeaponPosition(Coordonnee weaponPosition)
{
    this->WeaponPosition = weaponPosition;
}
