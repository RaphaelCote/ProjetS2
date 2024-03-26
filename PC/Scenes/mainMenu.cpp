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

    ShowMenu();
}

void MainMenu::Update()
{
    if (doOnce)
    {
        OnEnable();
        ShowMenu();
        doOnce = false;
        Sleep(200);
        ShowMenu();
    }
}

void MainMenu::ShowMenu()
{
    // ClearMenu();
    cons->SupprimerObjet("s0");
    cons->SupprimerObjet("s1");
    cons->SupprimerObjet("s2");
    cons->SupprimerObjet("s3");
    cons->SupprimerObjet("s4");
    cons->SupprimerObjet("s5");
    cons->SupprimerObjet("s6");

    Sleep(50);

    string s0 = "------------------------------------------------------------------- ";
    string s1 = "Bienvenue au menu du jeu Raft Wars ";
    string s2 = "-";
    s2 += (choice == 0 ? "O" : "-");
    s2 += "- Jouer ";
    string s3 = "-";
    s3 += (choice == 1 ? "O" : "-");
    s3 += "- Niveaux ";
    string s4 = "-";
    s4 += (choice == 2 ? "O" : "-");
    s4 += "- Magasin ";
    string s5 = "-";
    s5 += (choice >= 3 ? "O" : "-");
    s5 += "- Sortir ";
    string s6 = "------------------------------------------------------------------- ";

    int y0 = cons->MaxRows - 3;
    int y1 = cons->MaxRows - 4;
    int y2 = cons->MaxRows - 5;
    int y3 = cons->MaxRows - 6;
    int y4 = cons->MaxRows - 7;
    int y5 = cons->MaxRows - 8;
    int y6 = cons->MaxRows - 9;
    int x = 2;

    cons->AfficherTexte(std::cout, s0, &x, &y0, "s0");
    cons->AfficherTexte(std::cout, s1, &x, &y1, "s1");
    cons->AfficherTexte(std::cout, s2, &x, &y2, "s2");
    cons->AfficherTexte(std::cout, s3, &x, &y3, "s3");
    cons->AfficherTexte(std::cout, s4, &x, &y4, "s4");
    cons->AfficherTexte(std::cout, s5, &x, &y5, "s5");
    cons->AfficherTexte(std::cout, s6, &x, &y6, "s6");
}

void MainMenu::ClearMenu()
{
    cons->SupprimerObjet("s0");
    cons->SupprimerObjet("s1");
    cons->SupprimerObjet("s2");
    cons->SupprimerObjet("s3");
    cons->SupprimerObjet("s4");
    cons->SupprimerObjet("s5");
    cons->SupprimerObjet("s6");
}

void MainMenu::Selection()
{
    doOnce = true;
    ClearMenu();
    OnDisable();

    if (choice == 0)
    {
        PlayGame();
    }
    else if (choice == 1)
    {
        GotoLevelSelect();
    }
    else if (choice == 2)
    {
        GotoShop();
    }
    else if (choice >= 3)
    {
        int x = 2;
        int y = cons->MaxRows - 4;
        cons->AfficherTexte(cout, "Au plaisir..", &x, &y, "AuPlaisir");
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