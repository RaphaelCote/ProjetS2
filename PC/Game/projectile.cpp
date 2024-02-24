//projectile.cpp
#include "projectile.h"
using namespace std;
// int Projectile::getDamage(){
//     return damage;
// }
Projectile::Projectile(Character& character)/*: lastShooter(character)*/{
    //: personnage(0, 0), damage(0) {}
    //cout << "test x initial: " << positionInitiale.x << endl;
    //this->positionInitiale={600,200};
    //character.getPosition();
    this->positionInitiale=character.getWeaponPosition();
    //cout << "test x initial: " << positionInitiale.x << endl;
    //prendre les coordonnées du player
    //lastShooter.getPosition();
}
int Projectile::findBulletPositionY(int positionX){
    //float V0=VITESSEMAX*puissance;
    V0=puissance*getProjectileMaxSpeed();
    
    //cout<<"Vitesse V0 trouvé: "<<V0<<endl;
    Coordonnee projectileStartPosition =positionInitiale;
    
    cout<<"Départ projectile: ("<<projectileStartPosition.x<< ", "<<projectileStartPosition.y<<")"<<endl;//détecte la bonne position
    
    //float rad=lastShooter.Aim(angledeg);
    rad=angledeg*PI/180;
    //cout<<"conversion de deg a rad= "<< rad<<endl;
    
    
    float deltax= (positionX - (positionInitiale.x));
    double positionY = ((g * deltax * deltax) / (2 * V0 * V0 * pow(cos(rad), 2)) + deltax * tan(rad)) + positionInitiale.y;
    //bulletEndPosition.y=round(positionY;
    
    return round(positionY);
}

int Projectile::findBulletPositionX(int positionY){
    //float V0=VITESSEMAX*puissance;
    V0=puissance*getProjectileMaxSpeed();
    
    //cout<<"Vitesse V0 trouvé: "<<V0<<endl;
    //j'ai remplacer les hitbox.width pour =100
    //j'ai remplacer les hitbox.height pour =100
    int positionX=0;
    //Coordonnee playerPosition =lastShooter.getPosition();
    Coordonnee projectileStartPosition =positionInitiale;
    cout<<"VA CHIERFIRST("<<positionInitiale.x<<", "<<positionInitiale.y<<")"<<endl;
    cout<<"Départ projectile: ("<<projectileStartPosition.x<< ", "<<projectileStartPosition.y<<")"<<endl;//détecte la bonne position
    //float rad=lastShooter.Aim(angledeg);
    rad=angledeg*PI/180;
    //cout<<"conversion de deg a rad= "<< rad<<endl;
    //float rad=angledeg;
    float deltay=( positionY-projectileStartPosition.y);
    float numeratorx1 = -tan(rad) + sqrt(pow(tan(rad), 2) - ((2 * g) / (pow(V0, 2) * pow(cos(rad), 2))) * -1*deltay);
    float numeratorx2 = -tan(rad) - sqrt(pow(tan(rad), 2) - ((2 * g) / (pow(V0, 2) * pow(cos(rad), 2))) * -1*deltay);
    float denominator = g / (pow(V0, 2) * pow(cos(rad), 2));

    float positionX1=(numeratorx1/denominator)+positionInitiale.x;
    float positionX2=(numeratorx2/denominator)+positionInitiale.x;
    cout<<"positionX1: "<<positionX1<<endl;
    cout<<"positionX2: "<<positionX2<<endl;
    if(positionX1>=0 &&positionX1>positionX2)
    {
        //bulletEndPosition.x=round(positionX1);
        positionX= round(positionX1);
        cout<<"premier if dans findBulletPositionX"<<endl;
    }
    if(positionX2>=0 && positionX2>positionX1){
        //bulletEndPosition.x=round(positionX2);
        positionX=round(positionX2);
        cout<<"deuxième if dans findBulletPositionX"<<endl;
    }
    //cout<<"positonX: "<<positionX<<endl;
    return positionX;
}
// au lieu de passer cela en paramètre, puissance
bool Projectile::checkIfCharacterHit(Character& character){
    //peut-etre mettre sa hitbox en paramêtre
    //playerShoot(forceX, forceY);

    //ligne noir  


    Coordonnee characterPosition =character.getPosition();
    cout<<"position du PERSONNAGE (la cible): ("<<characterPosition.x<< ", "<<characterPosition.y<<")"<<endl;//détecte la bonne position
    // int impactX = findBulletPositionX(characterPosition.y);
    // int impactY = findBulletPositionY(characterPosition.x);
    // cout<<"coordonnée impact: ("<<impactX<< ", "<<impactY<<")"<<endl;
    //si la position en x (quand y=0 est< que la position en x des ennemy)
    cout<< findBulletPositionX(characterPosition.y)<<endl;
    if( findBulletPositionX(characterPosition.y)<characterPosition.x && findBulletPositionY(characterPosition.x)<100){
        //on sait qu'il n'a pas toucher directement l'ennemie
        //pour les coordonnées de la balle, ce sera a changé éventuellement
        cout<<findBulletPositionX(characterPosition.y)<<" < "<<characterPosition.x<<endl;
        bulletEndPosition.x=findBulletPositionX(100);
        bulletEndPosition.y=100;
        cout<<"Premier if"<<endl;
        
        //character
        return false;
    }
        //&&findBulletPositionX(characterPosition.y)>=characterPosition.x
    //ligne bleu
    else if(findBulletPositionY(characterPosition.x)<=(characterPosition.y+character.getHitboxHeight()))    
    {
        //on sait qu'il a toucher a la position du projectile en Y
        bulletEndPosition.x=characterPosition.x;
        bulletEndPosition.y=findBulletPositionY(characterPosition.x);
        cout<<"Premier else if"<<endl;
        //charater.takeDamage(this) LE CHANGER POUR ÇA QUAND ON VA METTRE LA MÉTHODE DANS PROJECTILE
        
        //character.setHealthPoint(character.getHealthPoint()- damageReceived(character.getProjectileType(), impactX, impactY));
        
        //character.damageReceived(this, impactX,impactY);
        return true;
    }

    else if(findBulletPositionY(characterPosition.x+character.getHitboxWidth())>(characterPosition.y+character.getHitboxHeight()))
    {   //on sait qu'il ne touchera pas l'ennemie directement (passer par dessus l'ennemie)
        //pour les coordonnées de la balle, ce sera a changé éventuellement
        bulletEndPosition.x=findBulletPositionX(100);
        bulletEndPosition.y=100;
        cout<<"Deuxième else if"<<endl;
        return false;
    }
    else if(findBulletPositionY(characterPosition.x+character.getHitboxWidth())==(characterPosition.y+character.getHitboxHeight()))
    {
        //on sait qu'il a touché l'ennemie sur le coin supérieur droit
        bulletEndPosition.x=characterPosition.x+character.getHitboxWidth();
        bulletEndPosition.y=findBulletPositionY(characterPosition.x+character.getHitboxWidth());
        
        //character.setHealthPoint(character.getHealthPoint()- damageReceived(character.getProjectileType(), impactX, impactY));
        cout<<"Troisième else if"<<endl;
        //character.damageReceived(this, impactX,impactY);
        return true;
    }
    else if(findBulletPositionY(characterPosition.x+character.getHitboxWidth())<(characterPosition.y+character.getHitboxHeight()))
    {
        bulletEndPosition.x=findBulletPositionX(characterPosition.y+character.getHitboxHeight());
        bulletEndPosition.y=characterPosition.y+character.getHitboxHeight(); //damageMultiplier(int impactY)
        //character.setHealthPoint(character.getHealthPoint()- damageReceived(character.getProjectileType(), impactX, impactY));
        //character.damageReceived(this, impactX,impactY);
        cout<<"Quatrième else if"<<endl;
        return true;
    }
        
    else{
        //théoriquement rien passe dans le false, mais je le garde pour le déboguage 
        //pour les coordonnées de la balle, ce sera a changé éventuellement
        bulletEndPosition.x=findBulletPositionX(100);
        bulletEndPosition.y=100;
        cout<<"Else"<<endl;
        return false;
    }
}

float Projectile::damageReceived(Projectile& projectile, Character& character )// a changer pour int le type de retour
{
//APPELER LA FONCTION MÊME QUAND IL NE TOUCHE PAS DIRECTEMENT?
    
    float directDamage = 0.0;
    float explosionDamage = 0.0;//à tunner également
    if(typeid(projectile) == typeid(Canonball) && (character.getPosition().x==bulletEndPosition.x || character.getPosition().y==bulletEndPosition.y) )
    {
        directDamage = 1*damageMultiplier(bulletEndPosition.y);
    }
    if(typeid(projectile) == typeid(Grenade))
    {
        if((character.getPosition().x==bulletEndPosition.x || character.getPosition().y==bulletEndPosition.y))
        {
            directDamage=0.5*damageMultiplier(bulletEndPosition.y);
        }
        
        double distanceToImpact = sqrt((character.getPosition().x - bulletEndPosition.x * (character.getPosition().x - bulletEndPosition.x) +                              (character.getPosition().y - bulletEndPosition.y) * (character.getPosition().y - bulletEndPosition.y)));
        
        if(distanceToImpact >30)//40 px
        {
            explosionDamage=0;
        }
            
        else
        {
            explosionDamage = int(3 - distanceToImpact / 10.0);// 3 est la valeur max de dégat d'explosion
        }

    }
    if(typeid(projectile) == typeid(Rocket) && (character.getPosition().x==bulletEndPosition.x || character.getPosition().y==bulletEndPosition.y))
    {
        directDamage=4*damageMultiplier(bulletEndPosition.y);
    }
    return directDamage + explosionDamage;//multiplier cela par la norme du vecteur vitesse quand il touche le gars
}

float Projectile::damageMultiplier(int impactY){
    int  damageMultiplier = 1.0;  // Facteur de dommage a tunner


    if (impactY < bulletEndPosition.y + 100 / 3.0) 
    {
        return damageMultiplier = 1.0;  
    } else if (impactY < bulletEndPosition.y + 2.0 * 100 / 3.0) 
    {
        return damageMultiplier = 2.0;  
    } 
    else 
    {
        return damageMultiplier = 4.0;  
    }
}
Coordonnee Projectile::getBulletEndPosition(){
    return bulletEndPosition;
}
