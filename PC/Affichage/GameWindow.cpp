#include "GameWindow.h"
#include "../Controls/keyboardControlsRedirect.h"
#include "GenericMenu.h"
#include <QtWidgets>

GameWindow::GameWindow() : QMainWindow()
{
	setWindowTitle(tr("Guerre de radeaux"));

    stackedWidget = new QStackedWidget;

    setCentralWidget(stackedWidget);

    timerId = startTimer(200);
}

GameWindow::~GameWindow()
{
    killTimer(timerId);
}

void GameWindow::ShowContent(int widgetIndex) {
    stackedWidget->setCurrentIndex(widgetIndex);
    Sleep(1);
    (qobject_cast<GenericMenu*>(stackedWidget->currentWidget()))->SetChecked(0);
}

void GameWindow::AddContent(QWidget* widget) {
    stackedWidget->addWidget(widget);
}

bool GameWindow::IsCurrentWidget(QWidget* widget) {
    return stackedWidget->currentIndex() == stackedWidget->indexOf(widget);
}

void GameWindow::SetChecked(int index) {
    (qobject_cast<GenericMenu*>(stackedWidget->currentWidget()))->SetChecked(index);
}

void GameWindow::timerEvent(QTimerEvent* event)
{
    canInput = true;
}

void GameWindow::keyPressEvent(QKeyEvent* event) {
    //Si les controls sont pas keyboard
    if (!isKeyboardControls) {
        return;
    }

    //Si le temps entre les input est pas fini
    if (!canInput) {
        return;
    }

    canInput = false;

    KeyboardControlsRedirect kcr;

    if (event->key() == Qt::Key_W) {
        kcr.Joystick(0, 1);
    }
    else if (event->key() == Qt::Key_S) {
        kcr.Joystick(0, -1);
    }
    else if (event->key() == Qt::Key_L) {
        kcr.MainAction();
    }
}
