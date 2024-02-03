#include "controls.h"
#include "controlEvents.h"

Controls::Controls(ControlEvents ce)
{
    this->controlEvents = ce;
}

void Controls::MainAction()
{
    __raise controlEvents.MainAction();
}

void Controls::Back()
{
    __raise controlEvents.Back();
}

void Controls::NextSelection()
{
    __raise controlEvents.NextSelection();
}

void Controls::PreviousSelection()
{
    __raise controlEvents.PreviousSelection();
}

void Controls::Menu()
{
    __raise controlEvents.Menu();
}

void Controls::Joystick(float x, float y)
{
    __raise controlEvents.Joystick(x, y);
}

void Controls::Angle(float angle)
{
    __raise controlEvents.Angle(angle);
}