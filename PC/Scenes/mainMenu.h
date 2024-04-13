#ifndef MAINMENU_H
#define MAINMENU_H

#include "menu.h"
#include "../Controls/eventParameters.h"


class MainMenuQt;

class MainMenu : public Menu
{
public:
    friend void OnMainMenuMainActionCall(EventParameters);
    friend void OnMainMenuJoystickCall(EventParameters);

    void OnEnable();
    void OnDisable();

    MainMenu(MainMenuQt* mainMenu);
    void changeSelection(EventParameters ep);
    void Update();
    void ShowMenu();
    void ClearMenu();
    void Selection();

    void PlayGame();
    void GotoLevelSelect();
    void GotoShop();
    void ExitGame();
};

#endif

