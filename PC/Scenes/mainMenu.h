#ifndef MAINMENU_H
#define MAINMENU_H

#include "menu.h"
#include "../Controls/eventParameters.h"

using namespace std;

class MainMenu : public Menu
{
private:
    bool doOnce = true;

public:
    friend void OnMainMenuMainActionCall(EventParameters);
    friend void OnMainMenuJoystickCall(EventParameters);

    void OnEnable();
    void OnDisable();

    MainMenu();
    void changeSelection(EventParameters ep);
    void Update();
    void ShowMenu();
    void Selection();

    void PlayGame();
    void GotoLevelSelect();
    void GotoShop();
    void ExitGame();
};

#endif