#include <iostream>
#include <string>

#include "mainMenu.h"
#include "../raftWars.h"
#include "../controls/EventManager.h"
#include "LevelSelectionMenu.h"

void OnMainMenuMainActionCall(EventParameters ep)
{
    Menu *menu = (Menu *)scenes->get(activeScene);
    menu->Selection();
}

void OnMainMenuJoystickCall(EventParameters ep)
{
    Menu *menu = (Menu *)scenes->get(activeScene);
    menu->changeSelection(ep);
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
        if (choice < 3)
        {
            choice++;
        }
    }
}

void MainMenu::Update()
{
    OnEnable();
    ShowMenu();
    controls->ListenForControls();
}

void MainMenu::ShowMenu()
{
    // menu utilisateur
    system("cls");
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Bienvenue au menu du jeu Raft Wars" << endl;
    cout << "-" << (choice == 0 ? "O" : "-") << "- Commencer" << endl;
    cout << "-" << (choice == 1 ? "O" : "-") << "- Niveaux" << endl;
    cout << "-" << (choice == 2 ? "O" : "-") << "- Magasin" << endl;
    cout << "-" << (choice >= 3 ? "O" : "-") << "- Sortir" << endl;
    cout << "-------------------------------------------------------------------" << endl;
}

void MainMenu::Selection()
{
    if (choice == 0)
    {
        OnDisable();
        PlayGame();
    }
    else if (choice == 1)
    {
        OnDisable();
        GotoLevelSelect();
    }
    else if (choice == 2)
    {
        OnDisable();
        GotoShop();
    }
    else if (choice >= 3)
    {

        system("cls"); // clear la command prompt
        cout << "Au plaisir.." << endl;
        system("PAUSE");
        exit(0);
    }
}

void MainMenu::PlayGame()
{
    activeScene = 1;
}

void MainMenu::GotoLevelSelect()
{
    LevelSelectionMenu *lsm = (LevelSelectionMenu *)scenes->get(2);
    lsm->lastMenu = 0;
    activeScene = 2;
}

void MainMenu::GotoShop()
{
    activeScene = 5;
}

void MainMenu::ExitGame()
{
    exit(0);
}