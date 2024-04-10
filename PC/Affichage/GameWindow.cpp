#include "GameWindow.h"
#include "../Controls/keyboardControlsRedirect.h"
#include "GenericMenu.h"
#include "ShowContentEvent.h"
#include <QtWidgets>

GameWindow::GameWindow() : QMainWindow()
{
	setWindowTitle(tr("Guerre de radeaux"));

    stackedWidget = new QStackedWidget;

    setCentralWidget(stackedWidget);

    timerId = startTimer(100);
}

GameWindow::~GameWindow()
{
    killTimer(timerId);
}

void GameWindow::ShowContent(int widgetIndex) {
    stackedWidget->setCurrentIndex(widgetIndex);

    if (widgetIndex != 1 && widgetIndex != 6) {
        Sleep(1);
        (qobject_cast<GenericMenu*>(stackedWidget->currentWidget()))->SetChecked(0);
    }
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

GameWidget* GameWindow::GetGameWidget() {
    return qobject_cast<GameWidget*>(stackedWidget->widget(1));
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
    else if (event->key() == Qt::Key_P) {
        kcr.Menu();
    }
    else if (event->key() == Qt::Key_Q) {
        kcr.PreviousSelection();
    }
    else if (event->key() == Qt::Key_E) {
        kcr.NextSelection();
    }
    else if (event->key() == Qt::Key_B) {
        kcr.Back();
    }
    else if (event->key() == Qt::Key_R) {
        keyboardAngle += 1;
        if (keyboardAngle > 90) {
            keyboardAngle = 90;
        }

        kcr.Angle(keyboardAngle);
    }
    else if (event->key() == Qt::Key_F) {
        keyboardAngle -= 1;
        if (keyboardAngle < 0) {
            keyboardAngle = 0;
        }

        kcr.Angle(keyboardAngle);
    }
    else if (event->key() == Qt::Key_T) {
        keyboardPower += 0.025;
        if (keyboardPower > 1) {
            keyboardPower = 1;
        }

        kcr.Joystick(keyboardPower, 0);
    }
    else if (event->key() == Qt::Key_G) {
        keyboardPower -= 0.025;
        if (keyboardPower < 0) {
            keyboardPower = 0;
        }

        kcr.Joystick(keyboardPower, 0);
    }
}

bool GameWindow::event(QEvent* event)
{
    // usage:
    if (event->type() == ShowContentEvent::showContent) {
        ShowContentEvent* sce = static_cast<ShowContentEvent*>(event);
        ShowContent(sce->index);

        return true;
    }

    return QWidget::event(event);
}
