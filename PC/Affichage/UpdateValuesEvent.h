#ifndef UPDATEVALUESEVENT_H
#define UPDATEVALUESEVENT_H

#include <QtWidgets>

#include "GenericMenu.h"

class UpdateValuesEvent : public QEvent
{
public:
	int index;

	UpdateValuesEvent(int index);

	static const QEvent::Type updateValues = (QEvent::Type)1001;
};

#endif