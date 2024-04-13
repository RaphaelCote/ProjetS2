#include <iostream>
#include <string>

#include "mainMenu.h"
#include "../raftWars.h"
#include "../Affichage/Global.h"
#include "../Affichage/ShowContentEvent.h"
#include "LevelSelectionMenu.h"
#include "shopMenu.h"
#include "../Controls/SoundManager.h"
#include "MainMenuQt.h"

void OnMainMenuMainActionCall(EventParameters ep)
{
    soundManager->soundTrack = mouseClickEffect;
    soundManager->functionDecider = play_SoundTrack;
    Menu *menu = (Menu *)scenes->at(activeScene);
    menu->Selection();
}

void OnMainMenuJoystickCall(EventParameters ep)
{
    soundManager->soundTrack = selectionSoundEffect;
    soundManager->functionDecider = play_SoundTrack;
    Menu *menu = (Menu *)scenes->at(activeScene);
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

MainMenu::MainMenu(MainMenuQt* mainMenuQt)
{
    mainMenuQt->connectButtonClicked(0, this);
    mainMenuQt->connectButtonClicked(1, this);
    mainMenuQt->connectButtonClicked(2, this);
    mainMenuQt->connectButtonClicked(3, this);
}

void MainMenu::changeSelection(EventParameters ep)
{
    // Ajout de délai entre les changements de sélection de menu
    // à rajouter dans tout les menus}
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

void MainMenu::Update()
{
    if (doOnce)
    {
        OnEnable();
        ShowMenu();
        doOnce = false;
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

    Sleep(10);

    std::string s0 = "------------------------------------------------------------------- ";
    std::string s1 = "Bienvenue au menu du jeu Raft Wars ";
    std::string s2 = "-";
    s2 += (choice == 0 ? "O" : "-");
    s2 += "- Jouer ";
    std::string s3 = "-";
    s3 += (choice == 1 ? "O" : "-");
    s3 += "- Niveaux ";
    std::string s4 = "-";
    s4 += (choice == 2 ? "O" : "-");
    s4 += "- Magasin ";
    std::string s5 = "-";
    s5 += (choice >= 3 ? "O" : "-");
    s5 += "- Sortir ";
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
        soundManager->music = gameMusic;
        soundManager->functionDecider = play_Music;
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
        //int x = 2;
        //int y = cons->MaxRows - 4;
        //cons->AfficherTexte(std::cout, "Au plaisir..", &x, &y, "AuPlaisir");
        exit(0);
    }
}

void MainMenu::PlayGame()
{

    doOnce = true;
    ClearMenu();
    OnDisable();
    choice = 0;
    Game *game = (Game *)scenes->at(1);
    game->isNewLevel = true;
    activeScene = 1;
    ShowContentEvent* scEvent = new ShowContentEvent(1);
    QApplication::postEvent(gameWindow, scEvent);
}

void MainMenu::GotoLevelSelect()
{
    choice = 0;
    LevelSelectionMenu *lsm = (LevelSelectionMenu *)scenes->at(2);
    lsm->lastMenu = 0;
    activeScene = 2;
    ShowContentEvent* scEvent = new ShowContentEvent(2);
    QApplication::postEvent(gameWindow, scEvent);
}

void MainMenu::GotoShop()
{
    choice = 0;
    ShopMenu *shop = (ShopMenu *)scenes->at(5);
    shop->lastMenu = 0;
    activeScene = 5;
    ShowContentEvent* scEvent = new ShowContentEvent(5);
    QApplication::postEvent(gameWindow, scEvent);
}

void MainMenu::ExitGame()
{
    exit(0);
}