#ifndef MENU_H
#define MENU_H

#include "../Controls/EventParameters.h"
#include "scene.h"


class Menu : public Scene
{

public:
    Menu();

    virtual void changeSelection(EventParameters ep) = 0;
    virtual void ShowMenu() = 0;
    virtual void ClearMenu() = 0;
    virtual void Selection() = 0;

    int choice = 0;

protected:
    
    bool doOnce = true;
};

#endif