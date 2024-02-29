#include <iostream>
#include <string>

#include "mainMenu.h"
#include "../raftWars.h"
#include "../controls/EventManager.h"
#include "../Controls/keyboardControls.h"

void OnMenuMainActionCall(EventParameters ep)
{

    activeMenu->Selection();
}

void OnMenuJoystickCall(EventParameters ep)
{
    activeMenu->changeSelection(ep);
}

void MainMenu::OnEnable()
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
        choice--;
        if (choice < 0)
        {
            choice = 0;
        }
    }
    else if (ep.parameter2 < -0.5)
    {
        choice++;
    }
}

void MainMenu::ShowMenu()
{
}

void MainMenu::Selection()
{
}
