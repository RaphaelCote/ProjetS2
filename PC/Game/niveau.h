#ifndef NIVEAU_H
#define NIVEAU_H

#include "../vecteur.h"
#include "character.h"
#include "Boat.h"
#include "../Affichage/AffichageConsole.h"
#include "../raftWars.h"

class Niveau
{
public:
    Niveau();
    Niveau(int width, int height, int image);
    ~Niveau();

    int height = 1080;
    int width = 3000;
    Vecteur<Character *> characters;
    Vecteur<Boat *> playerBoats;
    Vecteur<Boat *> enemyBoats;

    int backimge[1];

    void initializeBoats();
    void ShowCharacterInfo(ostream &s);
    void addRaftPlayer(int width, int height, int posX, int posY, int image, int capacite, int i);
    void addRaftenemy(int width, int height, int posX, int posY, int image, int capacite, int i);
    void MatRaft();
    void MatPlayer();
    void MatEnemy();
    void MatWater();
    void MatBalle();
    void MatGrenade();
    void MatRocket();
    void MatNuage();

    private:

    

};

#endif