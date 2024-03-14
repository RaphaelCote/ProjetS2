#ifndef NIVEAU_H
#define NIVEAU_H

#include "../vecteur.h"
#include "character.h"
#include "Boat.h"

class Niveau
{
public:
    int height = 1080;
    int width = 3000;
    Vecteur<Boat *> playerBoats;
    Vecteur<Boat *> enemyBoats;

    int backimge;

    Niveau();
    Niveau(int width, int height, int image);
    ~Niveau();

    void ShowLevelInfo(ostream &s);
    void addRaftPlayer(int width, int height, int posX, int posY, int image, int capacite);
    void addRaftenemy(int width, int height, int posX, int posY, int image, int capacite);
};

#endif