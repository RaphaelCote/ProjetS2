#ifndef MAINMENU_H
#define MAINMENU_H

#include "menu.cpp"

using namespace std;

class MainMenu
{
public:
    MainMenu();
    void Update();
    void PlayGame();
    void GotoLevelSelect();
    void GotoShop();
    void ExitGame();
};

#endif