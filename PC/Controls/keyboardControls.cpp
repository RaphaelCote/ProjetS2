#include "keyboardControls.h"

KeyboardControls::KeyboardControls(EventManager *em) : Controls(em)
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
    else if (input == "n")
    {
        PreviousSelection();
    }
    else if (input == "m")
    {
        NextSelection();
    }
    else if (input == "p")
    {
        Menu();
    }
    else if (input == "u")
    {
        float angle;
        cout << "Veuillez entrer un angle : ";
        cin >> angle;

        Angle(angle);
    }
    else if (input == "i")
    {
        float joystickX;
        float joystickY;
        cout << "Veuillez entrer un x de Joystick : ";
        cin >> joystickX;
        cout << "Veuillez entrer un y de Joystick : ";
        cin >> joystickY;

        Joystick(joystickX, joystickY);
    }
}