#include "LevelMenu.h"
#include "Global.h"
#include <QtWidgets>

LevelMenu::LevelMenu() : GenericMenu()
{
	CreateButtons(levelQty+1);

	QVBoxLayout* vbox = new QVBoxLayout();

	QPixmap logo("C:/home/DEVUniversite/ProjetS2/Images/logo.png");
	QLabel* titleLabel = new QLabel(this);
	titleLabel->setPixmap(logo.scaled(650, 200, Qt::KeepAspectRatio));
	vbox->addWidget(titleLabel);
	vbox->addItem(new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed));

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