#include "LevelMenu.h"
#include "Global.h"
#include <QtWidgets>

LevelMenu::LevelMenu() : GenericMenu()
{
	CreateButtons(levelQty+1, true);

	for (int i = 0; i <= levelQty; i++) {
		if (i == levelQty) {
			buttons[i]->setText("Retour");
		}
		else {
			QString text = "Niveau ";
			text += std::to_string(i + 1);
			buttons[i]->setText(text);
		}
	}

	if (levelQty < 3) {

		QVBoxLayout* layout = new QVBoxLayout();

		for (int i = 0; i <= levelQty; i++) {

			layout->addWidget(buttons[i]);
		}

		layout->setSpacing(45);
		layout->setAlignment(Qt::AlignCenter);

		setLayout(layout);
	}
	else {
		QGridLayout* layout = new QGridLayout();

		for (int i = 0; i <= levelQty; i++) {

			if (i < ceil((levelQty + 1) / 2)) {
				layout->addWidget(buttons[i], i, 1);
			}
			else {
				layout->addWidget(buttons[i], (i- ceil((levelQty + 1) / 2)), 2);
			}
		}
		layout->setSpacing(45);
		layout->setAlignment(Qt::AlignCenter);

		setLayout(layout);
	}

	update();
}