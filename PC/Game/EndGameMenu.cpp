#include <iostream>
#include <string>

#include "EndGameMenu.h"
#include "../raftWars.h"
#include "../controls/EventManager.h"
#include "../Controls/keyboardControls.h"
#include "shopMenu.h"

EndGameMenu::EndGameMenu()
{
}

void OnEndGameMenuMainActionCall(EventParameters ep)
{
    Menu *menu = (Menu *)scenes->get(activeScene);
    menu->Selection();
}

void OnEndGameMenuJoystickCall(EventParameters ep)
{
    Menu *menu = (Menu *)scenes->get(activeScene);
    menu->changeSelection(ep);
}

void EndGameMenu::OnEnable()
{
    eventManager->on("MainAction", OnEndGameMenuMainActionCall);
    eventManager->on("Joystick", OnEndGameMenuJoystickCall);
}

void EndGameMenu::OnDisable()
{
    eventManager->off("MainAction", OnEndGameMenuMainActionCall);
    eventManager->off("Joystick", OnEndGameMenuJoystickCall);
}

void EndGameMenu::changeSelection(EventParameters ep)
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
        if (choice < 2)
        {
            choice++;
        }
    }
}

void EndGameMenu::Update()
{
    OnEnable();
    ShowMenu();
    controls->ListenForControls();
}

void EndGameMenu::ShowMenu()
{
    system("cls");
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Fin du niveau" << endl;
    cout << "-" << (choice == 0 ? "O" : "-") << "- Prochain niveau" << endl;
    cout << "-" << (choice == 1 ? "O" : "-") << "- Selectionner un niveau" << endl;
    cout << "-" << (choice == 2 ? "O" : "-") << "- Magasin" << endl;
    cout << "-" << (choice == 3 ? "O" : "-") << "- Retour au menu" << endl;
    cout << "-------------------------------------------------------------------" << endl;
}

void EndGameMenu::Selection()
{
    if (choice == 0)
    {
        OnDisable();
        NextLevel();
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
    else if (choice == 3)
    {
        OnDisable();
        ReturnToMenu();
    }
}

void EndGameMenu::NextLevel()
{
    choice = 0;
    Game *game = (Game *)scenes->get(2);
    game->currentLevel++;
    activeScene = 1;
}

void EndGameMenu::GotoShop()
{
    choice = 0;
    ShopMenu *shop = (ShopMenu *)scenes->get(5);
    shop->lastMenu = 3;
    activeScene = 5;
}

void EndGameMenu::GotoLevelSelect()
{
    choice = 0;
    LevelSelectionMenu *lsm = (LevelSelectionMenu *)scenes->get(2);
    lsm->lastMenu = 3;
    activeScene = 2;
}

void EndGameMenu::ReturnToMenu()
{
    choice = 0;
    activeScene = 0;
}