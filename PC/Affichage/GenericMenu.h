#ifndef GENERICMENU_H
#define GENERICMENU_H

#include <QtWidgets>

#include "MenuButton.h"
#include "../Game/utility.h"

struct Frank_PixMap
{
	QPixmap pix;
	Coordonnee coor;
	Hitbox box;
	int rotation;
	int couche;
	QString name;
};

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
	QVector<Frank_PixMap*> vectorPixMap;
	std::vector<MenuButton*> buttons;

	void paintEvent(QPaintEvent* event) override;
};

#endif