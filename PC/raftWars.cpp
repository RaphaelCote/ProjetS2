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
using namespace std::chrono_literals;
using namespace std::chrono;

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
#include "Affichage/MainWindow.h"
#include <QTimer>
#include <QApplication>
#include <thread>
#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QApplication>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QFileInfo>
#include <QScreen>
//#include <QMediaPlaylist>
#include <thread>
#include <chrono>

/*------------------------------ Constantes ---------------------------------*/

/*---------------------------- Variables globales ---------------------------*/

EventManager *eventManager;
Tests *tests;
Controls *controls;
std::vector<Scene *> *scenes;
Inventory *inventory;
int activeScene;
LevelGetter *levelGetter;
AffichageConsole *cons;


std::chrono::duration<double, std::milli> currentclock;
std::chrono::duration<double, std::milli> lastClock;
std::chrono::duration<double, std::milli> rcvSerialTimer;



void fonctionBatard()
{
    compteur++;
    controls->ReceiveSerial();
}
void timerFunction()
{
    while (true)
    {
        // Effectuer l'action désirée ici
        fonctionBatard();

        // Attendre 10 ms
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
class MyThread : public QThread {
public:
    void run() override 
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
        //tests->testAffichage();
        // tests->testOuvertureJsonAffiche();

        inventory = new Inventory();
        inventory->addGold(2000);

        // reset UI
        cons->ResetUI();

        activeScene = 0;

        scenes = new std::vector<Scene*>();
        scenes->push_back(new MainMenu());
        scenes->push_back(new Game());
        scenes->push_back(new LevelSelectionMenu());
        scenes->push_back(new EndGameMenu());
        scenes->push_back(new PauseMenu());
        scenes->push_back(new ShopMenu());
        levelGetter = new LevelGetter();

        Sleep(500);
        /*std::chrono::system_clock::time_point start = std::chrono::high_resolution_clock::now();*/
        std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
        // totalElapsed = start - start;

        
        //timer.setInterval(10); // Interval in milliseconds
        //QObject::connect(&timer, &QTimer::timeout, [=]()
        //    {
        //        ((ControllerControls*)controls)->ReceiveSerial();
        //    });
        //QObject::connect(&timer, &QTimer::timeout, [&]() {
        //    compteur++; // Incrémentation de compteur à chaque timeout du timer
        //    fonctionBatard();
        //    });
        
       
        // Main loop
        //----------------------Sans QTimer----------------------//
        while (true)
        {
            lastClock = currentclock;
            const auto now = std::chrono::high_resolution_clock::now();
            currentclock = now - start;
            scenes->at(activeScene)->Update();// en théorie ça marche
            /*scenes->get(activeScene)->Update();*/   //==> ancienne magouille

            Sleep(10);

            if ((currentclock.count() - rcvSerialTimer.count()) > 100)
            {

                ((ControllerControls*)controls)->ReceiveSerial();

                rcvSerialTimer = currentclock;
            }

            controls->ListenForControls();
        }
        //----------------------Avec QTimer----------------------//
        /* while (true)
        {

            scenes->get(activeScene)->Update();

            Sleep(10);

            timerFunction();

            controls->ListenForControls();
        }*/

    }
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    qDebug() << "Main thread started";
    
    MainWindow window;
    window.Initialiser();
    MyThread thread;
    thread.start();
    
    Tests test2;

    test2.testAffichageQt(&window, &app);

    window.show();
    
    
    return app.exec();
}
