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


/*
Scenes index:
0 : Main menu
1 : Game
2 : Level Selection menu
3 : End game menu
4 : Pause menu
5 : Shop
*/


class MainWindow : public QMainWindow {
public:
    MainWindow(QWidget* parent = nullptr) : QMainWindow(parent) {
        // Création d'un menu "Fichier" avec une action "Quitter"
        QMenu* fileMenu = menuBar()->addMenu(tr("&Fichier"));
        QAction* quitAction = fileMenu->addAction(tr("&Quitter"), this, &QMainWindow::close);

        // Création d'un menu "Aide" avec une action "À propos"
        QMenu* helpMenu = menuBar()->addMenu(tr("&Aide"));
        QAction* aboutAction = helpMenu->addAction(tr("&À propos"), this, &MainWindow::about);

        // Création d'une zone centrale pour la fenêtre
        QWidget* centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);

        // Définition de la taille de la fenêtre
        resize(400, 300);
    }

private slots:
    // Fonction à appeler lors du clic sur "À propos"
    void about() {
        QMessageBox::about(this, tr("À propos de l'application"),
            tr("Ceci est une application de démonstration "
                "créée avec Qt."));
    }
};
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
        controls = new ControllerControls(eventManager, "COM4");

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
    QMediaPlayer mediaPlayer;
    QString filePath = "C:\\Users\\victo\\OneDrive\\Documents\\Université\\S2\\S2APP7\\RaftWarsS2Qt\\Music\\RaftWarsIntroMusic.mp3";
    mediaPlayer.setSource(QUrl::fromLocalFile(filePath));

    // Lecture du fichier audio
    mediaPlayer.play();
    MyThread thread;
    thread.start();
    MainWindow window;
    window.show();
    Sleep(2000);
    // Lecture de la musique


    //QMediaPlayer* musicPlayer = new QMediaPlayer;
    //QMediaPlaylist* playlist = new QMediaPlaylist;

    //playlist->addMedia(QUrl("C:\\chemin\\vers\\votre\\fichier\\audio.mp3")); // Remplacez le chemin par le chemin de votre fichier audio
    //playlist->setPlaybackMode(QMediaPlaylist::Loop);

    //musicPlayer->setPlaylist(playlist);
    //musicPlayer->play();

   



    //QTimer timer;
    //timer.setInterval(100); // Interval in milliseconds
    //QObject::connect(&timer, &QTimer::timeout, &fonctionBatard);
    //timer.start();
   // std::thread timerThread(timerFunction);

    // Attendre que le thread se termine
    //timerThread.join();
    return app.exec();
}
/*----------------------------- Fonction "Main" -----------------------------*/
//int main()
//{
//    cons = new AffichageConsole();
//
//    // === Event manager tests ===
//    eventManager = new EventManager();
//    // controls = new KeyboardControls(eventManager);
//    controls = new ControllerControls(eventManager, "COM4");
//
//    // tests = new Tests();
//    // tests->testjson();
//    // tests->tests_unitaires_levelGetter();
//
//    // tests->test_unitaires_affichage(); // Test affichage jeux
//    //tests->testAffichage();
//    // tests->testOuvertureJsonAffiche();
//
//    inventory = new Inventory();
//    inventory->addGold(2000);
//
//    // reset UI
//    cons->ResetUI();
//
//    activeScene = 0;
//
//    scenes = new Vecteur<Scene*>();
//    scenes->add(new MainMenu());
//    scenes->add(new Game());
//    scenes->add(new LevelSelectionMenu());
//    scenes->add(new EndGameMenu());
//    scenes->add(new PauseMenu());
//    scenes->add(new ShopMenu());
//    levelGetter = new LevelGetter();
//
//    Sleep(500);
//    /*std::chrono::system_clock::time_point start = std::chrono::high_resolution_clock::now();*/
//    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
//    // totalElapsed = start - start;
//
//
//    //timer.setInterval(10); // Interval in milliseconds
//    //QObject::connect(&timer, &QTimer::timeout, [=]()
//    //    {
//    //        ((ControllerControls*)controls)->ReceiveSerial();
//    //    });
//    //QObject::connect(&timer, &QTimer::timeout, [&]() {
//    //    compteur++; // Incrémentation de compteur à chaque timeout du timer
//    //    fonctionBatard();
//    //    });
//
//
//    // Main loop
//    while (true)
//    {
//        lastClock = currentclock;
//        const auto now = std::chrono::high_resolution_clock::now();
//        currentclock = now - start;
//
//        scenes->get(activeScene)->Update();
//
//        Sleep(10);
//
//        if ((currentclock.count() - rcvSerialTimer.count()) > 100)
//        {
//
//            ((ControllerControls*)controls)->ReceiveSerial();
//
//            rcvSerialTimer = currentclock;
//        }
//
//        controls->ListenForControls();
//    }
//
//    return 0;
//}