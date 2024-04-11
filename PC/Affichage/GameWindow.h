#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtWidgets>
#include "GameWidget.h"
#include "GenericMenu.h"
#include "Game/utility.h"

class GameWindow : public QMainWindow
{
	Q_OBJECT

public:
	bool canInput = true;

	bool isKeyboardControls = false;
	GameWindow();
	~GameWindow();

	void ShowContent(int widgetIndex);
	void AddContent(QWidget* widget);
	bool IsCurrentWidget(QWidget* widget);
	void SetChecked(int index);
	GameWidget* GetGameWidget();
	GenericMenu* GetMenuWidget(int index);
	////////////////////////////////////////////////////
	/*QPoint lineStart;
	QPoint lineEnd;*/
	Coordonnee LineStart;
	Coordonnee LineEnd;
	
public slots:
	void increaseLineToRight() {
		// Mettre à jour les coordonnées de fin de ligne
		//lineEnd.setX(lineEnd.x() + 10); // Augmentez la coordonnée x de la ligne de 100 pixels
		//// Mettre à jour l'affichage
		//if ((lineEnd.x() - lineStart.x()) > 100)
		//	lineEnd.setX(lineStart.x() + 100);

		/*LineEnd.x = LineEnd.x + 10;
		if (LineEnd.x - LineStart.x > 100)
			LineEnd.x = LineStart.x + 100;*/

		update();
	}
	void decreaseLineToLeft()
	{
		/*lineEnd.setX(lineEnd.x() - 10);
		if ((lineEnd.x() - lineStart.x()) < 0)
			lineEnd.setX(lineStart.x());*/

		/*LineEnd.x = LineEnd.x - 10;
		if (LineEnd.x - LineStart.x < 0)
			LineEnd.x = LineStart.x;*/
		update();
	}
	void increaseLinetoUp()
	{
		/*lineEnd.setY(lineEnd.y() - 10);
		if ((lineEnd.y() - lineStart.y()) < -20)
			lineEnd.setY(lineStart.y() - 20);*/

		/*LineEnd.y = LineEnd.y - 10;
		if (LineEnd.y - LineStart.y < -70)
			LineEnd.y = LineStart.y - 70;*/

		update();
	}
	void decreaseLineToDown()
	{
		/*lineEnd.setY(lineEnd.y() + 10);
		if ((lineEnd.y() - lineStart.y()) > 70)
			lineEnd.setY(lineStart.y() + 70);*/

		/*LineEnd.y = LineEnd.y + 10;
		if (LineEnd.y - LineStart.y > 100)
			LineEnd.y = LineStart.y + 100;*/

		update();
	}

signals:
	/*void tKeyPressed(const QPoint& newStart);*/
	void tKeyPressed();
	void gKeyPressed();
	void rKeyPressed();
	void fKeyPressed();
	////////////////////////////////////////////////////
private:

	float keyboardPower = 0.5;
	float keyboardAngle = 45;

	int timerId;
	QStackedWidget* stackedWidget;

	void timerEvent(QTimerEvent* event); 
	void keyPressEvent(QKeyEvent* event) override;
	bool event(QEvent* event) override;
};

#endif