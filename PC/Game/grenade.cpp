#include "grenade.h"
using namespace std;
bool Grenade::zoneGrenade(int h,int k,int x,int y)
{
    if(pow((x-h),2) +pow((y-k),2) <=175*175)
    {
        return true;
    }
    else{
        return false;
    }
}
int Grenade::pythagore(int xi, int xf, int yi, int yf)
{
    int deltax=xf-xi;
    int deltay=yf-yi;
    int distance= round(sqrt( pow((deltax),2)+ pow((deltay),2) ));
    return distance;
}
int Grenade::damageReceived(Character& character){
    
    float dy=bulletEndPosition.y-character.getPosition().y;
    float Vf= sqrt( pow(V0*cos(rad),2) + pow(V0*sin(rad),2) +2*g*dy);
    int explosionDamage=0;
    //float damageMultiplierExplosion=exp(-0.03*x);// la variable x est la distance (entre 100 et 0, soit 100 le max), que tu es par rapport au centre de l'explosion
    

    //--------------------Gestion des dégats explosion----------------------//
    
    int positionFinaleGrenandeY=findBulletPositionYTime(TempsGrenade);
    int positionFinaleGrenadeX=findBulletPositionX(positionFinaleGrenandeY);
    //check up grenade pour si l'ennemie est touché
    
    int tableauDistance[7];
    //coin inférieur gauche
    tableauDistance[0]=pythagore(positionFinaleGrenadeX,character.getPosition().x,positionFinaleGrenandeY,character.getPosition().y); 
    //a gauche du personnage dans le milieu
    tableauDistance[1]=pythagore(positionFinaleGrenadeX, character.getPosition().x, positionFinaleGrenandeY, character.getPosition().y+character.getHitboxHeight()/2 );
    
    //coin supérieur gauche
    tableauDistance[2]=pythagore(positionFinaleGrenadeX, character.getPosition().x, positionFinaleGrenandeY, character.getPosition().y+character.getHitboxHeight());
    //Milieu supérieur 
    tableauDistance[3]=pythagore(positionFinaleGrenadeX,character.getPosition().x+character.getHitboxWidth()/2,positionFinaleGrenandeY, character.getPosition().y+character.getHitboxHeight());
    //coin supérieur droit
    tableauDistance[4]=pythagore(positionFinaleGrenadeX,character.getPosition().x+character.getHitboxWidth(),positionFinaleGrenandeY, character.getPosition().y+character.getHitboxHeight());
    //a droite du personnage dans le milieu
    tableauDistance[5]=pythagore(positionFinaleGrenadeX,character.getPosition().x+character.getHitboxWidth(),positionFinaleGrenandeY, character.getPosition().y+character.getHitboxHeight()/2);
    //coin inférieur droit
    tableauDistance[6]=pythagore(positionFinaleGrenadeX,character.getPosition().x+character.getHitboxWidth(),positionFinaleGrenandeY, character.getPosition().y);
    
    int distanceMin=tableauDistance[0];
    if(bulletEndPosition.x==character.getPosition().x ||bulletEndPosition.y==character.getPosition().y +character.getHitboxHeight())
    {
        explosionDamage=120;
    }
    else
    {
        for(int i=0;i<7;i++)
        {
            cout<<tableauDistance[i]<<endl;
            if(tableauDistance[i]<distanceMin)
            {
                distanceMin=tableauDistance[i];
            }
        }
        if(distanceMin<=RayonCercleExplosion)
        {
            //tu sais que t'es dans le cercle
            explosionDamage=round(exp(-0.015*distanceMin)*MaxDamage);

        }
    } 
    character.setHealthPoint(character.getHealthPoint()-explosionDamage);
    
    
   
    //--------------------Vérification de la vie (si en bas de 0 healthpoint)----------------------//

    if(character.getHealthPoint()<=0)
    {
        character.setHealthPoint(0);
    }
    cout << "La cible a actuellement " <<character.getHealthPoint() << " points de vie. Il a ete frappe a une vitesse de " << Vf << " pixels/s a la position:";
    return explosionDamage;
    
}
int Grenade::getProjectileMaxSpeed()
{
    return grenadeMaxSpeed;
}