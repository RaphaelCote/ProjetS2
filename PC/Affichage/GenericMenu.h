#ifndef GENERICMENU_H
#define GENERICMENU_H

#include <QtWidgets>
#include <vector>

#include "MenuButton.h"
#include "../Affichage/Pixmaps.h"

class GenericMenu : public QWidget
{
	Q_OBJECT

public:
	int minX;
	int minY;

	GenericMenu();
	void CreateButtons(int btnQty, bool isSized);
	void SetChecked(int index);

protected:
	std::vector<Raph_PixMap*> vectorPixMap;
	std::vector<MenuButton*> buttons;

	void paintEvent(QPaintEvent* event) override;
};

#endif