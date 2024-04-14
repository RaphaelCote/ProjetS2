#ifndef ENDGAMEMENUQT_H
#define ENDGAMEMENUQT_H

#include <QtWidgets>

#include "GenericMenu.h"
class EndGameMenu;
class EndGameMenuQt : public GenericMenu
{
	Q_OBJECT

public:
	EndGameMenuQt();
	void UpdateValues(bool isWon, int moneyGot);
	void connectButtonClicked(int buttonIndex, EndGameMenu* handler);
protected:
	QLabel* title;
	QLabel* moneyReceived;
};

#endif