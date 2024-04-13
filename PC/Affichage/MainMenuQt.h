#ifndef MAINMENUQT_H
#define MAINMENUQT_H

#include <QtWidgets>
#include "GenericMenu.h"

class MainMenu;
class MainMenuQt : public GenericMenu
{
	Q_OBJECT

public:
    MainMenuQt();
	void connectButtonClicked(int buttonIndex, MainMenu* handler);
	
};

#endif

