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
    Boat(int n, int posx, int posy);
    ~Boat();
    int getNbCharacters();
    int getCapacite();
    Coordonnee getPositionBoat();
    bool addCharacter(Character* characterAdded);
    bool addPosition(Coordonnee* positionAdded);
    Vecteur<Coordonnee*> characterPositions;
    Vecteur<Character*> characters;
    bool removeCharacters(int index);
    bool removePosition(int index);
    void affichageJoueur(ostream & s);
    void affichageAdversaire(ostream & s);

private:
    int nbCharacters;
    int capacite;
    Coordonnee positionBoat;
};

#endif