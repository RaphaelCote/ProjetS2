// projectile.cpp
#include "projectile.h"

Projectile::Projectile(Character &character)
{
    angleRotationProjectile = 0;
    angledeg = 0;
    puissance = 0;
    V0 = 0;
    this->bulletStartPosition.x = character.getWeaponPosition().x;
    this->bulletStartPosition.y = character.getWeaponPosition().y;
    this->hitbox = {1, 1};
}

Projectile::Projectile(Coordonnee bulletStartPosition)
{
    angleRotationProjectile = 0;
    angledeg = 0;
    puissance = 0;
    V0 = 0;
    this->bulletStartPosition.x = bulletStartPosition.x;
    this->bulletStartPosition.y = bulletStartPosition.y;
    this->bulletCurrentPosition.x = bulletStartPosition.x;
    this->bulletCurrentPosition.y = bulletStartPosition.y;
    this->hitbox = {1, 1};
}

Projectile::Projectile(Coordonnee bulletStartPosition, Hitbox hitboxset)
{
    angleRotationProjectile = 0;
    angledeg = 0;
    puissance = 0;
    V0 = 0;
    this->bulletStartPosition = bulletStartPosition;
    this->bulletCurrentPosition = bulletStartPosition;
    this->hitbox = hitboxset;
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
    // une grenade explose après 3 secondes donc entré 3 sec en paramètre
    rad = angledeg * PI / 180;
    // std::cout<<"radian: "<<rad<<std::endl;
    V0 = puissance * getProjectileMaxSpeed();
    // std::cout<<"V0 :"<<V0<<std::endl;
    float num = std::pow((g * time + V0 * std::sin(rad)), 2) - std::pow((V0 * std::sin(rad)), 2);
    float denum = 2.0f * g;
    int positionfinaleY = std::round(num / denum + bulletStartPosition.y);
    // std::cout<<"Position finale y avant condition: "<<positionfinaleY<<std::endl;
    return positionfinaleY;
}
int Projectile::findBulletPositionY(int positionX)
{
    V0 = puissance * getProjectileMaxSpeed();

    rad = angledeg * PI / 180;

    float deltax = (positionX - (bulletStartPosition.x));
    double positionY = ((g * deltax * deltax) / (2 * V0 * V0 * std::pow(std::cos(rad), 2)) + deltax *std::tan(rad)) + bulletStartPosition.y;

    return std::round(positionY);
}

int Projectile::findBulletPositionX(int positionY)
{
    V0 = puissance * getProjectileMaxSpeed();
    int positionX = 0;

    rad = angledeg * PI / 180;
    // std::cout<<"conversion de deg a rad= "<< rad<<std::endl;
    // float rad=angledeg;
    float deltay = (positionY - bulletStartPosition.y);
    float numeratorx1 = -std::tan(rad) + sqrt(std::pow(std::tan(rad), 2) - ((2 * g) / (std::pow(V0, 2) * std::pow(std::cos(rad), 2))) * -1 * deltay);
    float numeratorx2 = -std::tan(rad) - sqrt(std::pow(std::tan(rad), 2) - ((2 * g) / (std::pow(V0, 2) * std::pow(std::cos(rad), 2))) * -1 * deltay);
    float denominator = g / (std::pow(V0, 2) * std::pow(std::cos(rad), 2));

    float positionX1 = (numeratorx1 / denominator) + bulletStartPosition.x;
    float positionX2 = (numeratorx2 / denominator) + bulletStartPosition.x;
    // SI l'angle est négatif, faire un autre code, sinon prendre lui qu'on a live
    // std::cout<<"positionX1: "<<positionX1<<std::endl;
    // std::cout<<"positionX2: "<<positionX2<<std::endl;
    if (angledeg > 0)
    {
        if (positionX1 >= 0 && positionX1 > positionX2)
        {
            positionX = std::round(positionX1);
        }
        if (positionX2 >= 0 && positionX2 > positionX1)
        {
            positionX = std::round(positionX2);
        }
    }
    if (angledeg < 0)
    {

        if (positionX1 < positionX2)
        {
            positionX = std::round(positionX1);
        }
        if (positionX2 < positionX1)
        {
            positionX = std::round(positionX2);
        }
    }

    return positionX;
}

bool Projectile::checkIfCharacterHit(Character& character)
{

    Coordonnee characterPosition = character.getPosition();
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
            // std::cout<<"Premier if angle positif"<<std::endl;

            // il va falloir modifier cette condition (si elle touche le bateau ou non)
            bulletEndPosition.x = findBulletPositionX(characterPosition.y);
            bulletEndPosition.y = characterPosition.y;
            damageReceived(character);
            return false;
        }
        else if (findBulletPositionY(characterPosition.x) <= (characterPosition.y + character.getHitboxHeight()))
        {
            // on sait qu'il a toucher a la position du projectile en X
            // std::cout<<"Premier else if angle positif"<<std::endl;
            bulletEndPosition.x = characterPosition.x;
            bulletEndPosition.y = findBulletPositionY(characterPosition.x);
            damageReceived(character);
            return true;
        }
        else if (findBulletPositionY(characterPosition.x + character.getHitboxWidth()) > (characterPosition.y + character.getHitboxHeight()))
        { // on sait qu'il ne touchera pas l'ennemie directement (passer par dessus l'ennemie)
            // pour les coordonnées de la balle, ce sera a changé éventuellement (vérifier si cela a touché bateau ou l'eau)
            // std::cout<<"Deuxième else if angle positif"<<std::endl;

            // il va falloir modifier cette condition (si elle touche le bateau ou non)
            bulletEndPosition.x = findBulletPositionX(characterPosition.y);
            bulletEndPosition.y = characterPosition.y;
            damageReceived(character);
            return false;
        }
        else if (findBulletPositionY(characterPosition.x + character.getHitboxWidth()) == (characterPosition.y + character.getHitboxHeight()))
        {
            // on sait qu'il a touché l'ennemie sur le coin supérieur droit
            // std::cout<<"Troisième else if angle positif"<<std::endl;
            bulletEndPosition.x = characterPosition.x + character.getHitboxWidth();
            bulletEndPosition.y = findBulletPositionY(characterPosition.x + character.getHitboxWidth());
            damageReceived(character);
            return true;
        }
        else if (findBulletPositionY(characterPosition.x + character.getHitboxWidth()) <= (characterPosition.y + character.getHitboxHeight()))
        {
            // on sait qu'il a touché l'ennemie entre son coin supérieur gauche et supérieur droit excluant
            // std::cout<<"Quatrième else if angle positif"<<std::endl;
            bulletEndPosition.x = findBulletPositionX(characterPosition.y + character.getHitboxHeight());
            bulletEndPosition.y = characterPosition.y + character.getHitboxHeight();
            damageReceived(character);
            return true;
        }
        else
        {
            // std::cout<<"Else angle positif"<<std::endl;
            // THÉORIQUEMENT rien passe dans le false, mais je le garde pour le déboguage

            bulletEndPosition.x = findBulletPositionX(characterPosition.y);
            bulletEndPosition.y = characterPosition.y;
            damageReceived(character);
            return false;
        }
    }
    if (angledeg < 0)
    {
        if (findBulletPositionX(characterPosition.y) > characterPosition.x + character.getHitboxWidth() && findBulletPositionY(characterPosition.x + character.getHitboxWidth()) < characterPosition.y)
        {
            // on sait qu'il n'a pas toucher directement l'ennemie
            // pour les coordonnées de la balle, ce sera a changé éventuellement (vérifier si cela a touché bateau ou l'eau)
            // std::cout<<"Premier if angle négatif"<<std::endl;
            bulletEndPosition.x = findBulletPositionX(characterPosition.y);
            bulletEndPosition.y = characterPosition.y;
            damageReceived(character);
            return false;
        }
        else if (findBulletPositionY(characterPosition.x + character.getHitboxWidth()) <= (characterPosition.y + character.getHitboxHeight()))
        {
            // on sait qu'il a toucher a la position du projectile en X
            // std::cout<<"Premier else if angle négatif"<<std::endl;
            bulletEndPosition.x = characterPosition.x + character.getHitboxWidth();
            bulletEndPosition.y = findBulletPositionY(characterPosition.x + character.getHitboxWidth());
            damageReceived(character);

            return true;
        }
        else if (findBulletPositionY(characterPosition.x) > (characterPosition.y + character.getHitboxHeight()))
        { // on sait qu'il ne touchera pas l'ennemie directement (passer par dessus l'ennemie)
            // pour les coordonnées de la balle, ce sera a changé éventuellement (vérifier si cela a touché bateau ou l'eau)
            // std::cout<<"Deuxième else if angle négatif"<<std::endl;
            bulletEndPosition.x = findBulletPositionX(characterPosition.y);
            bulletEndPosition.y = characterPosition.y;
            damageReceived(character);
            return false;
        }
        else if (findBulletPositionY(characterPosition.x) == (characterPosition.y + character.getHitboxHeight()))
        {
            // on sait qu'il a touché l'ennemie sur le coin supérieur droit
            // std::cout<<"Troisième else if angle négatif"<<std::endl;
            bulletEndPosition.x = characterPosition.x;
            bulletEndPosition.y = findBulletPositionY(characterPosition.x);
            damageReceived(character);
            return true;
        }
        else if (findBulletPositionY(characterPosition.x) <= (characterPosition.y + character.getHitboxHeight()))
        {
            // on sait qu'il a touché l'ennemie entre son coin supérieur gauche et supérieur droit excluant
            // std::cout<<"Quatrième else if angle négatif"<<std::endl;
            bulletEndPosition.x = findBulletPositionX(characterPosition.y + character.getHitboxHeight());
            bulletEndPosition.y = characterPosition.y + character.getHitboxHeight();
            damageReceived(character);
            return true;
        }
        else
        {
            // std::cout << "Else angle négatif" << std::endl;
            // THÉORIQUEMENT rien passe dans le false, mais je le garde pour le déboguage

            bulletEndPosition.x = findBulletPositionX(characterPosition.y);
            bulletEndPosition.y = characterPosition.y;
            damageReceived(character);
            return false;
        }
    }
}

void Projectile::checkIfCharactersHit(std::vector<Character*> characters) {
    for (int i = 0; i < characters.size(); i++)
    {
        if (checkIfCharacterHit(*(characters[i]))) {
            return;
        }
    }
}

Coordonnee Projectile::getBulletEndPosition()
{
    return bulletEndPosition;
}
