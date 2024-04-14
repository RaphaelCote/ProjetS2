#ifndef LEVELMENU_H
#define LEVELMENU_H

#include <QtWidgets>

#include "GenericMenu.h"
class LevelSelectionMenu;
class LevelMenu : public GenericMenu
{
	Q_OBJECT

public:
	LevelMenu();
	void connectButtonClicked(LevelSelectionMenu* handler);
};

#endif