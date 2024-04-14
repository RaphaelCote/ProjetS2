#ifndef INVENTORY_H
#define INVENTORY_H
#include "../Scenes/shopMenu.h"
#include <iostream>

#define PRIXPETITSHIELD 200
#define PRIXMOYENSHIELD 300
#define PRIXGROSSHIELD 500
#define PRIXROCKET 100
#define PRIXGRENADE 200

class Inventory : public ShopMenu
{
public:
    Inventory(ShopMenuQt* shopMenu);

    int GetPrixRocket();
    int GetPrixGrenade();
    int GetPrixShieldSmall();
    int GetPrixShieldMedium();
    int GetPrixShieldBig();

    int getGold();
    void addGold(int Gold);
    void removeGold(int Gold);

    int getRockets();
    void addRockets();
    void removeRockets();

    int getShield();
    void setShield(int Shield);
    void addShield(int level);

    int getGrenade();
    void addGrenade();
    void removeGrenade();

private:
    int nbRockets;
    int nbGrenades;
    int shield;
    int gold;
};

extern Inventory* inventory;

#endif