#ifndef KEYBOARDCONTROLSREDIRECT_H
#define KEYBOARDCONTROLSREDIRECT_H

class KeyboardControlsRedirect
{
public:
    KeyboardControlsRedirect();

    void MainAction();
    void Back();
    void NextSelection();
    void PreviousSelection();
    void Menu();
    void Joystick(float x, float y);
    void Angle(float angle);
};

#endif