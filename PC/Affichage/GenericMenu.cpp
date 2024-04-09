#include "GenericMenu.h"
#include "Global.h"
#include "GameWindow.h"

GenericMenu::GenericMenu()
{
	QScreen* screen = QGuiApplication::primaryScreen();
	QRect screenGeometry = screen->geometry();
	int screenWidth = screenGeometry.width();
	int screenHeight = screenGeometry.height();
	minX = 0;
	minY = 0;

	QPixmap map3("C:/home/DEVUniversite/ProjetS2/Images/beach.jpg");
	map3 = map3.scaled(screenWidth, screenHeight);

	Raph_PixMap* image4 = new Raph_PixMap;
	image4->pix = map3;
	image4->x = 0;
	image4->y = 0;
	image4->box = { screenHeight, 50 };
	image4->name = "background";
	image4->couche = 1;
	vectorPixMap.append(image4);
}

void GenericMenu::CreateButtons(int btnQty) {
	for (int i = 0; i < btnQty; i++) {
		buttons.push_back(new MenuButton("Btn", this));
		buttons[i]->setCheckable(true);
		buttons[i]->installEventFilter(this);
	}

	SetChecked(0);
}

void GenericMenu::SetChecked(int index) {
	for (int i = 0; i < buttons.size(); i++) {
		if (i == index) {
			buttons[i]->setChecked(true);
		}
		else {
			buttons[i]->setChecked(false);
		}
	}
}

void GenericMenu::paintEvent(QPaintEvent* event) {
	Q_UNUSED(event);
	QPainter painter(this);

	int windowHeight = this->height();

	//painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
	for (int i = 0; i < vectorPixMap.length(); i++)
	{
		int x = 0;
		int y = 0;

		if (vectorPixMap[i]->couche == -1)
		{
			x = vectorPixMap[i]->x;
			y = windowHeight - vectorPixMap[i]->y - vectorPixMap[i]->box.height;
		}
		else
		{
			x = vectorPixMap[i]->x + minX;
			y = windowHeight - vectorPixMap[i]->y - vectorPixMap[i]->box.height + minY;
		}


		painter.drawPixmap(x, y, vectorPixMap[i]->pix);
	}

}
