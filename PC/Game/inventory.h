#ifndef INVENTORY_H
#define INVENTORY_H
#include "Scenes/shopMenu.h"
#include <iostream>

using namespace std;

class Inventory: public ShopMenu
{
    public:
    private:
        int nbRoquettes = 0;
        int nbGrenades = 0;
        int nbShield = 0;
        int nbLittleShield = 0;
        int nbMidShield = 0;
        int nbBigShield = 0;
        int money = 0;
};

#endif