#ifndef NIVEAU_H
#define NIVEAU_H

#include "../vecteur.h"
#include "character.h"

class Niveau
{
private:
    int nbraft;
    Vecteur<Character *> characters;

public:
    Niveau();
    Niveau(int);
    ~Niveau();
    int hight = 1080;
    int wight = 3000;

    int backimge[1];
    void creerListeRaft();
};

#endif