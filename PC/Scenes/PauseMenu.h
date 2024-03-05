#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include "menu.h"


using namespace std;

class PauseMenu : public Menu
{
public:
    PauseMenu();

    friend void OnPauseMenuMainActionCall(EventParameters);
    friend void OnPauseMenuJoystickCall(EventParameters);

    void OnEnable();
    void OnDisable();

    void changeSelection(EventParameters ep);
    void ShowMenu();
    void Selection();

    void Update();
    void Continu();
    void ReturnToMenu();
};

#endif