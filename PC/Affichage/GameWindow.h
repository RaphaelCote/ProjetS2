#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtWidgets>
#include "GameWidget.h"
#include "MouseLine.h"

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

	
	////////////////////////////////////////////////////
	 
	MouseLine* mouseLine;
	QPoint lineStart;
	QPoint lineEnd;
	void paintEvent(QPaintEvent* event) override {
		// Appel � la m�thode paintEvent de la classe de base
		QMainWindow::paintEvent(event);

		// Cr�ation d'un objet QPainter pour le dessin
		QPainter painter(this);
		// D�finir la couleur de la ligne (noir dans cet exemple)
		painter.setPen(QPen(Qt::black, 2, Qt::DotLine)); // �paisseur de ligne de 2 pixels
		// Dessiner la ligne en utilisant les coordonn�es actuelles
		painter.drawLine(lineStart, lineEnd);
	}
public slots:
	void increaseLineToRight() {
		// Mettre � jour les coordonn�es de fin de ligne
		lineEnd.setX(lineEnd.x() + 100); // Augmentez la coordonn�e x de la ligne de 100 pixels
		// Mettre � jour l'affichage
		update();
	}
	////////////////////////////////////////////////////
private:

	float keyboardPower = 0.5;
	float keyboardAngle = 45;

	int timerId;
	QStackedWidget* stackedWidget;

	void timerEvent(QTimerEvent* event); 
	void keyPressEvent(QKeyEvent* event) override;
	bool event(QEvent* event) override;
signals:
	/*void tKeyPressed(const QPoint& newStart);*/
	void tKeyPressed();
	void gKeyPressed();
	void rKeyPressed();
	void fKeyPressed();
};

#endif