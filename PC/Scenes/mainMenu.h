#ifndef MAINMENU_H
#define MAINMENU_H

#include "menu.h"

using namespace std;

class MainMenu : public Menu
{
    friend void OnMainMenuMainActionCall(EventParameters);
    friend void OnMainMenuJoystickCall(EventParameters);

    void OnEnable();
    void OnDisable();

    void changeSelection(EventParameters ep);
    void ShowMenu();
    void Selection();
};

#endif