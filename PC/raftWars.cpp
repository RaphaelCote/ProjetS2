/*
 * Auteurs: Jean-Samuel Lauzon
 * Date: Fevrier 2022
 * Modif : Janvier 2023, Compatible VisualStudio, JpGouin
 * Modif : S2-H24, Équipe P-20
 */

/*------------------------------ Librairies ---------------------------------*/
#include <iostream>
#include <string>
using namespace std;

/*-------------------------- Librairies externes ----------------------------*/


/*-------------------------- Other file include -----------------------------*/
#include "raftWars.h"
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
    // === Event manager tests ===
    eventManager = new EventManager();
    //controls = new KeyboardControls(eventManager);
     controls = new ControllerControls(eventManager, "COM3");

    tests = new Tests();
    // tests->tests_unitaires();

    inventory = new Inventory();
    inventory->addGold(2000);

    activeScene = 0;

    scenes = new Vecteur<Scene *>;
    scenes->add(new MainMenu());
    scenes->add(new Game());
    scenes->add(new LevelSelectionMenu());
    scenes->add(new EndGameMenu());
    scenes->add(new PauseMenu());
    scenes->add(new ShopMenu());

    while (true)
    {
        scenes->get(activeScene)->Update();
    }

    int led_state = 0;
    float valX = 0;
    

    // Boucle pour tester la communication bidirectionnelle Arduino-PC
    for (int i = 0; i < 1110; i++)
    {
        if(i%10 == 0)
            led_state = 0;
        //cout << "Sending a message" << endl;
        controls->AddMessage("led", led_state);
        if(!controls->SendMessageJson())
            continue;
        //cout << "Message sent: " << led_state << endl;
        // Changement de l'etat led
        led_state = led_state >> 1;
        led_state += 512;
        cout << "Main//////////////////////////////" << endl;
        // controls->GetValue("JoyX", &valX);
        // cout << valX << endl;

        // Bloquer le fil pour environ 1 sec
        Sleep(1000); // 1000ms
        
    }

    return 0;
}

