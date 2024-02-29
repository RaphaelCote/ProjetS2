#ifndef MENU_H
#define MENU_H

#include "../Controls/EventParameters.h"
#include "scene.h"

using namespace std;

class Menu : public Scene
{

public:
    Menu();

    virtual void changeSelection(EventParameters ep) = 0;
    virtual void ShowMenu() = 0;
    virtual void Selection() = 0;

protected:
    int choice = 0;
};

#endif