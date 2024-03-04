#ifndef BOAT_H
#define BOAT_H

#include <ostream>
#include "character.h"
#include "../Vecteur.h"
#include "utility.h"

using namespace std;

class Boat
{
public:
    Vecteur<Character *> characters;

    Boat(int n, int posx, int posy);
    ~Boat();

    int getNbCharacters();
    int getCapacite();
    Coordonnee getPositionBoat();
    bool addCharacter(Character *characterAdded);
    bool removeCharacters(int index);
    void ShowInfo(ostream &s);

private:
    int nbCharacters;
    int capacite;
    Coordonnee positionBoat;
};

#endif