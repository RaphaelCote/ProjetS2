#include "UpdateValuesEvent.h"
#include "Global.h"
#include <QtWidgets>

UpdateValuesEvent::UpdateValuesEvent(int index) : QEvent(UpdateValuesEvent::updateValues)
{
	this->index = index;
}