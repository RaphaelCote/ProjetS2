#ifndef BOAT_H
#define BOAT_H

#include <ostream>
#include "charachters.h"
#include "../Vecteur.h"
#include "Coordonnees.h"

using namespace std;

class Boat
{
public:
    Boat(int n);
    ~Boat();
    int getNbCharacters();
    int getCapacite();
    bool addCharacter(character* characterAdded);
    bool addPosition(Coordonnee* positionAdded);
    Vecteur<Coordonnee*> characterPositions;
    Vecteur<character*> characters;
    bool removeCharacters(int index);
    bool removePosition(int index);
    void affichageJoueur(ostream & s);
    void affichageAdversaire(ostream & s);

private:
    int nbCharacters;
    int capacite;
};

#endif