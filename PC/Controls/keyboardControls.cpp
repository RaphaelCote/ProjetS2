#include "keyboardControls.h"

void KeyboardControls::ListenForControls()
{
    string input;
    cin >> input;

    if (input == " ")
    {
        MainAction();
    }
    else if (input == "w")
    {
        Joystick(0, 1);
    }
    else if (input == "s")
    {
        Joystick(0, -1);
    }
}