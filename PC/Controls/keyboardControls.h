#ifndef KEYBOARDCONTROLS_H
#define KEAYBOARDCONTROLS_H

#include "controls.h"

using namespace std;

class KeyboardControls : public Controls
{
public:
    void ListenForControls();
};

#endif