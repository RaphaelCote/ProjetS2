#include <iostream>
#include <string>

#include "PauseMenu.h"
#include "../raftWars.h"
#include "../controls/EventManager.h"
#include "../Controls/keyboardControls.h"

PauseMenu::PauseMenu()
{
}

void OnPauseMenuMainActionCall(EventParameters)
{
    Menu *menu = (Menu *)scenes->get(activeScene);
    menu->Selection();
}

void OnPauseMenuJoystickCall(EventParameters ep)
{
    Menu *menu = (Menu *)scenes->get(activeScene);
    menu->changeSelection(ep);
}

void PauseMenu::OnEnable()
{
    eventManager->on("MainAction", OnPauseMenuMainActionCall);
    eventManager->on("Joystick", OnPauseMenuJoystickCall);
}

void PauseMenu::OnDisable()
{
    eventManager->off("MainAction", OnPauseMenuMainActionCall);
    eventManager->off("Joystick", OnPauseMenuJoystickCall);
}

void PauseMenu::changeSelection(EventParameters ep)
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
        if (choice < 1)
        {
            choice++;
        }
    }
}

void PauseMenu::Update()
{
    OnEnable();
    ShowMenu();
    controls->ListenForControls();
}

void PauseMenu::ShowMenu()
{
    system("cls");
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Pause" << endl;
    cout << "-" << (choice == 0 ? "O" : "-") << "- Continuer." << endl;
    cout << "-" << (choice == 1 ? "O" : "-") << "- Retour au menu." << endl;
    cout << "-------------------------------------------------------------------" << endl;
}

void PauseMenu::Selection()
{
    if (choice == 0)
    {
        OnDisable();
        Continu();
    }
    else if (choice == 1)
    {
        OnDisable();
        ReturnToMenu();
    }
}

void PauseMenu::Continu()
{
    choice = 0;
    activeScene = 1;
}

void PauseMenu::ReturnToMenu()
{
    choice = 0;
    Game *game = (Game *)scenes->get(1);
    game->StopGame();
    activeScene = 0;
}