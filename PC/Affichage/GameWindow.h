#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtWidgets>
#include "GameWidget.h"

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