#ifndef SHOP_H
#define SHOP_H
#include <iostream>
#include <string>
#include "../Controls/EventParameters.h"
#include "../Controls/EventListener.h"
#include "menu.h"

using namespace std;

class shop : public Menu
{

public:
    shop();
    friend void OnShopActionCall(EventParameters);
    friend void OnShopJoystickCall(EventParameters);

    void OnEnable();
    void OnDisable();

    void changeSelection(EventParameters ep);
    void menuController(int menu);
    void afficherShop();
    void selectionShop();
    void afficherInventaire();

private:
    int choix = 0;
    int lastActiveMenu = 0;
    int nbRoquettes = 0;
    int nbGrenades = 0;
    int nbShield = 0;
    int money = 0;
};

#endif