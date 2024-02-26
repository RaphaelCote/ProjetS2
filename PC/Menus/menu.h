#ifndef MAINMENU_H
#define MAINMENU_H
#include <iostream>
#include <string>
#include "../Controls/EventParameters.h"
#include "../Controls/EventListener.h"

using namespace std;

class Menu : public EventListener
{

public:
    Menu();
    friend void OnMenuMainActionCall(EventParameters);
    friend void OnMenuJoystickCall(EventParameters);

    void OnEnable();
    void OnDisable();

    void changeSelection(EventParameters ep);
    void menuController(int menu);
    void afficherMenuPrincipal();
    void selectionMenuPrincipal();
    void afficherMenuPause();
    void selectionMenuPause();
    void afficherMenuFin(string message);
    void selectionMenuFin();

private:
    int choix = 0;
    int lastActiveMenu = 0;
};

#endif