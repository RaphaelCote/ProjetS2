#include <iostream>
#include <string>

#include "EndGameMenu.h"
#include "../raftWars.h"
#include "../Controls/keyboardControls.h"
#include "shopMenu.h"
#include "../Affichage/Global.h"

EndGameMenu::EndGameMenu()
{
}

void OnEndGameMenuMainActionCall(EventParameters ep)
{
    Menu *menu = (Menu *)scenes->at(activeScene);
    menu->Selection();
}

void OnEndGameMenuJoystickCall(EventParameters ep)
{
    Menu *menu = (Menu *)scenes->at(activeScene);
    menu->changeSelection(ep);
}

void OnEndGameMenuBackCall(EventParameters)
{
    EndGameMenu *menu = (EndGameMenu *)scenes->at(activeScene);
    menu->ReturnToMenu();
    menu->OnDisable();
}

void EndGameMenu::OnEnable()
{
    eventManager->on("MainAction", OnEndGameMenuMainActionCall);
    eventManager->on("Joystick", OnEndGameMenuJoystickCall);
    eventManager->on("Back", OnEndGameMenuBackCall);
}

void EndGameMenu::OnDisable()
{
    eventManager->off("MainAction", OnEndGameMenuMainActionCall);
    eventManager->off("Joystick", OnEndGameMenuJoystickCall);
    eventManager->off("Back", OnEndGameMenuBackCall);
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
        ShowMenu();
        gameWindow->SetChecked(choice);
    }
    else if (ep.parameter2 < -0.5)
    {
        if (choice < 3)
        {
            choice++;
        }
        ShowMenu();
        gameWindow->SetChecked(choice);
    }
}

void EndGameMenu::Update()
{
    if (doOnce)
    {
        OnEnable();
        ShowMenu();
        doOnce = false;
    }
}

void EndGameMenu::ShowMenu()
{
    // ClearMenu();
    cons->SupprimerObjet("s0");
    cons->SupprimerObjet("s1");
    cons->SupprimerObjet("s2");
    cons->SupprimerObjet("s3");
    cons->SupprimerObjet("s4");
    cons->SupprimerObjet("s5");
    cons->SupprimerObjet("s6");

    Sleep(10);

    // Vérifier qu'on est pas au dernier niveau
    std::string s0 = "------------------------------------------------------------------- ";
    std::string s1 = "Fin du niveau ";
    std::string s2 = "-";
    s2 += (choice == 0 ? "O" : "-");
    s2 += "- Prochain niveau ";
    std::string s3 = "-";
    s3 += (choice == 1 ? "O" : "-");
    s3 += "- Selectionner un niveau ";
    std::string s4 = "-";
    s4 += (choice == 2 ? "O" : "-");
    s4 += "- Magasin ";
    std::string s5 = "-";
    s5 += (choice >= 3 ? "O" : "-");
    s5 += "- Retour au menu ";
    std::string s6 = "------------------------------------------------------------------- ";

    int y0 = ((cons->MaxRows) * 10) - 30;
    int y1 = ((cons->MaxRows) * 10) - 40;
    int y2 = ((cons->MaxRows) * 10) - 50;
    int y3 = ((cons->MaxRows) * 10) - 60;
    int y4 = ((cons->MaxRows) * 10) - 70;
    int y5 = ((cons->MaxRows) * 10) - 80;
    int y6 = ((cons->MaxRows) * 10) - 90;
    int x = 20;

    cons->AfficherTexte(std::cout, s0, x, y0, "s0");
    cons->AfficherTexte(std::cout, s1, x, y1, "s1");
    cons->AfficherTexte(std::cout, s2, x, y2, "s2");
    cons->AfficherTexte(std::cout, s3, x, y3, "s3");
    cons->AfficherTexte(std::cout, s4, x, y4, "s4");
    cons->AfficherTexte(std::cout, s5, x, y5, "s5");
    cons->AfficherTexte(std::cout, s6, x, y6, "s6");
}

void EndGameMenu::ClearMenu()
{
    cons->SupprimerObjet("s0");
    cons->SupprimerObjet("s1");
    cons->SupprimerObjet("s2");
    cons->SupprimerObjet("s3");
    cons->SupprimerObjet("s4");
    cons->SupprimerObjet("s5");
    cons->SupprimerObjet("s6");
}

void EndGameMenu::Selection()
{
    doOnce = true;
    OnDisable();
    ShowMenu();

    if (choice == 0)
    {
        NextLevel();
    }
    else if (choice == 1)
    {
        GotoLevelSelect();
    }
    else if (choice == 2)
    {
        GotoShop();
    }
    else if (choice == 3)
    {
        ReturnToMenu();
    }
}

void EndGameMenu::NextLevel()
{
    choice = 0;
    Game *game = (Game *)scenes->at(1);
    game->SetLevelIndex(game->GetLevelIndex() + 1);
    game->isNewLevel = true;
    activeScene = 1;
}

void EndGameMenu::GotoShop()
{
    choice = 0;
    ShopMenu *shop = (ShopMenu *)scenes->at(5);
    shop->lastMenu = 3;
    activeScene = 5;
}

void EndGameMenu::GotoLevelSelect()
{
    choice = 0;
    LevelSelectionMenu *lsm = (LevelSelectionMenu *)scenes->at(2);
    lsm->lastMenu = 3;
    activeScene = 2;
}

void EndGameMenu::ReturnToMenu()
{
    choice = 0;
    activeScene = 0;
}