/*
 * Auteurs: Jean-Samuel Lauzon
 * Date: Fevrier 2022
 * Modif : Janvier 2023, Compatible VisualStudio, JpGouin
 * Modif : S2-H24, Équipe P-20
 */

/*------------------------------ Librairies ---------------------------------*/
#include <iostream>
#include <string>
#include <conio.h>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono_literals;

/*-------------------------- Librairies externes ----------------------------*/

/*-------------------------- Other file include -----------------------------*/
#include "raftWars.h"
#include "Affichage/AffichageConsole.h"
#include "Controls/eventManager.h"
#include "Controls/keyboardControls.h"
#include "Controls/ControllerControls.h"
#include "tests.h"
#include "Scenes/menu.h"
#include "Scenes/mainMenu.h"
#include "Scenes/pauseMenu.h"
#include "Scenes/endGameMenu.h"
#include "Scenes/levelSelectionMenu.h"
#include "Scenes/shopMenu.h"

/*------------------------------ Constantes ---------------------------------*/

#define _GLIBCXX_USE_NANOSLEEP

/*---------------------------- Variables globales ---------------------------*/

EventManager *eventManager;
Tests *tests;
Controls *controls;
Vecteur<Scene *> *scenes;
Inventory *inventory;
int activeScene;
LevelGetter *levelGetter;
AffichageConsole *cons;
std::chrono::_V2::system_clock::time_point start;
std::chrono::duration<double, std::milli> currentclock;
std::chrono::duration<double, std::milli> lastClock;
std::chrono::duration<double, std::milli> rcvSerialTimer;

/*
Scenes index:
0 : Main menu
1 : Game
2 : Level Selection menu
3 : End game menu
4 : Pause menu
5 : Shop
*/

/*----------------------------- Fonction "Main" -----------------------------*/
int main()
{
    cons = new AffichageConsole();

    // === Event manager tests ===
    eventManager = new EventManager();
    // controls = new KeyboardControls(eventManager);
    controls = new ControllerControls(eventManager, "COM3");

    // tests = new Tests();
    // tests->testjson();
    // tests->tests_unitaires_levelGetter();

    // tests->test_unitaires_affichage(); // Test affichage jeux

    inventory = new Inventory();
    inventory->addGold(2000);

    // reset UI
    cons->ResetUI();

    activeScene = 0;

    scenes = new Vecteur<Scene *>();
    scenes->add(new MainMenu());
    scenes->add(new Game());
    scenes->add(new LevelSelectionMenu());
    scenes->add(new EndGameMenu());
    scenes->add(new PauseMenu());
    scenes->add(new ShopMenu());

    levelGetter = new LevelGetter();

    Sleep(1000);
    start = std::chrono::high_resolution_clock::now();
    // totalElapsed = start - start;

    // Main loop
    while (true)
    {
        lastClock = currentclock;
        const auto now = std::chrono::high_resolution_clock::now();
        currentclock = now - start;

        scenes->get(activeScene)->Update();

        Sleep(1);

        if ((currentclock.count() - rcvSerialTimer.count()) > 100)
        {
            ControllerControls *controller = (ControllerControls *)controls;
            controller->ReceiveSerial();

            rcvSerialTimer = currentclock;
        }

        controls->ListenForControls();
    }

    // Restore cursor visibility and console mode
    // cursorInfo.bVisible = true;
    // SetConsoleCursorInfo(consoleHandle, &cursorInfo);
    // SetConsoleMode(consoleHandle, mode);

    return 0;
}
