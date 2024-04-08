#ifndef BOAT_H
#define BOAT_H

#include <ostream>
#include "character.h"
#include "utility.h"


class Boat
{
public:
    Boat(int n, Coordonnee position, int height, int width, int image);
    std::vector<Character *> characters;

    ~Boat();

    int getNbCharacters();
    int getCapacite();
    Coordonnee getPositionBoat();
    int getHeight();
    int getWidth();
    int *getPointerPositionBoat_X();
    int *getPointerPositionBoat_Y();
    Hitbox getHitboxBoat();
    bool addCharacter(Character *characterAdded);
    bool removeCharacters(int index);
    void ShowInfo(std::ostream &s);

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