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
    Boat(int n, Coordonnee position, int height, int width, int image);
    Vecteur<Character *> characters;

    
    ~Boat();

    int getNbCharacters();
    int getCapacite();
    Coordonnee getPositionBoat();
    int* getPointerPositionBoat_X();
    int* getPointerPositionBoat_Y();
    Hitbox getHitboxBoat();
    int getHeight();
    int getWidth();
    bool addCharacter(Character *characterAdded);
    bool removeCharacters(int index);
    void ShowInfo(ostream &s);

    
    

private:
    int nbCharacters;
    int capacite;
    int imageboat;
    int widthBoat;
    int heightBoat;
    Coordonnee positionBoat;
    Hitbox hitBoxBoat;
    
};

#endif