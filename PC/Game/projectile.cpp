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
    //SI l'angle est négatif, faire un autre code, sinon prendre lui qu'on a live
    //cout<<"positionX1: "<<positionX1<<endl;
    //cout<<"positionX2: "<<positionX2<<endl;
    if(angledeg>0)
    {
        if(positionX1>=0 &&positionX1>positionX2)
        {
            positionX= round(positionX1);
        }
        if(positionX2>=0 &&positionX2>positionX1)
        {
            positionX=round(positionX2);
        }
    }
    if(angledeg<0)
    {

        if( positionX1<positionX2 )
        {
            positionX= round(positionX1);
        }
        if(positionX2<positionX1)
        {
            positionX=round(positionX2);
        }
    }
    
    return positionX;
}

bool Projectile::checkIfCharacterHit(Character& character)
{

    //vérifier si c'est un friendly ou un ennemie
    Coordonnee characterPosition =character.getPosition();
    if(angledeg>0)
    {
        if(findBulletPositionX(characterPosition.y)<characterPosition.x && findBulletPositionY(characterPosition.x) < characterPosition.y){
        //on sait qu'il n'a pas toucher directement l'ennemie
        //pour les coordonnées de la balle, ce sera a changé éventuellement (vérifier si cela a touché bateau ou l'eau)
            //cout<<"Premier if angle positif"<<endl;
            bulletEndPosition.x=findBulletPositionX(characterPosition.y);
            bulletEndPosition.y=characterPosition.y;
            return false;
        }
        else if(findBulletPositionY(characterPosition.x)<=(characterPosition.y+character.getHitboxHeight()))    
        {
            //on sait qu'il a toucher a la position du projectile en Y
            //cout<<"Premier else if angle positif"<<endl;
            bulletEndPosition.x=characterPosition.x;
            bulletEndPosition.y=findBulletPositionY(characterPosition.x);
            damageReceived(character);
            return true;
        }
        else if(findBulletPositionY(characterPosition.x+character.getHitboxWidth())>(characterPosition.y+character.getHitboxHeight()))
        {   //on sait qu'il ne touchera pas l'ennemie directement (passer par dessus l'ennemie)
            //pour les coordonnées de la balle, ce sera a changé éventuellement (vérifier si cela a touché bateau ou l'eau)
            //cout<<"Deuxième else if angle positif"<<endl;
            bulletEndPosition.x=findBulletPositionX(characterPosition.y);
            bulletEndPosition.y=characterPosition.y;
            return false;
        }
        else if(findBulletPositionY(characterPosition.x+character.getHitboxWidth())==(characterPosition.y+character.getHitboxHeight()))
        {
            //on sait qu'il a touché l'ennemie sur le coin supérieur droit
            //cout<<"Troisième else if angle positif"<<endl;
            bulletEndPosition.x=characterPosition.x+character.getHitboxWidth();
            bulletEndPosition.y=findBulletPositionY(characterPosition.x+character.getHitboxWidth());
            damageReceived(character);
            return true;
        }
        else if(findBulletPositionY(characterPosition.x+character.getHitboxWidth())<=(characterPosition.y+character.getHitboxHeight()))
        {
            //on sait qu'il a touché l'ennemie entre son coin supérieur gauche et supérieur droit excluant 
            //cout<<"Quatrième else if angle positif"<<endl;
            bulletEndPosition.x=findBulletPositionX(characterPosition.y+character.getHitboxHeight());
            bulletEndPosition.y=characterPosition.y+character.getHitboxHeight(); 
            damageReceived(character);
            return true;
        }
        else{
            //cout<<"Else angle positif"<<endl;
            //THÉORIQUEMENT rien passe dans le false, mais je le garde pour le déboguage 
            
            bulletEndPosition.x=findBulletPositionX(characterPosition.y);
            bulletEndPosition.y=characterPosition.y;
            return false;
        }
    }
    if(angledeg<0)
    {
       if(findBulletPositionX(characterPosition.y)>characterPosition.x + character.getHitboxWidth() && findBulletPositionY(characterPosition.x+character.getHitboxWidth()) < characterPosition.y){
        //on sait qu'il n'a pas toucher directement l'ennemie
        //pour les coordonnées de la balle, ce sera a changé éventuellement (vérifier si cela a touché bateau ou l'eau)
            //cout<<"Premier if angle négatif"<<endl;
            bulletEndPosition.x=findBulletPositionX(characterPosition.y);
            bulletEndPosition.y=characterPosition.y;
            return false;
        }
        else if(findBulletPositionY(characterPosition.x+character.getHitboxWidth())<=(characterPosition.y+character.getHitboxHeight()))    
        {
            //on sait qu'il a toucher a la position du projectile en Y
            //cout<<"Premier else if angle négatif"<<endl;
            bulletEndPosition.x=characterPosition.x+character.getHitboxWidth() ;
            bulletEndPosition.y=findBulletPositionY(characterPosition.x + character.getHitboxWidth());
            damageReceived(character);
            return true;
        }
        else if(findBulletPositionY(characterPosition.x)>(characterPosition.y+character.getHitboxHeight()))
        {   //on sait qu'il ne touchera pas l'ennemie directement (passer par dessus l'ennemie)
            //pour les coordonnées de la balle, ce sera a changé éventuellement (vérifier si cela a touché bateau ou l'eau)
            //cout<<"Deuxième else if angle négatif"<<endl;
            bulletEndPosition.x=findBulletPositionX(characterPosition.y);
            bulletEndPosition.y=characterPosition.y;
            return false;
        }
        else if(findBulletPositionY(characterPosition.x)==(characterPosition.y+character.getHitboxHeight()))
        {
            //on sait qu'il a touché l'ennemie sur le coin supérieur droit
            //cout<<"Troisième else if angle négatif"<<endl;
            bulletEndPosition.x=characterPosition.x;
            bulletEndPosition.y=findBulletPositionY(characterPosition.x);
            damageReceived(character);
            return true;
        }
        else if(findBulletPositionY(characterPosition.x)<=(characterPosition.y+character.getHitboxHeight()))
        {
            //on sait qu'il a touché l'ennemie entre son coin supérieur gauche et supérieur droit excluant 
            //cout<<"Quatrième else if angle négatif"<<endl;
            bulletEndPosition.x=findBulletPositionX(characterPosition.y+character.getHitboxHeight());
            bulletEndPosition.y=characterPosition.y+character.getHitboxHeight(); 
            damageReceived(character);
            return true;
        }
        else{
            cout<<"Else angle négatif"<<endl;
            //THÉORIQUEMENT rien passe dans le false, mais je le garde pour le déboguage 
            
            bulletEndPosition.x=findBulletPositionX(characterPosition.y);
            bulletEndPosition.y=characterPosition.y;
            return false;
        }
    }
    
}

Coordonnee Projectile::getBulletEndPosition()
{
    return bulletEndPosition;
}
