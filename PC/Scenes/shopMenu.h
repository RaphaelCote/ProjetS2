#ifndef SHOP_H
#define SHOP_H
#include <iostream>
#include <string>
#include "../Controls/EventParameters.h"
#include "../Controls/EventListener.h"
#include "menu.h"


class ShopMenu : public Menu
{

public:
    int lastMenu = 0;

    friend void OnShopMainActionCall(EventParameters);
    friend void OnShopJoystickCall(EventParameters);
    friend void OnShopBackCall(EventParameters);

    void OnEnable();
    void OnDisable();

    ShopMenu();
    void changeSelection(EventParameters ep);
    void Update();
    void ShowMenu();
    void ClearMenu();
    void Selection();

    void Back();
};

#endif