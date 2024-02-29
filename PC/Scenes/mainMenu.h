#ifndef MAINMENU_H
#define MAINMENU_H

#include "menu.h"

using namespace std;

class MainMenu : public Menu
{
    friend void OnMenuMainActionCall(EventParameters);
    friend void OnMenuJoystickCall(EventParameters);

    void OnEnable();
    void OnDisable();

    void changeSelection(EventParameters ep);
    void ShowMenu();
    bool Selection();
};

#endif