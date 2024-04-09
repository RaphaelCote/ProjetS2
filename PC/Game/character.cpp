#include "character.h"

Character::Character(int posX, int posY)
{
    this->position.x = posX;
    this->position.y = posY;
    this->healthPoint = 100;

    Hitbox hitbox;
    hitbox.height = 100;
    hitbox.width = 100;

    this->hitbox = hitbox;
    this->imagecharacter = 1;
}

Character::Character(Coordonnee positionset, Hitbox hitboxset, std::string image)
{
    this->position = positionset;
    this->healthPoint = 100;

    this->hitbox = hitboxset;
    this->imagecharacter = image;
}

Character::~Character() {}

int Character::getHealthPoint()
{
    return healthPoint;
}

void Character::setHealthPoint(int healthPoint)
{
    this->healthPoint = healthPoint;
}

int Character::getHitboxWidth()
{
    return hitbox.width;
}

int Character::getHitboxHeight()
{
    return hitbox.height;
}

Coordonnee *Character::PointeurPosition()
{
    Coordonnee *Positionptr = nullptr;
    Positionptr = &position;
    return Positionptr;
}

float Character::Aim(float angledeg)
{
    // éventuellement, ce sera la méthode qui calculera l'angle a partir de l'accéléromètre, et qui le retournera en rad
    // présentement, nous allons simplement prendre pour aquis qu'on reçoit un angle en deg et on le convertie en rad
    float rad = angledeg * 3.14 / 180;
    return rad;
}

void Character::ShowInfo()
{
    // cout << "Position : x : " << getPosition().x << " y : " << getPosition().y << " | Vie : " << getHealthPoint() << endl;
}

Coordonnee Character::getPosition()
{
    return position;
}
std::string Character::getimage()
{
    return imagecharacter;
}

void Character::setPosition(Coordonnee coor)
{
    position.x = coor.x;
    position.y = coor.y;
}

// void Character::applyShield(Shield& shield){
//     //présentement elle est vide, mais il faudrait vérifier quel shield
//     //a été achetée dans le shop et attribué des points de vie supplémentaire au joueur
//     //pt a coder directement dans playerCharacter
// }