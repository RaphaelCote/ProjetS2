#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QtWidgets>

class MenuButton : public QPushButton
{
	Q_OBJECT

public:
	MenuButton(const QString& text, QWidget* parent = nullptr);

};

#endif