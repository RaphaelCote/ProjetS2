#include <iostream>
#include <string>

#include "mainMenu.h"
#include "../raftWars.h"
#include "../controls/EventManager.h"
#include "../Controls/keyboardControls.h"

void OnMainMenuMainActionCall(EventParameters ep)
{

    // activeMenu->Selection();
}

void OnMainMenuJoystickCall(EventParameters ep)
{
    // activeMenu->changeSelection(ep);
}

void MainMenu::OnEnable()
{
    eventManager->on("MainAction", OnMainMenuMainActionCall);
    eventManager->on("Joystick", OnMainMenuJoystickCall);
}

void MainMenu::OnDisable()
{
    eventManager->off("MainAction", OnMainMenuMainActionCall);
    eventManager->off("Joystick", OnMainMenuJoystickCall);
}

MainMenu::MainMenu()
{
}

void MainMenu::Update()
{
    ShowMenu();
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
    // menu utilisateur
    system("cls");
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Bienvenue au menu du jeu Raft Wars" << endl;
    cout << "-" << (choice == 0 ? "O" : "-") << "- Commencer." << endl;
    // cout << " 2. Choisir un niveau." << endl;
    cout << "-" << (choice >= 1 ? "O" : "-") << "- Sortir" << endl;
    cout << "-------------------------------------------------------------------" << endl;
}

void MainMenu::Selection()
{
    if (choice == 0)
    {

        system("cls"); // clear la command prompt
        OnDisable();
    }
    else if (choice >= 1)
    {

        system("cls"); // clear la command prompt
        cout << "Au plaisir.." << endl;
        system("PAUSE");
        exit(0);
    }
}