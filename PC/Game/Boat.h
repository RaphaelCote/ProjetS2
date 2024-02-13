#ifndef BOAT_H
#define BOAT_H

#include <ostream>
#include "charachters.h"

using namespace std;

class Boat
{
public:
    Boat(int n);
    ~Boat();
    int getNbCharacters();
    int getCapacite();
    bool addCharacter(Character* characterAdded);
    list<Vector*> characterPositions;
    list<Characters*> characters;
    Character* removeCharacters(int index);
    removePosition(int index);
    void affichageJoueur(ostream & s);
    void affichageAdversaire(ostream & s);

private:
    int nbCharacters;
    int capacite;

};

#endif