#include "controls.h"

Controls::Controls(EventManager *em)
{
    this->eventManager = em;
}

void Controls::MainAction()
{
    eventManager->emit("event", EventParameters());
}

void Controls::Back()
{
    eventManager->emit("event", EventParameters());
}

void Controls::NextSelection()
{
    eventManager->emit("event", EventParameters());
}

void Controls::PreviousSelection()
{
    eventManager->emit("event", EventParameters());
}

void Controls::Menu()
{
    eventManager->emit("event", EventParameters());
}

void Controls::Joystick(float x, float y)
{
    eventManager->emit("event", EventParameters());
}

void Controls::Angle(float angle)
{
    eventManager->emit("event", EventParameters());
}