#include "ShopMenuQt.h"
#include "Global.h"
#include <QtWidgets>


ShopMenuQt::ShopMenuQt() : GenericMenu()
{
	CreateButtons(6, false);

	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->setAlignment(Qt::AlignCenter);

	moneyLabel = new QLabel("Argent : " + QString::number(inventory->getGold()), this);
	moneyLabel->setStyleSheet("QLabel {"
			" border:4px outset; "
			" border-radius: 8px; "
			" border-color: solid black; "
		//	" color:rgb(0, 0, 0); "
			" background-color: lightblue;  "
		" opacity : 150; "
		" font: 24pt 'Cooper Black'; "
		"qproperty-alignment: 'AlignCenter';"
		" min-width: 0px;"
		" max - width: 10000px; }");
	moneyLabel->setAlignment(Qt::AlignRight);

	// Ajouter le QLabel dans un QHBoxLayout pour le positionner en haut à droite
	QHBoxLayout* moneyLayout = new QHBoxLayout();
	moneyLayout->addStretch(); // Ajouter un espace flexible pour pousser le QLabel à droite
	moneyLayout->addWidget(moneyLabel);

	// Ajouter le QHBoxLayout contenant le QLabel en haut à droite de gameWindow
	mainLayout->addLayout(moneyLayout);

	shieldLabel = new QLabel("Shield : " + QString::number(inventory->getShield()) + " PV", this);
	shieldLabel->setStyleSheet("QLabel {"
		" border:4px outset; "
		" border-radius: 8px; "
		" border-color: solid black; "
		//	" color:rgb(0, 0, 0); "
		" background-color: lightblue;  "
		" opacity : 150; "
		" font: 24pt 'Cooper Black'; "
		"qproperty-alignment: 'AlignCenter';"
		" min-width: 0px;"
		" max - width: 10000px; }");
	shieldLabel->setAlignment(Qt::AlignRight);

	// Ajouter le QLabel dans un QHBoxLayout pour le positionner en haut à droite
	QHBoxLayout* shieldLayout = new QHBoxLayout();
	shieldLayout->addStretch(); // Ajouter un espace flexible pour pousser le QLabel à droite
	shieldLayout->addWidget(shieldLabel);

	// Ajouter le QHBoxLayout contenant le QLabel en haut à droite de gameWindow
	mainLayout->addLayout(shieldLayout);

	// Créer un widget pour contenir le reste du contenu
	QWidget* contentWidget = new QWidget(gameWindow);
	QVBoxLayout* Vlayout = new QVBoxLayout(contentWidget);
	Vlayout->setAlignment(Qt::AlignCenter);
	QHBoxLayout* Hlayout3 = new QHBoxLayout(gameWindow);
	


	QWidget* rocketWidget = new QWidget(gameWindow);
	rocketWidget->setStyleSheet("background-color: lightblue; border: 2px solid black; padding: 10px; max-width:1050; max-height: 1500;");
	QWidget* itemInfo = new QWidget(gameWindow);
	itemInfo->setStyleSheet("background-color: lightblue; border: 2px solid black; padding: 10px; max-width:1050; max-height: 1500;");
	QHBoxLayout* Hlayout1 = new QHBoxLayout(rocketWidget);


	QHBoxLayout* Hlayout2 = new QHBoxLayout(itemInfo);


	QPixmap rocket("Images/Projectile/Missile.png");
	QLabel* RocketImage = new QLabel(gameWindow);
	RocketImage->setPixmap(rocket.scaled(300, 200, Qt::KeepAspectRatio));				// Scale logo
	RocketImage->setAlignment(Qt::AlignCenter);
	Hlayout1->addWidget(RocketImage);


	QPixmap Grenade("Images/Projectile/Grenade.png");
	QLabel* GrenadeImage = new QLabel(gameWindow);
	GrenadeImage->setPixmap(Grenade.scaled(280, 70, Qt::KeepAspectRatio));				// Scale logo
	GrenadeImage->setAlignment(Qt::AlignCenter);
	Hlayout1->addWidget(GrenadeImage);
	Vlayout->addLayout(Hlayout1);

	Vlayout->addWidget(rocketWidget);


	RocketInfo = new QLabel("Roquette\nPrix : " + QString::number(inventory->GetPrixRocket()) + "$\n Possede : "+ QString::number(inventory->getRockets()) + ", max 2", gameWindow);
	GrenadeInfo = new QLabel("Grenade\nPrix : " + QString::number(inventory->GetPrixGrenade()) + "$\n Possede : " + QString::number(inventory->getGrenade()) + ", max 2", gameWindow);
	if (inventory->getRockets() >= 2) {
		RocketInfo->setStyleSheet("QLabel {"
			"border: 2px solid red;"
			" opacity : 150; "
			" font: 14pt 'Cooper Black'; "
			"qproperty-alignment: 'AlignCenter';"
			" min-width: 0px;"
			" max - width: 10000px; }");
	}
	else {
		RocketInfo->setStyleSheet("QLabel {"
			"border: 2px solid black;"
			" opacity : 150; "
			" font: 14pt 'Cooper Black'; "
			"qproperty-alignment: 'AlignCenter';"
			" min-width: 0px;"
			" max - width: 10000px; }");
	}

	if (inventory->getGrenade() >= 2) {
		GrenadeInfo->setStyleSheet("QLabel {"
			"border: 2px solid red;"
			" opacity : 150; "
			" font: 14pt 'Cooper Black'; "
			"qproperty-alignment: 'AlignCenter';"
			" min-width: 0px;"
			" max - width: 10000px; }");
	}
	else {
		GrenadeInfo->setStyleSheet("QLabel {"
			"border: 2px solid black;"
			" opacity : 150; "
			" font: 14pt 'Cooper Black'; "
			"qproperty-alignment: 'AlignCenter';"
			" min-width: 0px;"
			" max - width: 10000px; }");
	}

	Hlayout2->addWidget(RocketInfo);
	Hlayout2->addWidget(GrenadeInfo);

	Vlayout->addLayout(Hlayout2);
	//Vlayout->addSpacing(0.1);
	Vlayout->addWidget(itemInfo);

	buttons[0]->setText("Acheter");
	buttons[1]->setText("Acheter");
	buttons[2]->setText("Acheter");
	buttons[3]->setText("Acheter");
	buttons[4]->setText("Acheter");
	buttons[5]->setText("Retour");

	Hlayout3->addWidget(buttons[0]);
	Hlayout3->addWidget(buttons[1]);
	Vlayout->addLayout(Hlayout3);
	Vlayout->addSpacing(30);

	QWidget* PotionWidget = new QWidget(gameWindow);
	PotionWidget->setStyleSheet("background-color: lightblue; border: 2px solid black; padding: 10px; max-width:1050; max-height: 1500;");
	QWidget* PotionInfo = new QWidget(gameWindow);
	PotionInfo->setStyleSheet("background-color: lightblue; border: 2px solid black; padding: 10px; max-width:1500; max-height: 1500;");
	QHBoxLayout* Hlayout4 = new QHBoxLayout(PotionWidget);
	QHBoxLayout* Hlayout5 = new QHBoxLayout(PotionInfo);

	QPixmap potion1("Images/SmallPot.png");
	QLabel* smallPot = new QLabel(gameWindow);
	smallPot->setPixmap(potion1.scaled(280, 80, Qt::KeepAspectRatio));
	smallPot->setAlignment(Qt::AlignCenter);

	QPixmap potion2("Images/MedPot.png");
	QLabel* medPot = new QLabel(gameWindow);
	medPot->setPixmap(potion2.scaled(280, 80, Qt::KeepAspectRatio));
	medPot->setAlignment(Qt::AlignCenter);

	QPixmap potion3("Images/BigPot.png");
	QLabel* bigPot = new QLabel(gameWindow);
	bigPot->setPixmap(potion3.scaled(280, 70, Qt::KeepAspectRatio));
	bigPot->setAlignment(Qt::AlignCenter);

	Hlayout4->addWidget(smallPot);
	Hlayout4->addWidget(medPot);
	Hlayout4->addWidget(bigPot);
	Vlayout->addLayout(Hlayout4);
	Vlayout->addWidget(PotionWidget);

	PotInfo1 = new QLabel("Petite potion\nAjoute 25PV, max 50\nPrix : " + QString::number(inventory->GetPrixShieldSmall()) + "$ ", gameWindow);
	PotInfo2 = new QLabel("Moyenne potion\nAjoute 50PV, max 100\nPrix : " + QString::number(inventory->GetPrixShieldMedium()) + "$", gameWindow);
	PotInfo3 = new QLabel("Enorme potion\nAjoute 100PV, max 100\nPrix : " + QString::number(inventory->GetPrixShieldBig()) + "$", gameWindow);

	if (inventory->getShield() >= 50) {
		PotInfo1->setStyleSheet("QLabel {"
			"border: 2px solid red;"
			" opacity : 150; "
			" font: 14pt 'Cooper Black'; "
			"qproperty-alignment: 'AlignCenter';"
			" min-width: 0px;"
			" max-width: 1050px; }"
			"background-color: red;");

		if (inventory->getShield() >= 100) {
			PotInfo2->setStyleSheet("QLabel {"
				"border: 2px solid red;"
				" opacity : 150; "
				" font: 14pt 'Cooper Black'; "
				"qproperty-alignment: 'AlignCenter';"
				" min-width: 0px;"
				" max-width: 1050px; }"
				"background-color: red;");
			PotInfo3->setStyleSheet("QLabel {"
				"border: 2px solid red;"
				" opacity : 150; "
				" font: 14pt 'Cooper Black'; "
				"qproperty-alignment: 'AlignCenter';"
				" min-width: 0px;"
				" max-width: 1050px; }"
				"background-color: red;");
		}
		else {
			PotInfo2->setStyleSheet("QLabel {"
				"border: 2px solid black;"
				" opacity : 150; "
				" font: 14pt 'Cooper Black'; "
				"qproperty-alignment: 'AlignCenter';"
				" min-width: 0px;"
				" max-width: 1050px; }"
				"background-color: lightblue;");
			PotInfo3->setStyleSheet("QLabel {"
				"border: 2px solid black;"
				" opacity : 150; "
				" font: 14pt 'Cooper Black'; "
				"qproperty-alignment: 'AlignCenter';"
				" min-width: 0px;"
				" max-width: 1050px; }"
				"background-color: lightblue;");
		}
	}
	else {
		PotInfo1->setStyleSheet("QLabel {"
			"border: 2px solid black;"
			" opacity : 150; "
			" font: 14pt 'Cooper Black'; "
			"qproperty-alignment: 'AlignCenter';"
			" min-width: 0px;"
			" max-width: 1050px; }"
			"background-color: lightblue;");
		PotInfo2->setStyleSheet("QLabel {"
			"border: 2px solid black;"
			" opacity : 150; "
			" font: 14pt 'Cooper Black'; "
			"qproperty-alignment: 'AlignCenter';"
			" min-width: 0px;"
			" max-width: 1050px; }"
			"background-color: lightblue;");
		PotInfo3->setStyleSheet("QLabel {"
			"border: 2px solid black;"
			" opacity : 150; "
			" font: 14pt 'Cooper Black'; "
			"qproperty-alignment: 'AlignCenter';"
			" min-width: 0px;"
			" max-width: 1050px; }"
			"background-color: lightblue;");
	}

	Hlayout5->addWidget(PotInfo1);
	Hlayout5->addWidget(PotInfo2);
	Hlayout5->addWidget(PotInfo3);
	Vlayout->addLayout(Hlayout5);
	Vlayout->addWidget(PotionInfo);

	QHBoxLayout* Hlayout6 = new QHBoxLayout(gameWindow);
	Hlayout6->addWidget(buttons[2]);
	Hlayout6->addWidget(buttons[3]);
	Hlayout6->addWidget(buttons[4]);
	Vlayout->addLayout(Hlayout6);

	Vlayout->addSpacing(20);
	Vlayout->addWidget(buttons[5]);

	mainLayout->addWidget(contentWidget);
	setLayout(mainLayout);
	update();
}

void ShopMenuQt::UpdateValues() {
	moneyLabel->setText("Argent : " + QString::number(inventory->getGold()));
	shieldLabel->setText("Shield : " + QString::number(inventory->getShield()) + " PV");
	RocketInfo->setText("Roquette\nPrix : " + QString::number(inventory->GetPrixRocket()) + "$\n Possede : " + QString::number(inventory->getRockets()) + ", max 2");
	GrenadeInfo->setText("Grenade\nPrix : " + QString::number(inventory->GetPrixGrenade()) + "$\n Possede : " + QString::number(inventory->getGrenade()) + ", max 2");

	if (inventory->getRockets() >= 2) {
		RocketInfo->setStyleSheet("QLabel {"
			"border: 2px solid red;"
			" opacity : 150; "
			" font: 14pt 'Cooper Black'; "
			"qproperty-alignment: 'AlignCenter';"
			" min-width: 0px;"
			" max - width: 10000px; }");
	}
	else {
		RocketInfo->setStyleSheet("QLabel {"
			"border: 2px solid black;"
			" opacity : 150; "
			" font: 14pt 'Cooper Black'; "
			"qproperty-alignment: 'AlignCenter';"
			" min-width: 0px;"
			" max - width: 10000px; }");
	}

	if (inventory->getGrenade() >= 2) {
		GrenadeInfo->setStyleSheet("QLabel {"
			"border: 2px solid red;"
			" opacity : 150; "
			" font: 14pt 'Cooper Black'; "
			"qproperty-alignment: 'AlignCenter';"
			" min-width: 0px;"
			" max - width: 10000px; }");
	}
	else {
		GrenadeInfo->setStyleSheet("QLabel {"
			"border: 2px solid black;"
			" opacity : 150; "
			" font: 14pt 'Cooper Black'; "
			"qproperty-alignment: 'AlignCenter';"
			" min-width: 0px;"
			" max - width: 10000px; }");
	}

	if (inventory->getShield() >= 50) {
		PotInfo1->setStyleSheet("QLabel {"
			"border: 2px solid red;"
			" opacity : 150; "
			" font: 14pt 'Cooper Black'; "
			"qproperty-alignment: 'AlignCenter';"
			" min-width: 0px;"
			" max-width: 1050px; }"
			"background-color: red;");

		if (inventory->getShield() >= 100) {
			PotInfo2->setStyleSheet("QLabel {"
				"border: 2px solid red;"
				" opacity : 150; "
				" font: 14pt 'Cooper Black'; "
				"qproperty-alignment: 'AlignCenter';"
				" min-width: 0px;"
				" max-width: 1050px; }"
				"background-color: red;");
			PotInfo3->setStyleSheet("QLabel {"
				"border: 2px solid red;"
				" opacity : 150; "
				" font: 14pt 'Cooper Black'; "
				"qproperty-alignment: 'AlignCenter';"
				" min-width: 0px;"
				" max-width: 1050px; }"
				"background-color: red;");
		}
		else {
			PotInfo2->setStyleSheet("QLabel {"
				"border: 2px solid black;"
				" opacity : 150; "
				" font: 14pt 'Cooper Black'; "
				"qproperty-alignment: 'AlignCenter';"
				" min-width: 0px;"
				" max-width: 1050px; }"
				"background-color: lightblue;");
			PotInfo3->setStyleSheet("QLabel {"
				"border: 2px solid black;"
				" opacity : 150; "
				" font: 14pt 'Cooper Black'; "
				"qproperty-alignment: 'AlignCenter';"
				" min-width: 0px;"
				" max-width: 1050px; }"
				"background-color: lightblue;");
		}
	}
	else {
		PotInfo1->setStyleSheet("QLabel {"
			"border: 2px solid black;"
			" opacity : 150; "
			" font: 14pt 'Cooper Black'; "
			"qproperty-alignment: 'AlignCenter';"
			" min-width: 0px;"
			" max-width: 1050px; }"
			"background-color: lightblue;");
		PotInfo2->setStyleSheet("QLabel {"
			"border: 2px solid black;"
			" opacity : 150; "
			" font: 14pt 'Cooper Black'; "
			"qproperty-alignment: 'AlignCenter';"
			" min-width: 0px;"
			" max-width: 1050px; }"
			"background-color: lightblue;");
		PotInfo3->setStyleSheet("QLabel {"
			"border: 2px solid black;"
			" opacity : 150; "
			" font: 14pt 'Cooper Black'; "
			"qproperty-alignment: 'AlignCenter';"
			" min-width: 0px;"
			" max-width: 1050px; }"
			"background-color: lightblue;");
	}

	update();
}
