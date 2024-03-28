#include "Boat.h"
#include "character.h"

Boat::Boat(int n, Coordonnee position, int height, int width, int image)
{
    nbCharacters = 0;
    capacite = n;
    positionBoat = position;
    heightBoat = height;
    widthBoat = width;
    imageboat = image;
    Hitbox boatHitbox;
    boatHitbox.width = width;
    boatHitbox.height = height;
    hitboxes.add(&boatHitbox);
}

int Boat::getNbCharacters() // pour vérifier s'il reste des personnages vivants
{
    return characters.getSize();
}

int Boat::getCapacite()
{
    return characters.getCapacity();
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
    return characters.add(characterAdded);
}

bool Boat::removeCharacters(int index) // retirer les personnages lorsqu'ils sont morts
{
    nbCharacters--;
    return characters.remove(index);
}

void Boat::ShowInfo(ostream &s)
{
    s << "Position du bateau : (" << positionBoat.x << "," << positionBoat.y << ")" << endl;

    for (int i = 0; i < characters.getSize(); i++)
    {
        s << "Personnage " << i + 1 << " :" << endl;
        characters[i]->ShowInfo();
    }
}

Boat::~Boat()
{
    nbCharacters = 0;
}