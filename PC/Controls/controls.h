#ifndef CONTROLS_H
#define CONTROLS_H

// #include <iostream>
#include "controlEvents.h"

// using namespace std;

class Controls
{
public:
    ControlEvents controlEvents;
    Controls(ControlEvents ce);
    virtual void ListenForControls();

private:
    void MainAction();
    void Back();
    void NextSelection();
    void PreviousSelection();
    void Menu();
    void Joystick(float x, float y);
    void Angle(float angle);
};

#endif