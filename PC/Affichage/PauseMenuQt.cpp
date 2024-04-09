#include "PauseMenuQt.h"
#include "Global.h"
#include <QtWidgets>

PauseMenuQt::PauseMenuQt() : GenericMenu()
{
	CreateButtons(2, true);

	QVBoxLayout* vbox = new QVBoxLayout();

	buttons[0]->setText("Continuer");
	buttons[1]->setText("Retour au menu");

	vbox->addWidget(buttons[0]);
	vbox->addWidget(buttons[1]);

	vbox->setSpacing(45);
	vbox->setAlignment(Qt::AlignCenter);

	setLayout(vbox);
	update();
}