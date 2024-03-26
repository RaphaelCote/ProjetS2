#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include "menu.h"

using namespace std;

class PauseMenu : public Menu
{
public:
    friend void OnPauseMenuMainActionCall(EventParameters);
    friend void OnPauseMenuJoystickCall(EventParameters);
    friend void OnPauseMenuBackCall(EventParameters);

    void OnEnable();
    void OnDisable();

    PauseMenu();
    void changeSelection(EventParameters ep);
    void Update();
    void ShowMenu();
    void ClearMenu();
    void Selection();

    void Continu();
    void ReturnToMenu();
};

#endif