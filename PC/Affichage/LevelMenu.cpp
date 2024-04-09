#include "LevelMenu.h"
#include "Global.h"
#include <QtWidgets>

LevelMenu::LevelMenu() : GenericMenu()
{
	CreateButtons(levelQty+1);

	QVBoxLayout* vbox = new QVBoxLayout();

	for (int i = 0; i <= levelQty; i++) {
		if (i == levelQty) {
			buttons[i]->setText("Retour");
		}
		else {
			QString text = "Niveau ";
			text += std::to_string(i + 1);
			buttons[i]->setText(text);

		}
		vbox->addWidget(buttons[i]);
	}

	vbox->setSpacing(45);
	vbox->setAlignment(Qt::AlignCenter);

	setLayout(vbox);
	update();
}