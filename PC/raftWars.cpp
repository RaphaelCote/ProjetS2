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
using namespace std;

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

/*------------------------- Prototypes de fonctions -------------------------*/

/*---------------------------- Variables globales ---------------------------*/

EventManager *eventManager;
Tests *tests;
Controls *controls;
Vecteur<Scene *> *scenes;
Inventory *inventory;
int activeScene;
LevelGetter *levelGetter;
AffichageConsole *cons;
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
    controls = new KeyboardControls(eventManager);
    // controls = new ControllerControls(eventManager, "COM3");

    tests = new Tests();
    // tests->testjson();
    // tests->tests_unitaires_levelGetter();

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

    // Main loop
    while (true)
    {
        // Check if a key is pressed
        if (_kbhit())
        {
            // Read the pressed key
            char input = _getch();

            // Handle the input
            int x = 2;
            int y = cons->MaxRows - 3;
            string s = "You pressed: " + input;
            cons->AfficherTexte(cout, s, &x, &y, "key");

            // Exit loop if 'q' is pressed
            if (input == 'q')
            {
                break;
            }
        }

        // Do other processing here
        // Note: This loop will continue to execute without blocking on keyboard input
        scenes->get(activeScene)->Update();
    }

    // Restore cursor visibility and console mode
    // cursorInfo.bVisible = true;
    // SetConsoleCursorInfo(consoleHandle, &cursorInfo);
    // SetConsoleMode(consoleHandle, mode);

    return 0;
}
