#include "ShowContentEvent.h"
#include "Global.h"
#include <QtWidgets>

ShowContentEvent::ShowContentEvent(int index) : QEvent(QEvent::User)
{
	this->index = index;
}