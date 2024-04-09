#include "enemyCharacter.h"
#include "projectile.h"
#include "canonball.h"
#include "rocket.h"
#include "grenade.h"
#include "utility.h"
#include <cstdlib>
EnemyCharacter::~EnemyCharacter() {}

EnemyCharacter::EnemyCharacter(Coordonnee position, Hitbox hitboxsset, std::string image) : Character(position, hitboxsset, image)
{
    WeaponPosition.x = position.x;
    WeaponPosition.y = position.y + hitbox.height / 2;
}

Projectile *EnemyCharacter::createEnemyProjectile()
{
    Projectile *p;

    p = new Canonball(this->getWeaponPosition());

    std::srand(std::time(0));
    float random_angledeg = (float)(90.0 + (std::rand() % (15))) / 100;
    std::srand(std::time(0) + 071234263);
    float random_puissance = (float)(90.0 + (std::rand() % (15))) / 100;
    // cout << "random angleDeg : " << random_angledeg << endl;
    // cout << "random puissance : " << random_puissance << endl;
    p->setAngleDegre(-45.0 * random_angledeg);
    p->setPuissance(0.5 * random_puissance);

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
