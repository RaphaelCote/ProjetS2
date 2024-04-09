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
#include "Affichage/Global.h"
#include "Affichage/AffichageConsole.h"
#include "Affichage/GameWidget.h"
#include "Affichage/GameWindow.h"
#include "Affichage/MainMenuQt.h"
#include "Affichage/LevelMenu.h"
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
#include <QScreen>
// #include <QMediaPlaylist>
#include <thread>
#include <chrono>

/*------------------------------ Constantes ---------------------------------*/

/*---------------------------- Variables globales ---------------------------*/

EventManager *eventManager;
Tests *tests;
Controls *controls;
// Controls* controlsG;
GameWindow *gameWindow;
int levelQty;
std::vector<Scene *> *scenes;
/*
Scenes index:
0 : Main menu
1 : Game
2 : Level Selection menu
3 : End game menu
4 : Pause menu
5 : Shop
*/

Inventory *inventory;
int activeScene;
LevelGetter *levelGetter;
AffichageConsole *cons;

std::chrono::duration<double, std::milli> currentclock;
std::chrono::duration<double, std::milli> lastClock;
std::chrono::duration<double, std::milli> rcvSerialTimer;

class MyThread : public QThread
{
public:
    void run() override
    {
        cons = new AffichageConsole();

        // tests = new Tests();
        // tests->testjson();
        // tests->tests_unitaires_levelGetter();

        // tests->test_unitaires_affichage(); // Test affichage jeux
        // tests->testAffichage();
        // tests->testOuvertureJsonAffiche();

        // reset UI
        cons->ResetUI();

        activeScene = 0;

        scenes = new std::vector<Scene *>();
        scenes->push_back(new MainMenu());
        scenes->push_back(new Game());
        scenes->push_back(new LevelSelectionMenu());
        scenes->push_back(new EndGameMenu());
        scenes->push_back(new PauseMenu());
        scenes->push_back(new ShopMenu());

        Sleep(500);
        /*std::chrono::system_clock::time_point start = std::chrono::high_resolution_clock::now();*/
        std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
        // totalElapsed = start - start;

        // timer.setInterval(10); // Interval in milliseconds
        // QObject::connect(&timer, &QTimer::timeout, [=]()
        //     {
        //         ((ControllerControls*)controls)->ReceiveSerial();
        //     });
        // QObject::connect(&timer, &QTimer::timeout, [&]() {
        //     compteur++; // Incrémentation de compteur à chaque timeout du timer
        //     fonctionBatard();
        //     });

        // Main loop
        Sleep(2000); // minimum de 2 secondes sinon, sa crash

        QEvent *event = new QEvent(QEvent::User);
        QApplication::postEvent(gameWindow, event);
        //----------------------Sans QTimer----------------------//
        while (true)
        {
            lastClock = currentclock;
            const auto now = std::chrono::high_resolution_clock::now();
            currentclock = now - start;
            scenes->at(activeScene)->Update();      // en théorie ça marche
            /*scenes->get(activeScene)->Update();*/ //==> ancienne magouille

            Sleep(10);

            if ((currentclock.count() - rcvSerialTimer.count()) > 100)
            {

                ((ControllerControls *)controls)->ReceiveSerial();

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

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qDebug() << "Main thread started";

    inventory = new Inventory();
    inventory->addGold(2000);
    levelGetter = new LevelGetter();
    levelQty = levelGetter->nbLevel;

    gameWindow = new GameWindow();
    MainMenuQt *mainMenu = new MainMenuQt();
    GameWidget *gameQt = new GameWidget();
    LevelMenu *levelMenu = new LevelMenu();
    GenericMenu *endgameMenu = new GenericMenu();
    GenericMenu *pauseMenu = new GenericMenu();
    GenericMenu *shopMenu = new GenericMenu();
    GenericMenu *loadingScreen = new GenericMenu();

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int screenWidth = screenGeometry.width();
    int screenHeight = screenGeometry.height();
    int minX = 0;
    int minY = 0;

    QVBoxLayout *vbox = new QVBoxLayout();

    QPixmap logo("C:/home/DEVUniversite/ProjetS2/Images/logo.png");
    QLabel *titleLabel = new QLabel(loadingScreen);
    titleLabel->setPixmap(logo.scaled(650, 200, Qt::KeepAspectRatio));
    vbox->addWidget(titleLabel);
    vbox->addItem(new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed));

    vbox->setSpacing(45);
    vbox->setAlignment(Qt::AlignCenter);

    loadingScreen->setLayout(vbox);
    loadingScreen->update();

    // Lecture du fichier audio
    MyThread thread;
    thread.start();

    eventManager = new EventManager();
    controls = new KeyboardControls(eventManager);
    // controls = new ControllerControls(eventManager, "COM4");

    gameWindow->AddContent(mainMenu);
    gameWindow->AddContent(gameQt);
    gameWindow->AddContent(levelMenu);
    gameWindow->AddContent(endgameMenu);
    gameWindow->AddContent(pauseMenu);
    gameWindow->AddContent(shopMenu);
    gameWindow->AddContent(loadingScreen);

    gameWindow->ShowContent(6);

    gameWindow->setWindowState(Qt::WindowMaximized);
    gameWindow->show();
    //Sleep(500);
    // Lecture de la musique

    return app.exec();
}
