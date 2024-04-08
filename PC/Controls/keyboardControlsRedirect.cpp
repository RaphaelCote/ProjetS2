#include "keyboardControlsRedirect.h"
#include "../raftWars.h"

KeyboardControlsRedirect::KeyboardControlsRedirect()
{
}

void KeyboardControlsRedirect::MainAction()
{
    controls->MainAction();
}

void KeyboardControlsRedirect::Back()
{
    controls->Back();
}

void KeyboardControlsRedirect::NextSelection()
{
    controls->NextSelection();
}

void KeyboardControlsRedirect::PreviousSelection()
{
    controls->PreviousSelection();
}

void KeyboardControlsRedirect::Menu()
{
    controls->Menu();
}

void KeyboardControlsRedirect::Joystick(float x, float y)
{
    controls->Joystick(x, y);
}

void KeyboardControlsRedirect::Angle(float angle)
{
    controls->Angle(angle);
}