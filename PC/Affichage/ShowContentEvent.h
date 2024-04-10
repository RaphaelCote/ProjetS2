#ifndef SHOWCONTENTEVENT_H
#define SHOWCONTENTEVENT_H

#include <QtWidgets>

#include "GenericMenu.h"

class ShowContentEvent : public QEvent
{
public:
	int index;

	ShowContentEvent(int index);

	static const QEvent::Type showContent = QEvent::User;
};

#endif