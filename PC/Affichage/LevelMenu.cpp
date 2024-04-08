#include "LevelMenu.h"
#include "Global.h"
#include <QtWidgets>

LevelMenu::LevelMenu() : GenericMenu()
{
	CreateButtons(levelQty);

	QScreen* screen = QGuiApplication::primaryScreen();
	QRect screenGeometry = screen->geometry();
	int screenWidth = screenGeometry.width();
	int screenHeight = screenGeometry.height();
	minX = 0;
	minY = 0;

	QVBoxLayout* vbox = new QVBoxLayout();

	QPixmap logo("C:/home/DEVUniversite/ProjetS2/Images/logo.png");
	QLabel* titleLabel = new QLabel(this);
	titleLabel->setPixmap(logo.scaled(650, 200, Qt::KeepAspectRatio));
	vbox->addWidget(titleLabel);
	vbox->addItem(new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed));

	for (int i = 0; i < levelQty; i++) {
		if (i == levelQty - 1) {
			buttons[i]->setText("Retour");
			continue;
		}

		QString text = "Niveau ";
		text += std::to_string(i);
		buttons[i]->setText(text);

		vbox->addWidget(buttons[i]);
	}

	QPixmap map3("C:/home/DEVUniversite/ProjetS2/Images/beach.jpg");
	map3 = map3.scaled(screenWidth, screenHeight);

	Frank_PixMap* image4 = new Frank_PixMap;
	image4->pix = map3;
	image4->coor = { 0,0 };
	image4->box = { 50, screenHeight };
	image4->name = "allo2";
	image4->couche = 1;
	vectorPixMap.append(image4);

	vbox->setSpacing(45);
	vbox->setAlignment(Qt::AlignCenter);

	setLayout(vbox);
	update();
}