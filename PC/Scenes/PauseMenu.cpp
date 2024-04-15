#include <iostream>
#include <string>

#include "PauseMenu.h"
#include "../raftWars.h"
#include "../Controls/keyboardControls.h"
#include "game.h"
#include "../Affichage/Global.h"
#include "../Affichage/ShowContentEvent.h"
#include "PauseMenuQt.h"

PauseMenu::PauseMenu(PauseMenuQt* pauseMenu)
{
    pauseMenu->connectButtonClicked(0, this);
    pauseMenu->connectButtonClicked(1, this);
}

void OnPauseMenuMainActionCall(EventParameters)
{
    Menu *menu = (Menu *)scenes->at(activeScene);
    soundManager->soundTrack = mouseClickEffect;
    soundManager->functionDecider = play_SoundTrack;
    menu->Selection();
}

void OnPauseMenuJoystickCall(EventParameters ep)
{
    Menu *menu = (Menu *)scenes->at(activeScene);
    soundManager->soundTrack = selectionSoundEffect;
    soundManager->functionDecider = play_SoundTrack;
    menu->changeSelection(ep);
}

void OnPauseMenuBackCall(EventParameters)
{
    PauseMenu *menu = (PauseMenu *)scenes->at(activeScene);
    soundManager->soundTrack = mouseClickEffect;
    soundManager->functionDecider = play_SoundTrack;
    menu->OnDisable();
    menu->doOnce = true;
    menu->Continu();
}

void PauseMenu::OnEnable()
{
    eventManager->on("MainAction", OnPauseMenuMainActionCall);
    eventManager->on("Joystick", OnPauseMenuJoystickCall);
    eventManager->on("Back", OnPauseMenuBackCall);
}

void PauseMenu::OnDisable()
{
    eventManager->off("MainAction", OnPauseMenuMainActionCall);
    eventManager->off("Joystick", OnPauseMenuJoystickCall);
    eventManager->off("Back", OnPauseMenuBackCall);
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
        ShowMenu();
        gameWindow->SetChecked(choice);
    }
    else if (ep.parameter2 < -0.5)
    {
        if (choice < 1)
        {
            choice++;
        }
        ShowMenu();
        gameWindow->SetChecked(choice);
    }
}

void PauseMenu::Update()
{
    if (doOnce)
    {
        OnEnable();
        ShowMenu();
        doOnce = false;
    }
}

void PauseMenu::ShowMenu()
{
    // ClearMenu();
    cons->SupprimerObjet("s0");
    cons->SupprimerObjet("s1");
    cons->SupprimerObjet("s2");
    cons->SupprimerObjet("s3");
    cons->SupprimerObjet("s4");

    Sleep(10);

    // system("cls");
    std::string s0 = "------------------------------------------------------------------- ";
    std::string s1 = "Pause ";
    std::string s2 = "-";
    s2 += (choice == 0 ? "O" : "-");
    s2 += "- Continuer ";
    std::string s3 = "-";
    s3 += (choice == 1 ? "O" : "-");
    s3 += "- Retour au menu ";
    std::string s4 = "------------------------------------------------------------------- ";

    int y0 = ((cons->MaxRows) * 10) - 30;
    int y1 = ((cons->MaxRows) * 10) - 40;
    int y2 = ((cons->MaxRows) * 10) - 50;
    int y3 = ((cons->MaxRows) * 10) - 60;
    int y4 = ((cons->MaxRows) * 10) - 70;
    int x = 20;

    cons->AfficherTexte(std::cout, s0, x, y0, "s0");
    cons->AfficherTexte(std::cout, s1, x, y1, "s1");
    cons->AfficherTexte(std::cout, s2, x, y2, "s2");
    cons->AfficherTexte(std::cout, s3, x, y3, "s3");
    cons->AfficherTexte(std::cout, s4, x, y4, "s4");
}

void PauseMenu::ClearMenu()
{
    cons->SupprimerObjet("s0");
    cons->SupprimerObjet("s1");
    cons->SupprimerObjet("s2");
    cons->SupprimerObjet("s3");
    cons->SupprimerObjet("s4");
}

void PauseMenu::Selection()
{
    doOnce = true;
    OnDisable();
    ClearMenu();

    if (choice == 0)
    {
        Continu();
        soundManager->music = gameMusic;
        soundManager->functionDecider = play_Music;
    }
    else if (choice == 1)
    {
        soundManager->music = introMusic;
        soundManager->functionDecider = play_Music;
        ReturnToMenu();
    }
}

void PauseMenu::Continu()
{
    choice = 0;
    activeScene = 1;
    Game* game = (Game*)scenes->at(1);
    game->doOnce = true;
    ShowContentEvent* scEvent = new ShowContentEvent(1);
    QApplication::postEvent(gameWindow, scEvent);
}

void PauseMenu::ReturnToMenu()
{
    choice = 0;
    Game *game = (Game *)scenes->at(1);
    game->StopGame();
    activeScene = 0;
    ShowContentEvent* scEvent = new ShowContentEvent(0);
    QApplication::postEvent(gameWindow, scEvent);
}