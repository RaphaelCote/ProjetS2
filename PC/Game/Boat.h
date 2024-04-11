#ifndef BOAT_H
#define BOAT_H

#include <ostream>
#include <vector>
#include "character.h"
#include "utility.h"


class Boat
{
public:
    Boat(int n, Coordonnee position, int height, int width, std::string image);
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

    std::string imageboat;

private:
    int nbCharacters;
    int capacite;
    
    int widthBoat;
    int heightBoat;
    Coordonnee positionBoat;
    Hitbox hitBoxBoat;
};

#endif