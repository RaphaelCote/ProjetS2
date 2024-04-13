#ifndef MAINMENUQT_H
#define MAINMENUQT_H

#include <QtWidgets>
#include "mainMenu.h"
#include "menu.h"
#include "GenericMenu.h"

class MainMenuQt : public GenericMenu
{
	Q_OBJECT

public:
    MainMenuQt();
	MainMenu* mainMenu;
	//void emitPlayGamePressed();
	void PLAYGAMEPRESSED();

	
	/*void levelSelectionPressed();
	void shopPressed();
	void closePressed();*/

};

#endif