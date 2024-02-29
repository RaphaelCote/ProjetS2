//projectile.cpp
#include "projectile.h"
using namespace std;

Projectile::Projectile(Character& character)
{
    
    angledeg = 0;
    puissance = 0;
    this->bulletStartPosition=character.getWeaponPosition();
    
}

Projectile::Projectile(Coordonnee bulletStartPosition)
{
    angledeg = 0;
    puissance = 0;
    this->bulletStartPosition=bulletStartPosition;

}

int Projectile::findBulletPositionY(int positionX)
{
    V0=puissance*getProjectileMaxSpeed();
    
    rad=angledeg*PI/180;
    
    float deltax= (positionX - (bulletStartPosition.x));
    double positionY = ((g * deltax * deltax) / (2 * V0 * V0 * pow(cos(rad), 2)) + deltax * tan(rad)) + bulletStartPosition.y;
   
    return round(positionY);
}

int Projectile::findBulletPositionX(int positionY)
{
    V0=puissance*getProjectileMaxSpeed();
    int positionX=0;
    
    rad=angledeg*PI/180;
    //cout<<"conversion de deg a rad= "<< rad<<endl;
    //float rad=angledeg;
    float deltay=( positionY-bulletStartPosition.y);
    float numeratorx1 = -tan(rad) + sqrt(pow(tan(rad), 2) - ((2 * g) / (pow(V0, 2) * pow(cos(rad), 2))) * -1*deltay);
    float numeratorx2 = -tan(rad) - sqrt(pow(tan(rad), 2) - ((2 * g) / (pow(V0, 2) * pow(cos(rad), 2))) * -1*deltay);
    float denominator = g / (pow(V0, 2) * pow(cos(rad), 2));

    float positionX1=(numeratorx1/denominator)+bulletStartPosition.x;
    float positionX2=(numeratorx2/denominator)+bulletStartPosition.x;
    //cout<<"positionX1: "<<positionX1<<endl;
    //cout<<"positionX2: "<<positionX2<<endl;
    if(positionX1>=0 &&positionX1>positionX2)
    {
        positionX= round(positionX1);
    }
    if(positionX2>=0 && positionX2>positionX1)
    {
        positionX=round(positionX2);
    }
    return positionX;
}

bool Projectile::checkIfCharacterHit(Character& character)
{
    
    Coordonnee characterPosition =character.getPosition();
    
    if( findBulletPositionX(characterPosition.y)<characterPosition.x && findBulletPositionY(characterPosition.x)<100){
        //on sait qu'il n'a pas toucher directement l'ennemie
        //pour les coordonnées de la balle, ce sera a changé éventuellement (vérifier si cela a touché bateau ou l'eau)
        //cout<<"Premier if"<<endl;
        bulletEndPosition.x=findBulletPositionX(100);
        bulletEndPosition.y=100;
        return false;
    }
    else if(findBulletPositionY(characterPosition.x)<=(characterPosition.y+character.getHitboxHeight()))    
    {
        //on sait qu'il a toucher a la position du projectile en Y
        //cout<<"Premier else if"<<endl;
        bulletEndPosition.x=characterPosition.x;
        bulletEndPosition.y=findBulletPositionY(characterPosition.x);
        damageReceived(character);
        return true;
    }
    else if(findBulletPositionY(characterPosition.x+character.getHitboxWidth())>(characterPosition.y+character.getHitboxHeight()))
    {   //on sait qu'il ne touchera pas l'ennemie directement (passer par dessus l'ennemie)
        //pour les coordonnées de la balle, ce sera a changé éventuellement (vérifier si cela a touché bateau ou l'eau)
        //cout<<"Deuxième else if"<<endl;
        bulletEndPosition.x=findBulletPositionX(100);
        bulletEndPosition.y=100;
        return false;
    }
    else if(findBulletPositionY(characterPosition.x+character.getHitboxWidth())==(characterPosition.y+character.getHitboxHeight()))
    {
        //on sait qu'il a touché l'ennemie sur le coin supérieur droit
        //cout<<"Troisième else if"<<endl;
        bulletEndPosition.x=characterPosition.x+character.getHitboxWidth();
        bulletEndPosition.y=findBulletPositionY(characterPosition.x+character.getHitboxWidth());
        damageReceived(character);
        return true;
    }
    else if(findBulletPositionY(characterPosition.x+character.getHitboxWidth())<(characterPosition.y+character.getHitboxHeight()))
    {
        //on sait qu'il a touché l'ennemie entre son coin supérieur gauche et supérieur droit excluant 
        //cout<<"Quatrième else if"<<endl;
        bulletEndPosition.x=findBulletPositionX(characterPosition.y+character.getHitboxHeight());
        bulletEndPosition.y=characterPosition.y+character.getHitboxHeight(); 
        damageReceived(character);
        return true;
    }
    else{
        //cout<<"Else"<<endl;
        //THÉORIQUEMENT rien passe dans le false, mais je le garde pour le déboguage 
        
        bulletEndPosition.x=findBulletPositionX(100);
        bulletEndPosition.y=100;
        return false;
    }
}

Coordonnee Projectile::getBulletEndPosition()
{
    return bulletEndPosition;
}
