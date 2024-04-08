#include "Boat.h"
#include "character.h"

Boat::Boat(int n, Coordonnee position, int height, int width, int image)
{
    nbCharacters = 0;
    capacite = n;
    positionBoat = position;
    heightBoat = height;
    widthBoat = width;
    hitBoxBoat.height = height;
    hitBoxBoat.width = width;
    imageboat = image;
}

int Boat::getNbCharacters() // pour vérifier s'il reste des personnages vivants
{
    return characters.size();
}

int Boat::getCapacite()
{
    return characters.capacity();
}

Coordonnee Boat::getPositionBoat()
{
    return positionBoat;
}

int Boat::getHeight()
{
    return heightBoat;
}

int Boat::getWidth()
{
    return widthBoat;
}

int *Boat::getPointerPositionBoat_X()
{
    return &(positionBoat.x);
}

int *Boat::getPointerPositionBoat_Y()
{
    return &(positionBoat.y);
}

Hitbox Boat::getHitboxBoat()
{
    return hitBoxBoat;
}

bool Boat::addCharacter(Character *characterAdded) // pour initialiser le jeu: créer les personnages
{
    nbCharacters++;
    characters.push_back(characterAdded);
    return true;
}

bool Boat::removeCharacters(int index) // retirer les personnages lorsqu'ils sont morts
{
    nbCharacters--;
    characters.erase(characters.begin() + index);
    return true;
}

void Boat::ShowInfo(std::ostream &s)
{
    s << "Position du bateau : (" << positionBoat.x << "," << positionBoat.y << ")" << std::endl;

    for (int i = 0; i < characters.size(); i++)
    {
        s << "Personnage " << i + 1 << " :" << std::endl;
        characters[i]->ShowInfo();
    }
}

Boat::~Boat()
{
    nbCharacters = 0;
}