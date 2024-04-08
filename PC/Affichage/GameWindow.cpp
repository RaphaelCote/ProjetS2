#include "GameWindow.h"
#include "../Controls/keyboardControlsRedirect.h"
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

bool GameWindow::eventFilter(QObject* obj, QEvent* event) {
    //Si les controls sont pas keyboard
    if (!isKeyboardControls) {
        return QWidget::eventFilter(obj, event);
    }

    //Si l'envent est pas un input
    if (!(event->type() == QEvent::KeyPress)) {
    	return QWidget::eventFilter(obj, event);
    }

    //Si le temps entre les input est pas fini
    if (!canInput) {
    	return QWidget::eventFilter(obj, event);
    }

    //Si this est pas le menu affiche dw
    if (!IsCurrentWidget(this)) {
    	return QWidget::eventFilter(obj, event);
    }

    canInput = false;
    
    QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
    KeyboardControlsRedirect kcr;


    if (keyEvent->key() == Qt::Key_Up) {
        kcr.Joystick(0, 1);
    }
    else if (keyEvent->key() == Qt::Key_Down) {
        kcr.Joystick(0, -1);
    }
    else if (keyEvent->key() == Qt::Key_Space) {
        kcr.MainAction();
    }
    
    return QWidget::eventFilter(obj, event);
}
