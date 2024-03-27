#include "controls.h"

Controls::Controls(EventManager *em)
{
    this->eventManager = em;
}

void Controls::ListenForControls()
{
}

void Controls::MainAction()
{
    eventManager->emit("MainAction", EventParameters());
}

void Controls::Back()
{
    eventManager->emit("Back", EventParameters());
}

void Controls::NextSelection()
{
    eventManager->emit("NextSelection", EventParameters());
}

void Controls::PreviousSelection()
{
    eventManager->emit("PreviousSelection", EventParameters());
}

void Controls::Menu()
{
    eventManager->emit("Menu", EventParameters());
}

void Controls::Joystick(float x, float y)
{
    if (x > 1)
    {
        x = 1;
    }
    if (y > 1)
    {
        y = 1;
    }
    eventManager->emit("Joystick", EventParameters(x, y));
}

void Controls::Angle(float angle)
{
    if (angle > 90)
    {
        angle = 90;
    }
    if (angle < 0)
    {
        angle = 0;
    }
    eventManager->emit("Angle", EventParameters(angle));
}