#ifndef ENDGAMEMENU_H
#define ENDGAMEMENU_H

#include "menu.h"
#include "LevelSelectionMenu.h"
#include "mainMenu.h"

class EndGameMenuQt;
class EndGameMenu : public Menu
{
private:
    int lastLevel = 0;
    int nextLevel = 0;
    bool hasCheckedLevel = false;

public:
    friend void OnEndGameMenuMainActionCall(EventParameters);
    friend void OnEndGameMenuJoystickCall(EventParameters);
    friend void OnEndGameMenuBackCall(EventParameters);

    void OnEnable();
    void OnDisable();

    EndGameMenu(EndGameMenuQt* endGameMenu);
    void changeSelection(EventParameters ep);
    void Update();
    void ShowMenu();
    void ClearMenu();
    void Selection();

    void NextLevel();
    void GotoShop();
    void GotoLevelSelect();
    void ReturnToMenu();
};

#endif