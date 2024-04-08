#ifndef KEYBOARDCONTROLS_H
#define KEYBOARDCONTROLS_H

#include "controls.h"


class KeyboardControls : public Controls
{
public:
    KeyboardControls(EventManager *em);
    void ListenForControls();
    void ReceiveSerial() {};
   
};

#endif