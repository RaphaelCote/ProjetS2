#include "EndGameMenuQt.h"
#include "Global.h"
#include <QtWidgets>

EndGameMenuQt::EndGameMenuQt() : GenericMenu()
{
	CreateButtons(4, true);

	QVBoxLayout* vbox = new QVBoxLayout();

	buttons[0]->setText("Prochain Niveau");
	buttons[1]->setText("Selection de niveau");
	buttons[2]->setText("Magasin");
	buttons[3]->setText("Retour au menu");

	vbox->addWidget(buttons[0]);
	vbox->addWidget(buttons[1]);
	vbox->addWidget(buttons[2]);
	vbox->addWidget(buttons[3]);

	vbox->setSpacing(45);
	vbox->setAlignment(Qt::AlignCenter);

	setLayout(vbox);
	update();
}