#include "controls.h"

Controls::Controls(EventManager *em)
{
    this->eventManager = em;
}

void Controls::MainAction()
{
    eventManager->emit("event", 100);
}

void Controls::Back()
{
    eventManager->emit("event", 100);
}

void Controls::NextSelection()
{
    eventManager->emit("event", 100);
}

void Controls::PreviousSelection()
{
    eventManager->emit("event", 100);
}

void Controls::Menu()
{
    eventManager->emit("event", 100);
}

void Controls::Joystick(float x, float y)
{
    eventManager->emit("event", 100);
}

void Controls::Angle(float angle)
{
    eventManager->emit("event", 100);
}