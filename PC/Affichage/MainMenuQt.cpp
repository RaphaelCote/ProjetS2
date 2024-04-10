#include "MainMenuQt.h"
#include "Global.h"
#include <QtWidgets>

MainMenuQt::MainMenuQt() : GenericMenu()
{
	CreateButtons(4);

	QVBoxLayout* vbox = new QVBoxLayout();

	QPixmap logo("Images/logo.png");
	QLabel* titleLabel = new QLabel(this);
	titleLabel->setPixmap(logo.scaled(650, 200, Qt::KeepAspectRatio));
	vbox->addWidget(titleLabel);
	vbox->addItem(new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed));

	buttons[0]->setText("Jouer");
	buttons[1]->setText("Selection du niveau");
	buttons[2]->setText("Magasin");
	buttons[3]->setText("Quitter");

	vbox->addWidget(buttons[0]);
	vbox->addWidget(buttons[1]);
	vbox->addWidget(buttons[2]);
	vbox->addWidget(buttons[3]);

	vbox->setSpacing(45);
	vbox->setAlignment(Qt::AlignCenter);

	setLayout(vbox);
	update();
}