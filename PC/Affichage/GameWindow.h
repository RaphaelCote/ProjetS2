#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtWidgets>

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

private:
	int timerId;
	QStackedWidget* stackedWidget;

	void timerEvent(QTimerEvent* event);
	bool eventFilter(QObject* obj, QEvent* event) override;
};

#endif