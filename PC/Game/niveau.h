#ifndef NIVEAU_H
#define NIVEAU_H

#include "../vecteur.h"
#include "character.h"

class Niveau
{
private:
    int nbraft;

public:
    Niveau();
    Niveau(int);
    ~Niveau();

    int height = 1080;
    int weight = 3000;
    Vecteur<Character *> characters;

    int backimge[1];

    void creerListeRaft();
    void ShowCharacterInfo();
};

#endif