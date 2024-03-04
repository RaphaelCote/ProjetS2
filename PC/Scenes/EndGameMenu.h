#ifndef ENDGAMEMENU_H
#define ENDGAMEMENU_H

#include "menu.h"
#include "LevelSelectionMenu.h"
#include "mainMenu.h"

using namespace std;

class EndGameMenu : public Menu
{
public:
    EndGameMenu();
    void Update();
    void NextLevel();
    void GotoLevelSelect();
    void ReturnToMenu();
};

#endif