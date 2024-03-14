#ifndef NIVEAU_H
#define NIVEAU_H

#include "../vecteur.h"
#include "character.h"
#include "Boat.h"

class Niveau
{
public:
    Niveau();
    Niveau(int width, int height, int image);
    ~Niveau();

    int heightlevels = 1080;
    int widthlevels = 3000;
    Vecteur<Character *> characters;
    Vecteur<Boat *> playerBoats;
    Vecteur<Boat *> enemyBoats;

    int backimge;

    void initializeBoats();
    void ShowCharacterInfo(ostream &s);
    void addRaftPlayer(int width, int height, int posX, int posY, int image, int capacite, int i);
    void addRaftenemy(int width, int height, int posX, int posY, int image, int capacite, int i);
};

#endif