#ifndef NIVEAU_H
#define NIVEAU_H

#include "character.h"
#include "projectile.h"
#include "Boat.h"
#include <vector>
#include <string>

class Niveau
{
private:
    

public:
    int heightlevels;
    int widthlevels;
    std::string backimge;

    int height = 1080;
    int width = 3000;
    std::vector<Boat *> playerBoats;
    std::vector<Boat *> enemyBoats;

    Niveau();
    Niveau(int width, int height, std::string image);
    ~Niveau();

    void ShowLevelInfo(std::ostream &s);
    void ShowNiveauinfo();
    void addRaftPlayer(int width, int height, Coordonnee position, std::string image, int capacite);
    void addRaftenemy(int width, int height, Coordonnee position, std::string image, int capacite);
    void MatRaft();
    void RaftQt();
    void MatEnemy();
    void MatWater();
    void MatBalle(Projectile *pro);
    void MatRocket(Projectile *pro);
    void MatGrenade(Projectile *Grenade);
    void BalleQt(Projectile* pro);
    void RocketQt(Projectile* pro);
    void GrenadeQt(Projectile* pro);
    void ExplosionQt(Projectile* pro);
    void AxeQt(Projectile* pro);
    void MatNuage();
    void MatCharacter();
    void CharacterQt();
    void BackgroundQt();
    void UpdateHealthQt();
    void RemoveItemQt(std::string name);
    void Delete();
};

#endif