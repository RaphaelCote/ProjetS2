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
    friend void OnShopMainActionCall(EventParameters);
    friend void OnShopJoystickCall(EventParameters);

    void OnEnable();
    void OnDisable();

    shop();
    void changeSelection(EventParameters ep);
    void Update();
    void ShowMenu();
    void Selection();

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