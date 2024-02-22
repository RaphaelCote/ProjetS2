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
    friend void OnMainActionCall(EventParameters);
    friend void OnJoystickCall(EventParameters);

    void OnEnable();
    void OnDisable();

    void changeSelection(EventParameters ep);
    void menuController();
    void afficherMenuPrincipal();
    void selectionMenuPrincipal();
    void afficherMenuPause();
    void selectionMenuPause();
    void afficherMenuFin();
    void selectionMenuFin();

private:
    int choix = 0;
    int lastActiveMenu = 0;
};

#endif