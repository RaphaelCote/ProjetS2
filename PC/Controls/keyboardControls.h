#ifndef KEYBOARDCONTROLS_H
#define KEYBOARDCONTROLS_H

#include "controls.h"

using namespace std;

class KeyboardControls : public Controls
{
public:
    KeyboardControls(EventManager *em);
    void ListenForControls();
};

#endif