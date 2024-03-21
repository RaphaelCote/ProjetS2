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
    
    //---------------------bulletEndPosition en fonction du temps-----------//
    int positionFinaleGrenadeYTemps=findBulletPositionYTime(TempsGrenade);
    int positionFinaleGrenadeXTemps=findBulletPositionX(positionFinaleGrenadeYTemps);

    //---------------------bulletEndPositon en fonction d'un point x/y---------//
    
    if(findBulletPositionY(character.getPosition().x)<=(character.getPosition().y+character.getHitboxHeight()))
    {
        
        //on sait qu'il a toucher a la position du projectile en X
        cout<<"touche cote lateral"<<endl;
        bulletEndPosition.x=character.getPosition().x;
        bulletEndPosition.y=findBulletPositionY(character.getPosition().x);
        
       if(positionFinaleGrenadeXTemps>character.getPosition().x)
       {
            positionFinaleGrenadeXTemps=bulletEndPosition.x;
            positionFinaleGrenadeYTemps=bulletEndPosition.y;
       }
    }
    else if(findBulletPositionY(character.getPosition().x+character.getHitboxWidth())<=(character.getPosition().y+character.getHitboxHeight()))
    {
        //on sait qu'il a touché l'ennemie entre son coin supérieur gauche et supérieur droit excluant 
        cout<<"touche haut de la tete"<<endl;
        bulletEndPosition.x=findBulletPositionX(character.getPosition().y+character.getHitboxHeight());
        bulletEndPosition.y=character.getPosition().y+character.getHitboxHeight(); 
        if(positionFinaleGrenadeYTemps<character.getPosition().y+character.getHitboxHeight())
        {
            positionFinaleGrenadeXTemps=bulletEndPosition.x;
            positionFinaleGrenadeYTemps=bulletEndPosition.y;
        }
    }
    
    
    //check up grenade pour si l'ennemie est touché
    cout<<"distance finale x: "<<positionFinaleGrenadeXTemps<<endl;
    int tableauDistance[7];
    //coin inférieur gauche
    tableauDistance[0]=pythagore(positionFinaleGrenadeXTemps,character.getPosition().x,positionFinaleGrenadeYTemps,character.getPosition().y); 
    //a gauche du personnage dans le milieu
    tableauDistance[1]=pythagore(positionFinaleGrenadeXTemps, character.getPosition().x, positionFinaleGrenadeYTemps, character.getPosition().y+character.getHitboxHeight()/2 );
    
    //coin supérieur gauche
    tableauDistance[2]=pythagore(positionFinaleGrenadeXTemps, character.getPosition().x, positionFinaleGrenadeYTemps, character.getPosition().y+character.getHitboxHeight());
    //Milieu supérieur 
    tableauDistance[3]=pythagore(positionFinaleGrenadeXTemps,character.getPosition().x+character.getHitboxWidth()/2,positionFinaleGrenadeYTemps, character.getPosition().y+character.getHitboxHeight());
    //coin supérieur droit
    tableauDistance[4]=pythagore(positionFinaleGrenadeXTemps,character.getPosition().x+character.getHitboxWidth(),positionFinaleGrenadeYTemps, character.getPosition().y+character.getHitboxHeight());
    //a droite du personnage dans le milieu
    tableauDistance[5]=pythagore(positionFinaleGrenadeXTemps,character.getPosition().x+character.getHitboxWidth(),positionFinaleGrenadeYTemps, character.getPosition().y+character.getHitboxHeight()/2);
    //coin inférieur droit
    tableauDistance[6]=pythagore(positionFinaleGrenadeXTemps,character.getPosition().x+character.getHitboxWidth(),positionFinaleGrenadeYTemps, character.getPosition().y);
    
    int distanceMin=tableauDistance[0];
    if((positionFinaleGrenadeXTemps>=character.getPosition().x && positionFinaleGrenadeXTemps<=character.getPosition().x+ character.getHitboxWidth()) && (positionFinaleGrenadeYTemps>=character.getPosition().y && positionFinaleGrenadeYTemps<=character.getPosition().y+character.getHitboxHeight()))
    {
        explosionDamage=120;
    }
    else if(positionFinaleGrenadeYTemps<=100)
    {
        if(positionFinaleGrenadeXTemps<character.getPosition().x|| positionFinaleGrenadeXTemps>character.getPosition().x+character.getHitboxWidth())
        {
            explosionDamage=0;
            positionFinaleGrenadeYTemps=100;
            
        }
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
    //cout << "La cible a actuellement " <<character.getHealthPoint() << " points de vie. la grenade a frappe a une vitesse de " << Vf << " pixels/s a la position: ( "<<positionFinaleGrenadeXTemps<<", "<<positionFinaleGrenadeYTemps<<")"<<endl;
    bulletEndPosition.x=positionFinaleGrenadeXTemps;
    bulletEndPosition.y=positionFinaleGrenadeYTemps;
    return explosionDamage;
    
}
int Grenade::getProjectileMaxSpeed()
{
    return grenadeMaxSpeed;
}