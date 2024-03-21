#include <iostream>
#include <string>

#include "mainMenu.h"
#include "../raftWars.h"
#include "../controls/EventManager.h"
#include "LevelSelectionMenu.h"
#include "shopMenu.h"

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
    // Ajout de délai entre les changements de sélection de menu
    // à rajouter dans tout les menus
    int millis = 600;
    if (millis < lastMove + 500)
    {
        return;
    }

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

    OnEnable();
}

void MainMenu::Update()
{
    if (doOnce)
    {
        OnEnable();
        ShowMenu();
        doOnce = false;
    }

    controls->ListenForControls();
}

void MainMenu::ShowMenu()
{
    // menu utilisateur
    string s0 = "-------------------------------------------------------------------";
    string s1 = "Bienvenue au menu du jeu Raft Wars";
    string s2 = "-";
    s2 += (choice == 0 ? "O" : "-");
    s2 += "- Jouer";
    string s3 = "-";
    s3 += (choice == 1 ? "O" : "-");
    s3 += "- Niveaux";
    string s4 = "-";
    s4 += (choice == 2 ? "O" : "-");
    s4 += "- Magasin";
    string s5 = "-";
    s5 += (choice >= 3 ? "O" : "-");
    s5 += "- Sortir";
    string s6 = "-------------------------------------------------------------------";

    int x0 = 0;
    int y0 = 0;
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    int x3 = 0;
    int y3 = 0;
    int x4 = 0;
    int y4 = 0;
    int x5 = 0;
    int y5 = 0;
    int x6 = 0;
    int y6 = 0;

    cons->AfficherTexte(cout, s0, &x0, &y0, "s0");
    cons->AfficherTexte(cout, s1, &x1, &y1, "s1");
    cons->AfficherTexte(cout, s2, &x2, &y2, "s2");
    cons->AfficherTexte(cout, s3, &x3, &y3, "s3");
    cons->AfficherTexte(cout, s4, &x4, &y4, "s4");
    cons->AfficherTexte(cout, s5, &x5, &y5, "s5");
    cons->AfficherTexte(cout, s6, &x6, &y6, "s6");
}

void MainMenu::Selection()
{
    doOnce = true;
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
        cons->ResetUI();
        cons->AfficherTexte(cout, "Au plaisir..", new int(10), new int(cons->ScreenHeight), "AuPlaisir");
        system("PAUSE");
        exit(0);
    }
}

void MainMenu::PlayGame()
{
    choice = 0;
    Game *game = (Game *)scenes->get(1);
    game->isNewLevel = true;
    activeScene = 1;
}

void MainMenu::GotoLevelSelect()
{
    choice = 0;
    LevelSelectionMenu *lsm = (LevelSelectionMenu *)scenes->get(2);
    lsm->lastMenu = 0;
    activeScene = 2;
}

void MainMenu::GotoShop()
{
    choice = 0;
    ShopMenu *shop = (ShopMenu *)scenes->get(5);
    shop->lastMenu = 0;
    activeScene = 5;
}

void MainMenu::ExitGame()
{
    exit(0);
}