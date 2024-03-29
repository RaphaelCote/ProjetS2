#ifndef NIVEAU_H
#define NIVEAU_H

#include "../vecteur.h"
#include "character.h"
#include "projectile.h"
#include "Boat.h"

class Niveau
{
private:
    int heightlevels;
    int widthlevels;
    int backimge;

public:
    int height = 1080;
    int width = 3000;
    Vecteur<Boat *> playerBoats;
    Vecteur<Boat *> enemyBoats;

    Niveau();
    Niveau(int width, int height, int image);
    ~Niveau();

    void ShowLevelInfo(ostream &s);
    void ShowNiveauinfo();
    void addRaftPlayer(int width, int height, Coordonnee position, int image, int capacite);
    void addRaftenemy(int width, int height, Coordonnee position, int image, int capacite);
    void MatRaft();
    void MatEnemy();
    void MatWater();
    void MatBalle(Projectile *pro);
    void MatRocket(Projectile *pro);
    void MatGrenade(Projectile *Grenade);
    void MatNuage();
    void MatCharacter();
    void Delete();
};

#endif