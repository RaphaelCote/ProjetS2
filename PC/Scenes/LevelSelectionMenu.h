#ifndef LEVELSELECTIONMENU_H
#define LEVELSELECTIONMENU_H

#include "menu.h"
#include "game.h"

using namespace std;

class LevelSelectionMenu : public Menu
{
public:
    int lastMenu = 0;

    friend void OnLevelSelectionMenuMainActionCall(EventParameters);
    friend void OnLevelSelectionMenuJoystickCall(EventParameters);
    friend void OnLevelSelectionMenuBackCall(EventParameters);

    void OnEnable();
    void OnDisable();

    LevelSelectionMenu();
    void changeSelection(EventParameters ep);
    void Update();
    void ShowMenu();
    void Selection();

    void SelectLevel(int level);
    void Back();
};

#endif