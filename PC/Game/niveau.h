#ifndef NIVEAU_H
#define NIVEAU_H

#include "../vecteur.h"
#include "character.h"
#include "Boat.h"

class Niveau
{
private:
    int heightlevels;
    int widthlevels;
    int backimge;
public:
    Niveau();
    Niveau(int width, int height, int image);
    ~Niveau();

  
    Vecteur<Character *> characters;
    Vecteur<Boat *> playerBoats;
    Vecteur<Boat *> enemyBoats;

    

    void initializeBoats();
    void ShowCharacterInfo(ostream &s);
    void ShowNiveauinfo();
    void addRaftPlayer(int width, int height, Coordonnee position, int image, int capacite, int i);
    void addRaftenemy(int width, int height, Coordonnee position, int image, int capacite, int i);
};

#endif