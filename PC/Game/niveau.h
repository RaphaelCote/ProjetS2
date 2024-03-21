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
    int backimge;
    Vecteur<Character *> characters;
    Vecteur<Boat *> playerBoats;
    Vecteur<Boat *> enemyBoats;

    void ShowLevelInfo(ostream &s);
    void ShowNiveauinfo();
    void addRaftPlayer(int width, int height, Coordonnee position, int image, int capacite);
    void addRaftenemy(int width, int height, Coordonnee position, int image, int capacite);
    void MatRaft();
    void MatPlayer();
    void MatEnemy();
    void MatWater();
    void MatBalle();
    void MatGrenade();
    void MatRocket();
    void MatNuage();
};

#endif