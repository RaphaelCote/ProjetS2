#include "Boat.h"
#include "character.h"


Boat::Boat()
{
    
}

Boat::Boat(int n, int posx, int posy)
{
    nbCharacters = 0;
    capacite = n;
    positionBoat.x = posx;
    positionBoat.y = posy;
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