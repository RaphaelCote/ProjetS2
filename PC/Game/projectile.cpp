// projectile.cpp
#include "projectile.h"
using namespace std;

Projectile::Projectile(Character &character)
{

    angledeg = 0;
    puissance = 0;
    this->bulletStartPosition.x = character.getWeaponPosition().x;
    this->bulletStartPosition.y = character.getWeaponPosition().y;
    this->hitbox = {1, 1};
}

Projectile::Projectile(Coordonnee bulletStartPosition)
{
    angledeg = 0;
    puissance = 0;
    this->bulletStartPosition.x = bulletStartPosition.x;
    this->bulletStartPosition.y = bulletStartPosition.y;
    this->bulletCurrentPosition.x = bulletStartPosition.x;
    this->bulletCurrentPosition.y = bulletStartPosition.y;
    this->hitbox = {1, 1};
}

Projectile::Projectile(Coordonnee bulletStartPosition, Hitbox hitboxset)
{
    angledeg = 0;
    puissance = 0;
    this->bulletStartPosition = bulletStartPosition;
    this->bulletCurrentPosition = bulletStartPosition;
    this->hitbox = hitboxset;
}
Projectile::~Projectile()
{

}
float Projectile::getPuissance()
{
    return puissance;
}
void Projectile::setPuissance(float puissance)
{
    this->puissance = puissance;
}
float Projectile::getAngleDegre()
{
    return angledeg;
}
void Projectile::setAngleDegre(float angledeg)
{
    this->angledeg = angledeg;
}
Coordonnee Projectile::getbulletStartPosition()
{
    return bulletStartPosition;
}
void Projectile::setbulletStartPosition(Coordonnee bulletStartPosition)
{
    this->bulletStartPosition = bulletStartPosition;
}

int Projectile::findBulletPositionYTime(float time)
{
    int positionfinaleY;
    if(angledeg<0)
    {
        rad = -angledeg * PI / 180;
        // cout<<"radian: "<<rad<<endl;
        V0 = puissance * getProjectileMaxSpeed();
        // cout<<"V0 :"<<V0<<endl;
        float num = pow((g * time + V0 * sin(rad)), 2) - pow((V0 * sin(rad)), 2);
        float denum = 2.0f * g;
        positionfinaleY = round(num / denum + bulletStartPosition.y);
    }
    if(angledeg>0)
    {
        // une grenade explose après 3 secondes donc entré 3 sec en paramètre
        rad = angledeg * PI / 180;
        // cout<<"radian: "<<rad<<endl;
        V0 = puissance * getProjectileMaxSpeed();
        // cout<<"V0 :"<<V0<<endl;
        float num = pow((g * time + V0 * sin(rad)), 2) - pow((V0 * sin(rad)), 2);
        float denum = 2.0f * g;
        positionfinaleY = round(num / denum + bulletStartPosition.y);
        // cout<<"Position finale y avant condition: "<<positionfinaleY<<endl;
    }
    
    return positionfinaleY;
}
int Projectile::findBulletPositionY(int positionX)
{
    V0 = puissance * getProjectileMaxSpeed();

    rad = angledeg * PI / 180;

    float deltax = (positionX - (bulletStartPosition.x));
    double positionY = ((g * deltax * deltax) / (2 * V0 * V0 * pow(cos(rad), 2)) + deltax * tan(rad)) + bulletStartPosition.y;

    return round(positionY);
}

int Projectile::findBulletPositionX(int positionY)
{
    V0 = puissance * getProjectileMaxSpeed();
    int positionX = 0;
    
    rad = angledeg * PI / 180;
    // cout<<"conversion de deg a rad= "<< rad<<endl;
    // float rad=angledeg;
    float deltay = (positionY - bulletStartPosition.y);
    float numeratorx1 = -tan(rad) + sqrt(pow(tan(rad), 2) - ((2 * g) / (pow(V0, 2) * pow(cos(rad), 2))) * -1 * deltay);
    float numeratorx2 = -tan(rad) - sqrt(pow(tan(rad), 2) - ((2 * g) / (pow(V0, 2) * pow(cos(rad), 2))) * -1 * deltay);
    float denominator = g / (pow(V0, 2) * pow(cos(rad), 2));

    float positionX1 = (numeratorx1 / denominator) + bulletStartPosition.x;
    float positionX2 = (numeratorx2 / denominator) + bulletStartPosition.x;
    // SI l'angle est négatif, faire un autre code, sinon prendre lui qu'on a live
    // cout<<"positionX1: "<<positionX1<<endl;
    // cout<<"positionX2: "<<positionX2<<endl;
    if (angledeg > 0)
    {
        // float tempsVol = abs((2*V0*sin(rad))/g);
        // int positionY = findBulletPositionYTime(tempsVol/2);
        if (positionX1 >= 0 && positionX1 > positionX2)
        {
            positionX = round(positionX1);
        }
        if (positionX2 >= 0 && positionX2 > positionX1)
        {
            positionX = round(positionX2);
        }
    }
    if (angledeg < 0)
    {

        if (positionX1 < positionX2)
        {
            positionX = round(positionX1);
        }
        if (positionX2 < positionX1)
        {
            positionX = round(positionX2);
        }
    }

    return positionX;
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
int Projectile::findHalfTrajectoryBulletPosition()
{
    //formule du temps de vole
    float tempsVol = abs((2*V0*sin(rad))/g);
    int positionY = findBulletPositionYTime(tempsVol/2);
    int positionX = findBulletPositionX(positionY);
    return positionX;

}

bool Projectile::checkIfCharacterHit(Character* character)
{

    Coordonnee characterPosition = character->getPosition();
    /*on sait que c'est l'ennemie qui se fait tirer dessus
    ---------------------IMPORTANT-----------------
    le bulletEndPosition de la grenade est actualisé dans, damageReceived
    ça fonctionne mais idéalement cela pourrait être plus prore */

    if (angledeg > 0)
    {
        if (findBulletPositionX(characterPosition.y) < characterPosition.x && findBulletPositionY(characterPosition.x) < characterPosition.y)
        {
            // on sait qu'il n'a pas toucher directement l'ennemie
            // pour les coordonnées de la balle, ce sera a changé éventuellement (vérifier si cela a touché bateau ou l'eau)
            cout<<"Premier if angle positif"<<endl;
            bulletEndPosition.x = findBulletPositionX(characterPosition.y);
            bulletEndPosition.y = characterPosition.y;
            damageReceived(*character);
            CheckerBounce();
            cout<<"bulletEndPosition.x = "<<bulletEndPosition.x<<endl;
            cout<<"bulletEndPosition.y = "<<bulletEndPosition.y<<endl;
            cout<<"Vf= "<<Vf<<endl;
            return false;
        }
        else if (findBulletPositionY(characterPosition.x) <= (characterPosition.y + character->getHitboxHeight()))
        {
            // on sait qu'il a toucher le cote lateral droit du personnage
            cout<<"Premier else if angle positif"<<endl;
            bulletEndPosition.x = characterPosition.x;
            bulletEndPosition.y = findBulletPositionY(characterPosition.x);
            damageReceived(*character);
            CheckerBounce();
            cout<<"bulletEndPosition.x = "<<bulletEndPosition.x<<endl;
            cout<<"bulletEndPosition.y = "<<bulletEndPosition.y<<endl;
            cout<<"Vf= "<<Vf<<endl;
            return true;
        }
        else if (findBulletPositionY(characterPosition.x + character->getHitboxWidth()) > (characterPosition.y + character->getHitboxHeight()))
        { // on sait qu'il ne touchera pas l'ennemie directement (passer par dessus l'ennemie)
            // pour les coordonnées de la balle, ce sera a changé éventuellement (vérifier si cela a touché bateau ou l'eau)
            cout<<"Deuxième else if angle positif"<<endl;

            // il va falloir modifier cette condition (si elle touche le bateau ou non)
            bulletEndPosition.x = findBulletPositionX(characterPosition.y);
            bulletEndPosition.y = characterPosition.y;
            damageReceived(*character);
            CheckerBounce();
            cout<<"bulletEndPosition.x = "<<bulletEndPosition.x<<endl;
            cout<<"bulletEndPosition.y = "<<bulletEndPosition.y<<endl;
            cout<<"Vf= "<<Vf<<endl;
            return false;
        }
        else if (findBulletPositionY(characterPosition.x + character->getHitboxWidth()) == (characterPosition.y + character->getHitboxHeight()))
        {
            // on sait qu'il a touché l'ennemie sur le coin supérieur droit
            cout<<"Troisième else if angle positif"<<endl;
            bulletEndPosition.x = characterPosition.x + character->getHitboxWidth();
            bulletEndPosition.y = findBulletPositionY(characterPosition.x + character->getHitboxWidth());
            damageReceived(*character);
            CheckerBounce();
            cout<<"bulletEndPosition.x = "<<bulletEndPosition.x<<endl;
            cout<<"bulletEndPosition.y = "<<bulletEndPosition.y<<endl;
            cout<<"Vf= "<<Vf<<endl;
            return true;
        }
        else if (findBulletPositionY(characterPosition.x + character->getHitboxWidth()) <= (characterPosition.y + character->getHitboxHeight()))
        {
            // on sait qu'il a touché l'ennemie entre son coin supérieur gauche et supérieur droit excluant
            cout<<"Quatrième else if angle positif"<<endl;
            bulletEndPosition.x = findBulletPositionX(characterPosition.y + character->getHitboxHeight());
            bulletEndPosition.y = characterPosition.y + character->getHitboxHeight();
            damageReceived(*character);
            CheckerBounce();
            cout<<"bulletEndPosition.x = "<<bulletEndPosition.x<<endl;
            cout<<"bulletEndPosition.y = "<<bulletEndPosition.y<<endl;
            cout<<"Vf= "<<Vf<<endl;
            return true;
        }
        else
        {
            // cout<<"Else angle positif"<<endl;
            // THÉORIQUEMENT rien passe dans le false, mais je le garde pour le déboguage

            bulletEndPosition.x = findBulletPositionX(characterPosition.y);
            bulletEndPosition.y = characterPosition.y;
            damageReceived(*character);
            CheckerBounce();
            return false;
        }
    }
    if (angledeg < 0)
    {
        if (findBulletPositionX(characterPosition.y) > characterPosition.x + character->getHitboxWidth() && findBulletPositionY(characterPosition.x + character->getHitboxWidth()) < characterPosition.y)
        {
            // on sait qu'il n'a pas toucher directement l'ennemie
            // pour les coordonnées de la balle, ce sera a changé éventuellement (vérifier si cela a touché bateau ou l'eau)
            cout<<"Premier if angle négatif"<<endl;
            bulletEndPosition.x = findBulletPositionX(characterPosition.y);
            bulletEndPosition.y = characterPosition.y;
            damageReceived(*character);
            CheckerBounce();
            cout<<"bulletEndPosition.x = "<<bulletEndPosition.x<<endl;
            cout<<"bulletEndPosition.y = "<<bulletEndPosition.y<<endl;
            cout<<"Vf= "<<Vf<<endl;
            return false;
        }
        else if (findBulletPositionY(characterPosition.x + character->getHitboxWidth()) <= (characterPosition.y + character->getHitboxHeight()))
        {
            // on sait qu'il a toucher a la position du projectile en X
            cout<<"Premier else if angle négatif"<<endl;
            bulletEndPosition.x = characterPosition.x + character->getHitboxWidth();
            bulletEndPosition.y = findBulletPositionY(characterPosition.x + character->getHitboxWidth());
            damageReceived(*character);
            CheckerBounce();
            
            cout<<"bulletEndPosition.x = "<<bulletEndPosition.x<<endl;
            cout<<"bulletEndPosition.y = "<<bulletEndPosition.y<<endl;
            cout<<"Vf= "<<Vf<<endl;
            return true;
        }
        else if (findBulletPositionY(characterPosition.x) > (characterPosition.y + character->getHitboxHeight()))
        { // on sait qu'il ne touchera pas l'ennemie directement (passer par dessus l'ennemie)
            // pour les coordonnées de la balle, ce sera a changé éventuellement (vérifier si cela a touché bateau ou l'eau)
            cout<<"Deuxième else if angle négatif"<<endl;
            bulletEndPosition.x = findBulletPositionX(characterPosition.y);
            bulletEndPosition.y = characterPosition.y;
            damageReceived(*character);
            CheckerBounce();
            cout<<"bulletEndPosition.x = "<<bulletEndPosition.x<<endl;
            cout<<"bulletEndPosition.y = "<<bulletEndPosition.y<<endl;
            cout<<"Vf= "<<Vf<<endl;
            return false;
        }
        else if (findBulletPositionY(characterPosition.x) == (characterPosition.y + character->getHitboxHeight()))
        {
            // on sait qu'il a touché l'ennemie sur le coin supérieur droit
            cout<<"Troisième else if angle négatif"<<endl;
            bulletEndPosition.x = characterPosition.x;
            bulletEndPosition.y = findBulletPositionY(characterPosition.x);
            damageReceived(*character);
            CheckerBounce();
            cout<<"bulletEndPosition.x = "<<bulletEndPosition.x<<endl;
            cout<<"bulletEndPosition.y = "<<bulletEndPosition.y<<endl;
            cout<<"Vf= "<<Vf<<endl;
            return true;
        }
        else if (findBulletPositionY(characterPosition.x) <= (characterPosition.y + character->getHitboxHeight()))
        {
            // on sait qu'il a touché l'ennemie entre son coin supérieur gauche et supérieur droit excluant
            cout<<"Quatrième else if angle négatif"<<endl;
            bulletEndPosition.x = findBulletPositionX(characterPosition.y + character->getHitboxHeight());
            bulletEndPosition.y = characterPosition.y + character->getHitboxHeight();
            damageReceived(*character);
            CheckerBounce();
            cout<<"bulletEndPosition.x = "<<bulletEndPosition.x<<endl;
            cout<<"bulletEndPosition.y = "<<bulletEndPosition.y<<endl;
            cout<<"Vf= "<<Vf<<endl;
            return true;
        }
        else
        {
            // cout << "Else angle négatif" << endl;
            // THÉORIQUEMENT rien passe dans le false, mais je le garde pour le déboguage

            bulletEndPosition.x = findBulletPositionX(characterPosition.y);
            bulletEndPosition.y = characterPosition.y;
            damageReceived(*character);
            CheckerBounce();
            
            return false;
        }
    }
}
void Projectile::checkVecteurCharacters(Vecteur<Character*> character)
{
    //il mnaque une condition pour que ça puisse marcher correctement
    do
    {
        for(int i=0;i<character.getSize();i++)
        {
            checkIfCharacterHit(character[i]);
        }
    } 
    while (Vf>50 && bulletEndPosition.y>=101);//bulletEndPosition.y>=a la hauteur de l'eau +1
    Vf=0;
    
}


Coordonnee Projectile::getBulletEndPosition()
{
    return bulletEndPosition;
}
void Projectile::AjouterInfoHitbox (infoHitbox infohitbox)
{
    infoHitbox* newInfoHitbox = new infoHitbox;
    newInfoHitbox->type = infohitbox.type;
    newInfoHitbox->coordonnees = infohitbox.coordonnees;
    newInfoHitbox->hitbox = infohitbox.hitbox;
    vecteurInfohitbox.add(newInfoHitbox);


}
void Projectile::bubbleSortInfoHitbox(bool CharacterType)//if bool CharacterType==true, we sort the vector in ascending order, otherwise we sort the vector in descending order
{

    if(CharacterType)// c'est que le player tire l'ennemi
    {
        for(int i =0; i<vecteurInfohitbox.getSize()-1; i++)
        {
            cout<<"premiere for bubble"<<endl;
            for(int j=0; j<vecteurInfohitbox.getSize()-i-1;j++)
            {
                cout<<"deuxieme for bubble"<<endl;
                if(vecteurInfohitbox[j]->coordonnees.x >vecteurInfohitbox[j+1]->coordonnees.x)
                {
                    cout<<"if bubble"<<endl;
                    
                    infoHitbox* temporaire = vecteurInfohitbox[j];
                    vecteurInfohitbox[j] = vecteurInfohitbox[j+1];
                    vecteurInfohitbox[j+1] = temporaire; 
                }
            }
        }
    }
    else
    {
        for(int i =0; i<vecteurInfohitbox.getSize()-1; i++)
        {
            cout<<"premiere for bubble"<<endl;
            for(int j=0; j<vecteurInfohitbox.getSize()-i-1;j++)
            {
                cout<<"deuxieme for bubble"<<endl;
                if(vecteurInfohitbox[j]->coordonnees.x <vecteurInfohitbox[j+1]->coordonnees.x)
                {
                    cout<<"if bubble"<<endl;
                    //Coordonnee coordEnemy = niv->enemyBoats[i]->characters[j]->getPosition();
                    infoHitbox* temporaire = vecteurInfohitbox[j];
                    vecteurInfohitbox[j] = vecteurInfohitbox[j+1];
                    vecteurInfohitbox[j+1] = temporaire; 
                }
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
    
    cout<<"Rentrer dans BounceHorizontal"<<endl;
    if(angledeg>0)
    {
        
        cout<<"angledeg>0"<<endl;
        for(int i=0;i<vecteurInfohitbox.getSize();i++)
        {
            cout<<"For angledeg>0"<<endl;
            // JE ne sais pas si VF s'uptade, sinon le coder directement dans le if
            float dy=bulletEndPosition.y-bulletStartPosition.y;
            Vf= sqrt( pow(V0*cos(rad),2) + pow(V0*sin(rad),2) +2*g*dy);
            if((findBulletPositionY(vecteurInfohitbox[i]->coordonnees.x)>=vecteurInfohitbox[i]->coordonnees.y && findBulletPositionY(vecteurInfohitbox[i]->coordonnees.x)<=vecteurInfohitbox[i]->coordonnees.y+vecteurInfohitbox[i]->hitbox.height))
            {
                
                //bulletEndPosition.x= allHitboxObject[i].coordonnees.x;
                //bulletEndPosition.y=findBulletPositionY(allHitboxObject[i].coordonnees.x);
                //a vérifier
                float dy=bulletEndPosition.y - bulletStartPosition.y; 
                float Vfy= sqrt(pow(V0*sin(rad),2) +2*g*dy);
                int positionFinaleTempsVol = findHalfTrajectoryBulletPosition();
                cout<<"positionFinaleTempsVol: "<<positionFinaleTempsVol<<endl;
                //float angleCourant = 
                if(bulletEndPosition.x<positionFinaleTempsVol)
                {
                    angledeg= -findPositiveAngleBulletPositionY(bulletEndPosition.y);//courbe verte
                    puissance = dampingProjectile*puissance; 
                }
                else if(bulletEndPosition.x==positionFinaleTempsVol)
                {
                    angledeg = 0;
                    puissance = dampingProjectile*puissance; 
                }
                else if(bulletEndPosition.x>positionFinaleTempsVol)
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
        for(int i=0;i<vecteurInfohitbox.getSize();i++)
        {
            // JE ne sais pas si VF s'uptade, sinon le coder directement dans le if
            cout<<"For angledeg<0"<<endl;
            float dy=bulletEndPosition.y-bulletStartPosition.y;
            Vf= sqrt( pow(V0*cos(rad),2) + pow(V0*sin(rad),2) +2*g*dy);
            if((findBulletPositionY(vecteurInfohitbox[i]->coordonnees.x+vecteurInfohitbox[i]->hitbox.width)>=vecteurInfohitbox[i]->coordonnees.y && findBulletPositionY(vecteurInfohitbox[i]->coordonnees.x+vecteurInfohitbox[i]->hitbox.width)<=vecteurInfohitbox[i]->coordonnees.y+vecteurInfohitbox[i]->hitbox.height))
            {
                //inverse l'angle et damp la vitesse de 20% (nouvelle Vi =Vf*0.8)
                //à ce moment là, on sait qu'on a frappé une hitbox sur sa paroie latéral droite
                cout<<"if bounceHorizontal"<<endl;
                //bulletEndPosition.x= allHitboxObject[i].coordonnees.x+allHitboxObject[i].width;
                //bulletEndPosition.y=findBulletPositionY(allHitboxObject[i].coordonnees.x+allHitboxObject[i].width);
                
                float dy=bulletEndPosition.y - bulletStartPosition.y; 
                float Vfy= sqrt(pow(V0*sin(rad),2) +2*g*dy);
                int positionFinaleTempsVol = findHalfTrajectoryBulletPosition();
                cout<<"positionFinaleTempsVol: "<<positionFinaleTempsVol<<endl;
                if(bulletEndPosition.x>positionFinaleTempsVol)
                {
                    cout<<"bulletEndPosition.x>positionFinaleTempsVol"<<endl;
                    angledeg= -findPositiveAngleBulletPositionY(bulletEndPosition.y);
                    puissance = dampingProjectile*puissance; 
                }
                else if(bulletEndPosition.x==positionFinaleTempsVol)
                {
                    cout<<"bulletEndPosition.x==positionFinaleTempsVol"<<endl;
                    angledeg = 0;
                    puissance = dampingProjectile*puissance; 
                }
                else if(bulletEndPosition.x<positionFinaleTempsVol)
                {
                    cout<<"bulletEndPosition.x<positionFinaleTempsVol"<<endl;
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
   
    cout<<"Rentrer dans BounceVerticale"<<endl;
    for(int i=0;i<vecteurInfohitbox.getSize();i++)
    {
                //utilise l'équation verte pour trouver l'angle de frappe 
           // }
            
            //else{
               //utilise l'équation bleu pour trouver l'angle de frappe  
            //}
                
            // demandé a Raph si y faut refaire un projectile
        cout<<"for bounceVertical"<<endl;
        if((findBulletPositionX(vecteurInfohitbox[i]->coordonnees.y)>=vecteurInfohitbox[i]->coordonnees.x && findBulletPositionX(vecteurInfohitbox[i]->coordonnees.y)<=vecteurInfohitbox[i]->coordonnees.x+vecteurInfohitbox[i]->hitbox.width))
        {
            cout<<"if bounceVertical"<<endl;
            angledeg = -findNegativeAngleBulletPositionY(vecteurInfohitbox[i]->coordonnees.y+vecteurInfohitbox[i]->hitbox.height);
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
    //if(bulletStartPosition.x!=bulletEndPosition.x )
}