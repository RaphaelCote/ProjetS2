#ifndef GENERICMENU_H
#define GENERICMENU_H

#include <QtWidgets>

#include "MenuButton.h"
#include "../Affichage/Pixmaps.h"

class GenericMenu : public QWidget
{
	Q_OBJECT

public:
	int minX;
	int minY;

	GenericMenu();
	void CreateButtons(int btnQty);
	void SetChecked(int index);

protected:
	QVector<Raph_PixMap*> vectorPixMap;
	std::vector<MenuButton*> buttons;

	void paintEvent(QPaintEvent* event) override;
};

#endif