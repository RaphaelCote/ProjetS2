#include "MenuButton.h"
#include <QtWidgets>

MenuButton::MenuButton(const QString& text, QWidget* parent) : QPushButton(text, parent)
{
	int widthPercentage = 100; // 50% of parent's width
	QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
	//sizePolicy.setHorizontalStretch(widthPercentage);
	sizePolicy.setHorizontalPolicy(QSizePolicy::Expanding);

	setMinimumWidth(600);
	setMinimumHeight(80);

	setMaximumWidth(600);
	setMaximumHeight(130);

	setSizePolicy(sizePolicy);

	setStyleSheet("QPushButton {"
		" border:4px outset; "
		" border-radius: 8px; "
		" border-color: rgb(255, 160, 48); "
		" color:rgb(0, 0, 0); "
		" background-color: rgb(255, 74, 49);  "
		" opacity : 150; "
		" font: 24pt 'Cooper Black'; "
		" min-width: 0px;"
		" max - width: 10000px; }"
		"QPushButton:checked {"
		" background-color: rgb(3, 215, 252); }"
	);
}
