#include "ShopMenuQt.h"
#include "Global.h"
#include <QtWidgets>

ShopMenuQt::ShopMenuQt() : GenericMenu()
{
	CreateButtons(6, false);

	QHBoxLayout* Hlayout3 = new QHBoxLayout(gameWindow);

	QVBoxLayout* Vlayout = new QVBoxLayout(this);
	Vlayout->setAlignment(Qt::AlignCenter);

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
	GrenadeImage->setPixmap(Grenade.scaled(280, 140, Qt::KeepAspectRatio));				// Scale logo
	GrenadeImage->setAlignment(Qt::AlignCenter);
	Hlayout1->addWidget(GrenadeImage);
	Vlayout->addLayout(Hlayout1);

	Vlayout->addWidget(rocketWidget);


	QLabel* RocketInfo = new QLabel("Roquette\nPrix : 10$", gameWindow);
	QLabel* GrenadeInfo = new QLabel("Grenade\nPrix : 10$", gameWindow);
	RocketInfo->setStyleSheet("QLabel {"
		//	" border:4px outset; "
		//	" border-radius: 8px; "
		//	" border-color: rgb(255, 160, 48); "
		//	" color:rgb(0, 0, 0); "
		//	" background-color: rgb(255, 74, 49);  "
		" opacity : 150; "
		" font: 14pt 'Cooper Black'; "
		"qproperty-alignment: 'AlignCenter';"
		" min-width: 0px;"
		" max - width: 10000px; }");
	GrenadeInfo->setStyleSheet("QLabel {"
		//	" border:4px outset; "
		//	" border-radius: 8px; "
		//	" border-color: rgb(255, 160, 48); "
		//	" color:rgb(0, 0, 0); "
		//	" background-color: rgb(255, 74, 49);  "
		" opacity : 150; "
		" font: 14pt 'Cooper Black'; "
		"qproperty-alignment: 'AlignCenter';"
		" min-width: 0px;"
		" max - width: 10000px; }");




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
	smallPot->setPixmap(potion1.scaled(300, 145, Qt::KeepAspectRatio));
	smallPot->setAlignment(Qt::AlignCenter);
	Hlayout4->addWidget(smallPot);

	QPixmap potion2("Images/MedPot.png");
	QLabel* medPot = new QLabel(gameWindow);
	medPot->setPixmap(potion2.scaled(300, 145, Qt::KeepAspectRatio));
	medPot->setAlignment(Qt::AlignCenter);
	Hlayout4->addWidget(medPot);

	QPixmap potion3("Images/BigPot.png");
	QLabel* bigPot = new QLabel(gameWindow);
	bigPot->setPixmap(potion3.scaled(300, 140, Qt::KeepAspectRatio));
	bigPot->setAlignment(Qt::AlignCenter);
	Hlayout4->addWidget(bigPot);
	Vlayout->addLayout(Hlayout4);
	Vlayout->addWidget(PotionWidget);

	QLabel* PotInfo1 = new QLabel("Petite potion\nAjoute 25PV, max 50PV\nPrix : 10$", gameWindow);
	QLabel* PotInfo2 = new QLabel("Moyenne potion\nAjoute 50PV, max 100PV\nPrix : 30$", gameWindow);
	QLabel* PotInfo3 = new QLabel("Enorme potion\nAjoute 100PV, max 100PV\nPrix : 50$", gameWindow);
	PotInfo1->setStyleSheet("QLabel {"
		" opacity : 150; "
		" font: 14pt 'Cooper Black'; "
		"qproperty-alignment: 'AlignCenter';"
		" min-width: 0px;"
		" max-width: 1050px; }");
	PotInfo2->setStyleSheet("QLabel {"
		" opacity : 150; "
		" font: 14pt 'Cooper Black'; "
		"qproperty-alignment: 'AlignCenter';"
		" min-width: 0px;"
		" max-width: 1050px; }");
	PotInfo3->setStyleSheet("QLabel {"
		" opacity : 150; "
		" font: 14pt 'Cooper Black'; "
		"qproperty-alignment: 'AlignCenter';"
		" min-width: 0px;"
		" max-width: 1050px; }");
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

	setLayout(Vlayout);
	update();
}