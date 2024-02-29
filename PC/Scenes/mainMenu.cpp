#include <iostream>
#include <string>

#include "mainMenu.h"
#include "../raftWars.h"
#include "../controls/EventManager.h"
#include "../Controls/keyboardControls.h"

void OnMenuMainActionCall(EventParameters ep)
{
    if (menu->lastActiveMenu == 0)
    {
        menu->selectionMenuPrincipal();
    }
    else if (menu->lastActiveMenu == 1)
    {
        menu->selectionMenuPause();
    }
    else if (menu->lastActiveMenu == 2)
    {
        menu->selectionMenuFin();
    }
}

void OnMenuJoystickCall(EventParameters ep)
{
    menu->changeSelection(ep);
}

void Main : Menu::OnEnable()
{
    eventManager->on("MainAction", OnMenuMainActionCall);
    eventManager->on("Joystick", OnMenuJoystickCall);
    // cout << "did on Enable" << endl;
}

void MainMenu::OnDisable()
{
    eventManager->off("MainAction", OnMenuMainActionCall);
    eventManager->off("Joystick", OnMenuJoystickCall);
}

void MainMenu::changeSelection(EventParameters ep)
{
    if (ep.parameter2 > 0.5)
    {
        choix--;
        if (choix < 0)
        {
            choix = 0;
        }
    }
    else if (ep.parameter2 < -0.5)
    {
        choix++;
    }
}