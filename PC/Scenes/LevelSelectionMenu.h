#ifndef LEVELSELECTIONMENU_H
#define LEVELSELECTIONMENU_H

#include "menu.h"
#include "game.h"

using namespace std;

class LevelSelectionMenu : public Menu
{
public:
    LevelSelectionMenu();

    friend void OnLevelSelectionMenuMainActionCall(EventParameters);
    friend void OnLevelSelectionMenuJoystickCall(EventParameters);

    void OnEnable();
    void OnDisable();

    void changeSelection(EventParameters ep);
    void ShowMenu();
    void Selection();

    void Update();
    void SelectLevel(int level);
    void Back();
    int lastMenu;
};

#endif