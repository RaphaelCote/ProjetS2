#ifndef NIVEAU_H
#define NIVEAU_H

#include "../vecteur.h"
#include "Boat.h"

class Niveau
{
private:


public:

    Niveau(int width,int height,int image);
    ~Niveau();

    int heightlevels;
    int widthlevels;
    Vecteur<Boat *> boat;

    int backimage;

    void creerListeRaft();
    void ShowCharacterInfo();
    void addRaft(int raftwidth, int raftheight,int corodoneeX,int corodoneeY,int imageraft, int capacite, int nbDuBateau);
};

#endif