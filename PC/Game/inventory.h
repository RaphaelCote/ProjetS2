#ifndef INVENTORY_H
#define INVENTORY_H
#include "../Scenes/shopMenu.h"
#include <iostream>

using namespace std;
#define PrixPetitShield 200
#define PrixMoyenShield 300
#define PrixGrosShield 500
#define PrixRocket 100
#define PrixGrenade 200


class Inventory: public ShopMenu
{
    public:
        Inventory();

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

#endif