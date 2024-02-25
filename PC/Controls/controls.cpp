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
    cout << "calling joystick" << endl;
    eventManager->emit("Joystick", EventParameters(x, y));
}

void Controls::Angle(float angle)
{
    eventManager->emit("Angle", EventParameters(angle));
}