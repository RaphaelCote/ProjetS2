#include "keyboardControls.h"

KeyboardControls::KeyboardControls(EventManager *em):Controls(em)
{
}

void KeyboardControls::ListenForControls()
{
    cout << "Veuillez entrer votre action : ";
    string input;
    cin >> input;

    if (input == "l")
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