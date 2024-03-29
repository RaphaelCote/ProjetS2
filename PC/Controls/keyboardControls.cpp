#include "keyboardControls.h"
#include "../raftWars.h"
#include <conio.h>

KeyboardControls::KeyboardControls(EventManager *em) : Controls(em)
{
    // HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    // CONSOLE_CURSOR_INFO cursorInfo;
    // GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    // cursorInfo.bVisible = false;
    // SetConsoleCursorInfo(consoleHandle, &cursorInfo);

    // Set the console mode to allow non-blocking input
    // DWORD mode;
    // GetConsoleMode(consoleHandle, &mode);
    // SetConsoleMode(consoleHandle, mode & (~ENABLE_ECHO_INPUT) & (~ENABLE_LINE_INPUT));
}

void KeyboardControls::ListenForControls()
{
    // cout << "Veuillez entrer votre action : ";
    string input = "+";
    // cin >> input;
    int x = 2;
    int y = cons->MaxRows - 11;

    if (_kbhit())
    {
        cons->SupprimerObjet("key");

        // Read the pressed key
        char inputChar = _getch();

        input = inputChar;

        // string s = "You pressed: -" + input;
        // s += "- ";
        // cons->AfficherTexte(cout, s, &x, &y, "key");

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
        else if (input == "q" && activeScene == 1)
        {
            PreviousSelection();
        }
        else if (input == "e" && activeScene == 1)
        {
            NextSelection();
        }
        else if (input == "p" && activeScene == 1)
        {
            Menu();
        }
        else if (input == "b")
        {
            Back();
        }
        else if (input == "1" && activeScene == 1)
        {
            float angle;
            // cout << "Veuillez entrer un angle : ";
            // cin >> angle;

            Angle(angle);
        }
        else if (input == "2" && activeScene == 1)
        {
            float joystickX;
            float joystickY;
            // cout << "Veuillez entrer un x de Joystick : ";
            // cin >> joystickX;
            // cout << "Veuillez entrer un y de Joystick : ";
            // cin >> joystickY;

            Joystick(joystickX, joystickY);
        }
    }
}