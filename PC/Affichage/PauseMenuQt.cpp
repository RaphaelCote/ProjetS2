#include "PauseMenuQt.h"
#include "Global.h"
#include "PauseMenu.h"
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
void PauseMenuQt::connectButtonClicked(int buttonIndex, PauseMenu* handler)
{
	QPushButton* button = nullptr;
	switch (buttonIndex) {
	case 0:
		button = buttons[0];
		connect(button, &QPushButton::clicked, [handler]()
			{
				handler->Continu();
			}
		);
		return;
	case 1:
		button = buttons[1];
		connect(button, &QPushButton::clicked, [handler]()
			{
				handler->ReturnToMenu();
			}
		);
		return;
	default:
		return; // Invalid button index
	}
}
