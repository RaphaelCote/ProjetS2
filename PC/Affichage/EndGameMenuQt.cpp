#include "EndGameMenu.h"
#include "EndGameMenuQt.h"
#include "Global.h"
#include <QtWidgets>

EndGameMenuQt::EndGameMenuQt() : GenericMenu()
{
	CreateButtons(4, true);

	QVBoxLayout* vbox = new QVBoxLayout();

	title = new QLabel("Vous avez kjbhgc!", this);
	title->setStyleSheet("QLabel {"
		" font: 30pt 'Cooper Black'; "
		"qproperty-alignment: 'AlignCenter';"
		" min-width: 0px;"
		" max - width: 10000px; }");
	title->setAlignment(Qt::AlignCenter);

	vbox->addWidget(title);

	moneyReceived = new QLabel("Vous avez recu x$", this);
	moneyReceived->setStyleSheet("QLabel {"
		" font: 20pt 'Cooper Black'; "
		"qproperty-alignment: 'AlignCenter';"
		" min-width: 0px;"
		" max - width: 10000px; }");
	moneyReceived->setAlignment(Qt::AlignCenter);

	vbox->addWidget(moneyReceived);

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

void EndGameMenuQt::UpdateValues(bool isWon, int moneyGot) {
	if (isWon) {
		title->setText("Vous avez gagnez!");
	}
	else {
		title->setText("Vous avez perdu.");
	}

	moneyReceived->setText("Vous avez recu "+ QString::number(moneyGot)+ "$");

	update();
}
void EndGameMenuQt::connectButtonClicked(int buttonIndex, EndGameMenu* handler)
{
	
	
	QPushButton* button = nullptr;
	switch (buttonIndex) {
	case 0:
		button = buttons[0];
		connect(button, &QPushButton::clicked, [handler]()
			{
				handler->NextLevel();
			}
		);
		return;
	case 1:
		button = buttons[1];
		connect(button, &QPushButton::clicked, [handler]()
			{
				handler->GotoLevelSelect();
			}
		);
		return;
	case 2:
		button = buttons[2];
		connect(button, &QPushButton::clicked, [handler]()
			{
				handler->GotoShop();
			}
		);
		return;
	case 3:
		button = buttons[3];
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