#include "MainMenu.h"
#include "Global.h"
#include <QtWidgets>

MainMenuQt::MainMenuQt() : GenericMenu()
{
	CreateButtons(4);

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

	buttons[0]->setText("Jouer");
	buttons[1]->setText("Selection du niveau");
	buttons[2]->setText("Magasin");
	buttons[3]->setText("Sortir");

	vbox->addWidget(buttons[0]);
	vbox->addWidget(buttons[1]);
	vbox->addWidget(buttons[2]);
	vbox->addWidget(buttons[3]);

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

void MainMenuQt::SelectChecked() {
	int checkedButton = 0;
	if (checkedButton == 0) {
	}
	else if (checkedButton == 1) {
	}
	else if (checkedButton == 2) {
	}
	else if (checkedButton == 3) {
		QApplication::quit();
	}
}