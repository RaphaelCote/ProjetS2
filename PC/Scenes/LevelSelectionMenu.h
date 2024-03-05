#ifndef LEVELSELECTIONMENU_H
#define LEVELSELECTIONMENU_H

#include "menu.h"
#include "game.h"

using namespace std;

class LevelSelectionMenu : public Menu
{
public:
    LevelSelectionMenu();
    void Update();
    void SelectLevel(int level);
    void Back();
    int lastMenu;
};

#endif