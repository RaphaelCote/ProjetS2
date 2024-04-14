#ifndef LEVELSELECTIONMENU_H
#define LEVELSELECTIONMENU_H

#include "menu.h"
#include "game.h"

class LevelMenu;
class LevelSelectionMenu : public Menu
{
public:
    int lastMenu = 0;

    friend void OnLevelSelectionMenuMainActionCall(EventParameters);
    friend void OnLevelSelectionMenuJoystickCall(EventParameters);
    friend void OnLevelSelectionMenuBackCall(EventParameters);

    void OnEnable();
    void OnDisable();

    LevelSelectionMenu(LevelMenu *levelSelectQt);
    void changeSelection(EventParameters ep);
    void Update();
    void ShowMenu();
    void ClearMenu();
    void Selection();

    void choixNiveau(int choix);

    void SelectLevel(int level);
    void Back();
};

#endif