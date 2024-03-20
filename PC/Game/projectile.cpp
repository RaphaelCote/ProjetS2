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
   
    return round(( pow((puissance * getProjectileMaxSpeed() *cos(angledeg*PI/180) * tan(angle*PI/180)),2) - pow(( puissance* getProjectileMaxSpeed() * sin(angledeg*PI/180)),2))/2*g) +150;
}
float Projectile::findNegativeAngleBulletPositionY(int positionY)//courbe bleu dans le desmos
{
    
    float num = -sqrt( pow((puissance*getProjectileMaxSpeed() * sin(angledeg * PI/180)), 2) +2*g*(positionY- bulletStartPosition.y) );
    float denum = puissance*getProjectileMaxSpeed()*cos(angledeg*PI/180);
    float angleFinal = atan(num/denum)*180/PI;
    //float denum =;
}
float Projectile::findPositiveAngleBulletPositionY(int positionY)//courbe verte dans le desmos 
{
    float num = sqrt( pow((puissance*getProjectileMaxSpeed() * sin(angledeg * PI/180)), 2) +2*g*(positionY- bulletStartPosition.y) );
    float denum = puissance*getProjectileMaxSpeed()*cos(angledeg*PI/180);
    float angleFinal = atan(num/denum)*180/PI;
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
// a changer pour qu'elle prenne un vecteur de character (les characters dedans) de character en paramètre
bool Projectile::checkIfCharacterHit(Character& character)
{

    
    Coordonnee characterPosition =character.getPosition();
    /*on sait que c'est l'ennemie qui se fait tirer dessus
    ---------------------IMPORTANT-----------------
    le bulletEndPosition de la grenade est actualisé dans, damageReceived
    ça fonctionne mais idéalement cela pourrait être plus prore */

    if(angledeg>0)
    {
        if(findBulletPositionX(characterPosition.y)<characterPosition.x && findBulletPositionY(characterPosition.x) < characterPosition.y){
        //on sait qu'il n'a pas toucher directement l'ennemie
        //pour les coordonnées de la balle, ce sera a changé éventuellement (vérifier si cela a touché bateau ou l'eau)
            //cout<<"Premier if angle positif"<<endl;

            //il va falloir modifier cette condition (si elle touche le bateau ou non)
            bulletEndPosition.x=findBulletPositionX(characterPosition.y);
            bulletEndPosition.y=characterPosition.y;
            damageReceived(character);
            return false;
        }
        else if(findBulletPositionY(characterPosition.x)<=(characterPosition.y+character.getHitboxHeight()))    
        {
            //on sait qu'il a toucher a la position du projectile en X
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
            
            //il va falloir modifier cette condition (si elle touche le bateau ou non)
            bulletEndPosition.x=findBulletPositionX(characterPosition.y);
            bulletEndPosition.y=characterPosition.y;
            damageReceived(character);
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
            damageReceived(character);
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
            damageReceived(character);
            return false;
        }
        else if(findBulletPositionY(characterPosition.x+character.getHitboxWidth())<=(characterPosition.y+character.getHitboxHeight()))    
        {
            //on sait qu'il a toucher a la position du projectile en X
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
            damageReceived(character);
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
            damageReceived(character);
            return false;
        }
    }
    
}

Coordonnee Projectile::getBulletEndPosition()
{
    return bulletEndPosition;
}


//-------------------BOUNCE-------------------//

void Projectile::ScanHitboxes()// si elle frape un paroie 
{

    Game *game = (Game *)scenes->get(1);
    Vecteur<Hitbox> allHitboxObject;
    
    Niveau* niv= game->levels[game->GetLevel()]; //si erreur avec crochet appeler get dans vecteur.cpp
    //-------------------bateaux ennemis----------------------//
    for(int i=0;i<niv->enemyBoats.getSize();i++)
    {
        //for pour les personnages dans le bateau ennemi
        for(int j=0;j<niv->enemyBoats[i]->characters.getSize();j++)
        { 
            //for pour chaque hitbox du bateau (si un bateau a 3 hitboxes, la for ce fait 3X)

            //Hitbox EnemyHitboxes = niv->enemyBoats[i]->characters[j]->getHitbox();
            //Coordonnee coordEnemy = niv->enemyBoats[i]->characters[j]->getPosition();
            
            allHitboxObject.add(niv->enemyBoats[i]->characters[j]->getHitbox());
        }
        for(int j=0;j<niv->enemyBoats[i]->hitboxes.getSize();j++)
        { 
            //on vérifie si la balle se retrouve entre les extremum en x de chaque surface horizontale de chaque hitbox du niveau
            //si oui, la vitesse en y est inversée (vers le haut plutot que vers le bas) et réduite de 20%
            allHitboxObject.add(*niv->enemyBoats[i]->hitboxes[j]);
        }
    }
    //-------------------bateaux alliés----------------------//
    for(int i=0;i<niv->playerBoats.getSize();i++)
    {
        //for pour les personnages dans le bateau allié
        for(int j=0;j<niv->playerBoats[i]->characters.getSize();j++)
        { 
            //for pour chaque hitbox du bateau (si un bateau a 3 hitboxes, la for ce fait 3X)
            allHitboxObject.add(niv->playerBoats[i]->characters[j]->getHitbox());
        }
        //for pour les hitboxs du bateau aliée
        for(int j=0;j<niv->playerBoats[i]->hitboxes.getSize();j++)
        { 
            //on vérifie si la balle se retrouve entre les extremum en y de chaque surface verticale gauche de chaque hitbox du niveau
            //si oui, la vitesse en x est inversée (vers le gauche plutot que vers la droite) et réduite de 20
            allHitboxObject.add(*niv->playerBoats[i]->hitboxes[j]);
        }
        
    }
    
    //------------Sorted croissant de la position des hitbox (bubble sort)----------//

    for(int i =0; i<allHitboxObject.getSize()-1; i++)
    {
        for(int j=0; i< allHitboxObject.getSize()-i-1;j++)
        {
            if(allHitboxObject[j].coordonnees.x>allHitboxObject[j+1].coordonnees.x)
            {
                //Coordonnee coordEnemy = niv->enemyBoats[i]->characters[j]->getPosition();
                Hitbox temporaire = allHitboxObject[j];
                allHitboxObject[j] = allHitboxObject[j+1];
                allHitboxObject[j+1] = temporaire; 
            }
        }
    }
        
}

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
    if(angledeg>0)
    {
        for(int i=0;i<allHitboxObject.getSize();i++)
        {
            // JE ne sais pas si VF s'uptade, sinon le coder directement dans le if
            if((findBulletPositionY(allHitboxObject[i].coordonnees.x)>=allHitboxObject[i].coordonnees.y && findBulletPositionY(allHitboxObject[i].coordonnees.x)<=allHitboxObject[i].coordonnees.y+allHitboxObject[i].height) && Vf>0.02*getProjectileMaxSpeed())
            {
                bulletEndPosition.x= allHitboxObject[i].coordonnees.x;
                bulletEndPosition.y=findBulletPositionY(allHitboxObject[i].coordonnees.x);
                
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
                // demandé a Raph si y faut refaire un projectile
            }
        }
    }
    if(angledeg<0)
    {
        for(int i=0;i<allHitboxObject.getSize();i++)
        {
            // JE ne sais pas si VF s'uptade, sinon le coder directement dans le if
            if((findBulletPositionY(allHitboxObject[i].coordonnees.x+allHitboxObject[i].width)>=allHitboxObject[i].coordonnees.y && findBulletPositionY(allHitboxObject[i].coordonnees.x+allHitboxObject[i].width)<=allHitboxObject[i].coordonnees.y+allHitboxObject[i].height) && Vf>0.02*getProjectileMaxSpeed())
            {
                //inverse l'angle et damp la vitesse de 20% (nouvelle Vi =Vf*0.8)


                bulletEndPosition.x= allHitboxObject[i].coordonnees.x+allHitboxObject[i].width;
                bulletEndPosition.y=findBulletPositionY(allHitboxObject[i].coordonnees.x+allHitboxObject[i].width);
                
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
            }
        }
    }
    
}

void Projectile::BounceVerticale()//si elle frappe un sol (plancher)
{
    for(int i=0;i<allHitboxObject.getSize();i++)
    {
        // JE ne sais pas si VF s'uptade, sinon le coder directement dans le if
        if((findBulletPositionX(allHitboxObject[i].coordonnees.y)>=allHitboxObject[i].coordonnees.x && findBulletPositionX(allHitboxObject[i].coordonnees.y)<=allHitboxObject[i].coordonnees.x+allHitboxObject[i].width) && Vf>0.02*getProjectileMaxSpeed())
        {
            //int bulletHitPositionX = findBulletPositionX(allHitboxObject.coordonnees.y +allHitboxObject.height);
            //int bulletHitPositionY = findBulletPositionY(bulletHitPositionX);
            //if(bulletHitPositionY > findBulletPositionYAngle(0) )
            //{
                //utilise l'équation verte pour trouver l'angle de frappe 
           // }
            
            //else{
               //utilise l'équation bleu pour trouver l'angle de frappe  
            //}
                
            // demandé a Raph si y faut refaire un projectile
            angledeg = -findNegativeAngleBulletPositionY(allHitboxObject[i].coordonnees.y+allHitboxObject[i].height);
            puissance = dampingProjectile*puissance;
        }
    }

}
void Projectile::CheckerBounce()
{
    BounceHorizontal();
    BounceVerticale();
}