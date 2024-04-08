#include "GameWindow.h"
//#include "GenericMenu.h"
#include <QtWidgets>

GameWindow::GameWindow() : QMainWindow()
{
	setWindowTitle(tr("Guerre de radeaux"));

    stackedWidget = new QStackedWidget;

    setCentralWidget(stackedWidget);

    timerId = startTimer(2000);
}

GameWindow::~GameWindow()
{
    killTimer(timerId);
}

void GameWindow::ShowContent(int widgetIndex) {
    stackedWidget->setCurrentIndex(widgetIndex);
    Sleep(1);
    //(qobject_cast<GenericMenu*>(stackedWidget->currentWidget()))->SetChecked(0);
}

void GameWindow::AddContent(QWidget* widget) {
    stackedWidget->addWidget(widget);
}

bool GameWindow::IsCurrentWidget(QWidget* widget) {
    return stackedWidget->currentIndex() == stackedWidget->indexOf(widget);
}

void GameWindow::timerEvent(QTimerEvent* event)
{
    canInput = true;
}
