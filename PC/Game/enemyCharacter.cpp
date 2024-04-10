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
float EnemyCharacter::findV0withAngle(float angledeg, Character* character)
{
    float deltay = ((character->getPosition().y + 0.5 * character->getHitboxHeight()) - (position.y + 0.5 * hitbox.height));
    float deltax = ((character->getPosition().x + character->getHitboxWidth()) - (position.x));
    //peut-�tre qu'il faut changer 
    float num = g * deltax * deltax;
    float denum = (2 * deltay * std::pow(std::cos(angledeg * PI / 180), 2)) - (2 * deltax * std::tan(angledeg * PI / 180) * std::pow(std::cos(angledeg * PI / 180), 2));
    float res = std::sqrt(num / denum);
    std::cout << "le r�sultat est celui-ci: " << std::endl;
    return res;
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
