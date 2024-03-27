//projectile.cpp
#include "projectile.h"
#include "../Scenes/game.h"
//#include "../raftWars.h"
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
float Projectile::getPuissance(){
    return puissance;
}
void Projectile::setPuissance(float puissance){
    this->puissance=puissance;
}
float Projectile::getAngleDegre(){
    return angledeg;
}
void Projectile::setAngleDegre(float angledeg){
    this->angledeg=angledeg;
}
Coordonnee Projectile::getbulletStartPosition(){
    return bulletStartPosition;
}
void Projectile::setbulletStartPosition(Coordonnee bulletStartPosition){
    this->bulletStartPosition=bulletStartPosition;
}
int Projectile::findBulletPositionYAngle(float angle)
{
    //courbe rouge desmos
    int positionY = round(( pow((puissance * getProjectileMaxSpeed() *cos(angledeg*PI/180) * tan(angle*PI/180)),2) - pow(( puissance* getProjectileMaxSpeed() * sin(angledeg*PI/180)),2))/2*g) +150;
    return positionY;
}
float Projectile::findNegativeAngleBulletPositionY(int positionY)//courbe bleu dans le desmos
{  
    float num = -sqrt( pow((puissance*getProjectileMaxSpeed() * sin(angledeg * PI/180)), 2) +2*g*(positionY- bulletStartPosition.y) );
    float denum = puissance*getProjectileMaxSpeed()*cos(angledeg*PI/180);
    float angleFinal = atan(num/denum)*180/PI;
    return angleFinal;
    //float denum =;
}
float Projectile::findPositiveAngleBulletPositionY(int positionY)//courbe verte dans le desmos 
{
    float num = sqrt( pow((puissance*getProjectileMaxSpeed() * sin(angledeg * PI/180)), 2) +2*g*(positionY- bulletStartPosition.y) );
    float denum = puissance*getProjectileMaxSpeed()*cos(angledeg*PI/180);
    float angleFinal = atan(num/denum)*180/PI;
    return angleFinal;
}
int Projectile::findBulletPositionYTime(float time)
{
    //une grenade explose après 3 secondes donc entré 3 sec en paramètre
    rad=angledeg*PI/180;
    cout<<"radian: "<<rad<<endl;
    V0=puissance*getProjectileMaxSpeed();
    cout<<"V0 :"<<V0<<endl;
    float num= pow((g*time +V0*sin(rad)),2)- pow((V0*sin(rad)),2);
    float denum =2.0f*g;
    int positionfinaleY= round(num/denum+ bulletStartPosition.y);
    cout<<"Position finale y avant condition: "<<positionfinaleY<<endl;    
    return positionfinaleY;
    
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

void Projectile::checkIfCharacterHit(Vecteur<Character*> character)
{
    /*---------------------IMPORTANT-----------------
    le bulletEndPosition de la grenade est actualisé dans, damageReceived
    ça fonctionne mais idéalement cela pourrait être plus propre */

    // on sait que c'est le joueur qui a tiré
    do
    {
        if(angledeg>0)
        {
            for(int i=0;i<character.getSize();i++)
            {
                //projectile->checkIfCharacterHit(*(activeLevel->characters[1])); 
                if(findBulletPositionX(character[i]->getPosition().y)<character[i]->getPosition().x && findBulletPositionY(character[i]->getPosition().x) < character[i]->getPosition().y)
                {
                    //on sait qu'il n'a pas toucher directement l'ennemie
                    //pour les coordonnées de la balle, ce sera a changé éventuellement (vérifier si cela a touché bateau ou l'eau)
                    cout<<"Premier if angle positif"<<endl;

                    //il va falloir modifier cette condition (si elle touche le bateau ou non)
                    bulletEndPosition.x=findBulletPositionX(character[i]->getPosition().y);
                    bulletEndPosition.y=character[i]->getPosition().y;
                    damageReceived(*character[i]);
                    cout << "vitesse finale après redéfinition " << Vf << endl;
                    CheckerBounce();   
                }
                else if(findBulletPositionY(character[i]->getPosition().x)<=(character[i]->getPosition().y+character[i]->getHitboxHeight()))    
                {
                    //on sait qu'il a toucher a la position du projectile en X
                    cout<<"Premier else if angle positif"<<endl;
                    bulletEndPosition.x=character[i]->getPosition().x;
                    bulletEndPosition.y=findBulletPositionY(character[i]->getPosition().x);
                    damageReceived(*character[i]);
                    cout << "vitesse finale après redéfinition " << Vf << endl;
                    CheckerBounce();

                }
                else if(findBulletPositionY(character[i]->getPosition().x+character[i]->getHitboxWidth())>(character[i]->getPosition().y+character[i]->getHitboxHeight()))
                {   //on sait qu'il ne touchera pas l'ennemie directement (passer par dessus l'ennemie)
                    //pour les coordonnées de la balle, ce sera a changé éventuellement (vérifier si cela a touché bateau ou l'eau)
                    cout<<"Deuxième else if angle positif"<<endl;
                    
                    //il va falloir modifier cette condition (si elle touche le bateau ou non)
                    bulletEndPosition.x=findBulletPositionX(character[i]->getPosition().y);
                    bulletEndPosition.y=character[i]->getPosition().y;
                    damageReceived(*character[i]);
                    cout << "vitesse finale après redéfinition " << Vf << endl;
                    CheckerBounce();
                }
                else if(findBulletPositionY(character[i]->getPosition().x+character[i]->getHitboxWidth())==(character[i]->getPosition().y+character[i]->getHitboxHeight()))
                {
                    //on sait qu'il a touché l'ennemie sur le coin supérieur droit
                    cout<<"Troisième else if angle positif"<<endl;
                    bulletEndPosition.x=character[i]->getPosition().x+character[i]->getHitboxWidth();
                    bulletEndPosition.y=findBulletPositionY(character[i]->getPosition().x+character[i]->getHitboxWidth());
                    damageReceived(*character[i]);
                    cout << "vitesse finale après redéfinition " << Vf << endl;
                    CheckerBounce();
                }
                else if(findBulletPositionY(character[i]->getPosition().x+character[i]->getHitboxWidth())<=(character[i]->getPosition().y+character[i]->getHitboxHeight()))
                {
                    //on sait qu'il a touché l'ennemie entre son coin supérieur gauche et supérieur droit excluant 
                    cout<<"Quatrième else if angle positif"<<endl;
                    bulletEndPosition.x=findBulletPositionX(character[i]->getPosition().y+character[i]->getHitboxHeight());
                    bulletEndPosition.y=character[i]->getPosition().y+character[i]->getHitboxHeight(); 
                    damageReceived(*character[i]);
                    cout << "vitesse finale après redéfinition " << Vf << endl;
                    CheckerBounce();
                }
                else
                {
                    cout<<"Else angle positif"<<endl;
                    //THÉORIQUEMENT rien passe dans le else, mais je le garde pour le déboguage 
                    bulletEndPosition.x=findBulletPositionX(character[i]->getPosition().y);
                    bulletEndPosition.y=character[i]->getPosition().y;
                    damageReceived(*character[i]);
                    cout << "vitesse finale après redéfinition " << Vf << endl;
                    CheckerBounce();

                }
            }
            
        }
    // on sait que c'est l'ennemie qui a tiré
        if(angledeg<0)
        {
            for(int i=0;i<character.getSize();i++)
            {
                if(findBulletPositionX(character[i]->getPosition().y)>character[i]->getPosition().x + character[i]->getHitboxWidth() && findBulletPositionY(character[i]->getPosition().x+character[i]->getHitboxWidth()) < character[i]->getPosition().y)
                {
                    //on sait qu'il n'a pas toucher directement l'ennemie
                    //pour les coordonnées de la balle, ce sera a changé éventuellement (vérifier si cela a touché bateau ou l'eau)
                    cout<<"Premier if angle négatif"<<endl;
                    bulletEndPosition.x=findBulletPositionX(character[i]->getPosition().y);
                    bulletEndPosition.y=character[i]->getPosition().y;
                    damageReceived(*character[i]);
                    cout << "vitesse finale après redéfinition " << Vf << endl;
                    CheckerBounce();
                }
                else if(findBulletPositionY(character[i]->getPosition().x+character[i]->getHitboxWidth())<=(character[i]->getPosition().y+character[i]->getHitboxHeight()))    
                {
                    //on sait qu'il a toucher a la position du projectile en X
                    cout<<"Premier else if angle négatif"<<endl;
                    bulletEndPosition.x=character[i]->getPosition().x+character[i]->getHitboxWidth() ;
                    bulletEndPosition.y=findBulletPositionY(character[i]->getPosition().x + character[i]->getHitboxWidth());
                    damageReceived(*character[i]);
                    cout << "vitesse finale après redéfinition " << Vf << endl;
                    CheckerBounce();
                }
                else if(findBulletPositionY(character[i]->getPosition().x)>(character[i]->getPosition().y+character[i]->getHitboxHeight()))
                {   //on sait qu'il ne touchera pas l'ennemie directement (passer par dessus l'ennemie)
                    //pour les coordonnées de la balle, ce sera a changé éventuellement (vérifier si cela a touché bateau ou l'eau)
                    cout<<"Deuxième else if angle négatif"<<endl;
                    bulletEndPosition.x=findBulletPositionX(character[i]->getPosition().y);
                    bulletEndPosition.y=character[i]->getPosition().y;
                    damageReceived(*character[i]);
                    cout << "vitesse finale après redéfinition " << Vf << endl;
                    CheckerBounce();
                }
                else if(findBulletPositionY(character[i]->getPosition().x)==(character[i]->getPosition().y+character[i]->getHitboxHeight()))
                {
                    //on sait qu'il a touché l'ennemie sur le coin supérieur droit
                    cout<<"Troisième else if angle négatif"<<endl;
                    bulletEndPosition.x=character[i]->getPosition().x;
                    bulletEndPosition.y=findBulletPositionY(character[i]->getPosition().x);
                    damageReceived(*character[i]);
                    cout << "vitesse finale après redéfinition " << Vf << endl;
                    CheckerBounce();
                }
                else if(findBulletPositionY(character[i]->getPosition().x)<=(character[i]->getPosition().y+character[i]->getHitboxHeight()))
                {
                    //on sait qu'il a touché l'ennemie entre son coin supérieur gauche et supérieur droit excluant 
                    cout<<"Quatrième else if angle négatif"<<endl;
                    bulletEndPosition.x=findBulletPositionX(character[i]->getPosition().y+character[i]->getHitboxHeight());
                    bulletEndPosition.y=character[i]->getPosition().y+character[i]->getHitboxHeight(); 
                    damageReceived(*character[i]);
                    cout << "vitesse finale après redéfinition " << Vf << endl;
                    CheckerBounce();
                }
                else{
                    cout<<"Else angle négatif"<<endl;
                    //THÉORIQUEMENT rien passe dans le else, mais je le garde pour le déboguage 
                    bulletEndPosition.x=findBulletPositionX(character[i]->getPosition().y);
                    bulletEndPosition.y=character[i]->getPosition().y;
                    damageReceived(*character[i]);
                    cout << "vitesse finale après redéfinition " << Vf << endl;
                    CheckerBounce();
                }
            }
        }
    }
    while(Vf>50 || bulletEndPosition.y>100);//plus haut que la hauteur de l'eau
     
}

Coordonnee Projectile::getBulletEndPosition()
{
    return bulletEndPosition;
}


// //-------------------BOUNCE-------------------//

// void Projectile::ScanHitboxes()
// {
//     Game *game = (Game *)scenes->get(1);
    
//     Niveau* niv= game->activeLevel; //si erreur avec crochet appeler get dans vecteur.cpp
//     //-------------------bateaux ennemis----------------------//
//     for(int i=0;i<niv->enemyBoats.getSize();i++)
//     {
//         cout<<"for pour les éléments dans le bateau ennemi"<<endl;
//         for(int j=0;j<niv->enemyBoats[i]->characters.getSize();j++)
//         { 
//             //for pour chaque hitbox du bateau (si un bateau a 3 hitboxes, la for ce fait 3X)
//             cout<<"for pour chaque hitbox du bateau ennemi"<<endl;
//             allHitboxObject.add(niv->enemyBoats[i]->characters[j]->getHitbox());
//         }
//         for(int j=0;j<niv->enemyBoats[i]->hitboxes.getSize();j++)
//         { 
//             cout<<"for pour les personnages dans le bateau ennemi"<<endl;  
//             allHitboxObject.add(*niv->enemyBoats[i]->hitboxes[j]);
//         }
//     }
//     //-------------------bateaux alliés----------------------//
//     for(int i=0;i<niv->playerBoats.getSize();i++)
//     {
//         cout<<"for pour les éléments dans le bateau alliés"<<endl;
//         for(int j=0;j<niv->playerBoats[i]->characters.getSize();j++)
//         { 
//             //for pour chaque hitbox du bateau (si un bateau a 3 hitboxes, la for ce fait 3X)
//             cout<<"for pour chaque hitbox du bateau alliés"<<endl;
//             allHitboxObject.add(niv->playerBoats[i]->characters[j]->getHitbox());
//         }

//         //niv->enemyBoats[i]->hitBoxBoat


//         //for pour les hitboxs du bateau aliée
//         for(int j=0;j<niv->playerBoats[i]->hitboxes.getSize();j++)
//         { 
//             //on vérifie si la balle se retrouve entre les extremum en y de chaque surface verticale gauche de chaque hitbox du niveau
//             //si oui, la vitesse en x est inversée (vers le gauche plutot que vers la droite) et réduite de 20
//             allHitboxObject.add(*niv->playerBoats[i]->hitboxes[j]);
//             cout<<"for pour les personnages dans le bateau alliés"<<endl; 
//         }
        
//     }
    
//     //------------Sorted croissant de la position des hitbox (bubble sort)----------//

//     for(int i =0; i<allHitboxObject.getSize()-1; i++)
//     {
//         cout<<"premiere for bubble"<<endl;
//         for(int j=0; i< allHitboxObject.getSize()-i-1;j++)
//         {
//             cout<<"deuxieme for bubble"<<endl;
//             if(allHitboxObject[j].coordonnees.x>allHitboxObject[j+1].coordonnees.x)
//             {
//                 cout<<"if bubble"<<endl;
//                 //Coordonnee coordEnemy = niv->enemyBoats[i]->characters[j]->getPosition();
//                 Hitbox temporaire = allHitboxObject[j];
//                 allHitboxObject[j] = allHitboxObject[j+1];
//                 allHitboxObject[j+1] = temporaire; 
//             }
//         }
//     }
        
// }

void Projectile::BounceHorizontal()// si elle frape un paroie 
{
    //---------Explication de la if en deux segments segments---------//
    /*
        1. (findBulletPositionY(coordEnemyBoatHitboxes.x)>=coordEnemyBoatHitboxes.y && findBulletPositionY(coordEnemyBoatHitboxes.x)<=coordEnemyBoatHitboxes.y+heightHitboxEnemyBoat)    (avant le ||)
        on vérifie si on est entre le coin inférieur gauche et le coin supérieur gauche de la hitbox 
        2. (findBulletPositionY(coordEnemyBoatHitboxes.x+widthHitboxEnemyBoat)>=coordEnemyBoatHitboxes.y && findBulletPositionY(coordEnemyBoatHitboxes.x+widthHitboxEnemyBoat)<=coordEnemyBoatHitboxes.y+heightHitboxEnemyBoat)   (après le || )
        on vérifie si on est entre le coin inférieur droit et le coin supérieur droit de la hitbox
        AU MOINS UNE DE SES DEUX CONDITIONS DOIT ÊTRE VRAI (sinon nous sommes clairement à coté et il n'y a pas de rebond)
        3. la vitesse doit être supérieur a 2% sinon on le considère arrêter
    */
    Maping * maping = new Maping();
    maping->ScanHitboxes();
    cout<<"Rentrer dans BounceHorizontal"<<endl;
    if(angledeg>0)
    {
        
        cout<<"angledeg>0"<<endl;
        for(int i=0;i<maping->allHitboxObject.getSize();i++)
        {
            cout<<"For angledeg<0"<<endl;
            // JE ne sais pas si VF s'uptade, sinon le coder directement dans le if
            float dy=bulletEndPosition.y-bulletStartPosition.y;
            Vf= sqrt( pow(V0*cos(rad),2) + pow(V0*sin(rad),2) +2*g*dy);
            if((findBulletPositionY(maping->allHitboxObject[i].coordonnees.x)>=maping->allHitboxObject[i].coordonnees.y && findBulletPositionY(maping->allHitboxObject[i].coordonnees.x)<=maping->allHitboxObject[i].coordonnees.y+maping->allHitboxObject[i].height))
            {
                
                //bulletEndPosition.x= allHitboxObject[i].coordonnees.x;
                //bulletEndPosition.y=findBulletPositionY(allHitboxObject[i].coordonnees.x);
                //a vérifier
                float dy=bulletEndPosition.y - bulletStartPosition.y; 
                float Vfy= sqrt(pow(V0*sin(rad),2) +2*g*dy)>0;
                if(Vfy>0)
                {
                    angledeg= -findPositiveAngleBulletPositionY(bulletEndPosition.y);//courbe verte
                    puissance = dampingProjectile*puissance; 
                }
                else if(Vfy==0)
                {
                    angledeg = 0;
                    puissance = dampingProjectile*puissance; 
                }
                else if(Vfy<0)
                {
                    angledeg= -findNegativeAngleBulletPositionY(bulletEndPosition.y);//pour les rebond vertical courbe bleu
                    puissance = dampingProjectile*puissance; 
                }
                // demandé a Raph si y faut refaire un projectile
                bulletStartPosition.x=bulletEndPosition.x;
                bulletStartPosition.y=bulletEndPosition.y;
            }
        }
    }
    if(angledeg<0)
    {
        cout<<"angledeg<0"<<endl;
        for(int i=0;i<maping->allHitboxObject.getSize();i++)
        {
            // JE ne sais pas si VF s'uptade, sinon le coder directement dans le if
            cout<<"For angledeg<0"<<endl;
            float dy=bulletEndPosition.y-bulletStartPosition.y;
            Vf= sqrt( pow(V0*cos(rad),2) + pow(V0*sin(rad),2) +2*g*dy);
            if((findBulletPositionY(maping->allHitboxObject[i].coordonnees.x+maping->allHitboxObject[i].width)>=maping->allHitboxObject[i].coordonnees.y && findBulletPositionY(maping->allHitboxObject[i].coordonnees.x+maping->allHitboxObject[i].width)<=maping->allHitboxObject[i].coordonnees.y+maping->allHitboxObject[i].height))
            {
                //inverse l'angle et damp la vitesse de 20% (nouvelle Vi =Vf*0.8)


                //bulletEndPosition.x= allHitboxObject[i].coordonnees.x+allHitboxObject[i].width;
                //bulletEndPosition.y=findBulletPositionY(allHitboxObject[i].coordonnees.x+allHitboxObject[i].width);
                
                float dy=bulletEndPosition.y - bulletStartPosition.y; 
                float Vfy= sqrt(pow(V0*sin(rad),2) +2*g*dy)>0;
                if(Vfy>0)
                {
                    angledeg= -findPositiveAngleBulletPositionY(bulletEndPosition.y);
                    puissance = dampingProjectile*puissance; 
                }
                else if(Vfy==0)
                {
                    angledeg = 0;
                    puissance = dampingProjectile*puissance; 
                }
                else if(Vfy<0)
                {
                    angledeg= -findNegativeAngleBulletPositionY(bulletEndPosition.y);
                    puissance = dampingProjectile*puissance; 
                }
                bulletStartPosition.x=bulletEndPosition.x;
                bulletStartPosition.y=bulletEndPosition.y;
            }
        }
    }
    
}

void Projectile::BounceVerticale()//si elle frappe un sol (plancher)
{
    Maping * maping = new Maping();
    maping->ScanHitboxes();
    cout<<"Rentrer dans BounceVerticale"<<endl;
    for(int i=0;i<maping->allHitboxObject.getSize();i++)
    {
                //utilise l'équation verte pour trouver l'angle de frappe 
           // }
            
            //else{
               //utilise l'équation bleu pour trouver l'angle de frappe  
            //}
                
            // demandé a Raph si y faut refaire un projectile
        cout<<"for bounceVertical"<<endl;
        if((findBulletPositionX(maping->allHitboxObject[i].coordonnees.y)>=maping->allHitboxObject[i].coordonnees.x && findBulletPositionX(maping->allHitboxObject[i].coordonnees.y)<=maping->allHitboxObject[i].coordonnees.x+maping->allHitboxObject[i].width))
        {
            angledeg = -findNegativeAngleBulletPositionY(maping->allHitboxObject[i].coordonnees.y+maping->allHitboxObject[i].height);
            puissance = dampingProjectile*puissance;
            bulletStartPosition.x=bulletEndPosition.x;
            bulletStartPosition.y=bulletEndPosition.y;
        }
    }

}
void Projectile::CheckerBounce()
{
    BounceHorizontal();
    BounceVerticale();
}