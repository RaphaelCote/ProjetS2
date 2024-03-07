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
    else if (input == "q")
    {
        PreviousSelection();
    }
    else if (input == "e")
    {
        NextSelection();
    }
    else if (input == "p")
    {
        Menu();
    }
    else if (input == "b")
    {
        Back();
    }
    else if (input == "1")
    {
        float angle;
        cout << "Veuillez entrer un angle : ";
        cin >> angle;

        Angle(angle);
    }
    else if (input == "2")
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