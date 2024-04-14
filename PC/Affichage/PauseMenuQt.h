#ifndef PAUSEMENUQT_H
#define PAUSEMENUQT_H

#include <QtWidgets>

#include "GenericMenu.h"
class PauseMenu;
class PauseMenuQt : public GenericMenu
{
	Q_OBJECT

public:
	PauseMenuQt();
	void connectButtonClicked(int buttonIndex, PauseMenu* handler);
};

#endif