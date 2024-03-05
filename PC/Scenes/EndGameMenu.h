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

    friend void OnEndGameMenuMainActionCall(EventParameters);
    friend void OnEndGameMenuJoystickCall(EventParameters);

    void OnEnable();
    void OnDisable();

    void changeSelection(EventParameters ep);
    void ShowMenu();
    void Selection();

    void Update();
    void NextLevel();
    void GotoShop();
    void GotoLevelSelect();
    void ReturnToMenu();
};

#endif