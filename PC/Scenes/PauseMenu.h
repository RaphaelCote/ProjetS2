#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include "menu.h"

using namespace std;

class PauseMenu : public Menu
{
public:
    PauseMenu();
    void Update();
    void Continu();
    void ReturnToMenu();
};

#endif