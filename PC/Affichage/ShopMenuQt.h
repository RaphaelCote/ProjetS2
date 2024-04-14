#ifndef SHOPMENUQT_H
#define SHOPMENUQT_H

#include <QtWidgets>

#include "GenericMenu.h"
#include "inventory.h"
class ShopMenu;
class ShopMenuQt : public GenericMenu
{
	Q_OBJECT

public:
	ShopMenuQt();
	void UpdateValues();
	void connectButtonClicked(int buttonIndex, Inventory* handler);

protected:
	QLabel* moneyLabel;
	QLabel* shieldLabel;
	QLabel* RocketInfo;
	QLabel* GrenadeInfo;

	QLabel* PotInfo1;
	QLabel* PotInfo2;
	QLabel* PotInfo3;
};

#endif