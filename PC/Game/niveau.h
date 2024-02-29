#ifndef NIVEAU_H
#define NIVEAU_H

#include "../vecteur.h"
#include "character.h"

class Niveau
{
private:


public:
    Niveau();
    Niveau(int,int,int);
    ~Niveau();

    int height;
    int width;
    Vecteur<Character *> characters;

    int backimge[1];

    void creerListeRaft();
    void ShowCharacterInfo();
};

#endif