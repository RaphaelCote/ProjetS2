#ifndef NIVEAU_H
#define NIVEAU_H

#include "../vecteur.h"
#include "character.h"
#include "Boat.h"


class Niveau
{
public:
    Niveau();
    ~Niveau();

    int height = 1080;
    int weight = 3000;
    Vecteur<Character *> characters;
    Vecteur<Boat *> playerBoats;
    Vecteur<Boat *> enemyBoats;

    int backimge[1];

    void initializeBoats();
    void ShowCharacterInfo(ostream &s);
};

#endif