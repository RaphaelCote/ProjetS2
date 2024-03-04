#include "shield.h"
Shield::Shield(int shieldpoint)
{
    this->shieldPoint=shieldpoint;
}
Shield::Shield(){}
Shield::~Shield(){}
int Shield::getShieldPoint()
{
    return shieldLevel;
}
void Shield::setShieldPoint(int shieldpoint){
    this->shieldPoint=shieldpoint;
}