#ifndef KEYBOARDCONTROLS_H
#define KEYBOARDCONTROLS_H

#include "controls.h"


class KeyboardControls : public Controls
{
public:
    float angleKeyboard = 45;
    float puissanceKeyboard = 0.5;

    KeyboardControls(EventManager *em);
    void ListenForControls();
    void ReceiveSerial() {};
   
};

#endif