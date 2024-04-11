#include "GameWindow.h"
#include "../Controls/keyboardControlsRedirect.h"
#include "GenericMenu.h"
#include "Game/niveau.h"
#include "Game/gameloader.h"
#include "Scenes/game.h"
#include "../Controls/SoundManager.h"
#include <QtWidgets>

GameWindow::GameWindow() : QMainWindow()
{
    setWindowTitle(tr("Guerre de radeaux"));

    stackedWidget = new QStackedWidget;

    setCentralWidget(stackedWidget);

    timerId = startTimer(100);
    Game* game = new Game();
    ///////////////////////////////////////////////////////////////////////

    //mouseLine = new MouseLine();
    ////connect(this, &GameWindow::tKeyPressed, mouseLine, &MouseLine::updateLineStart);

    connect(this, &GameWindow::tKeyPressed, this, &GameWindow::increaseLineToRight);
    connect(this, &GameWindow::gKeyPressed, this, &GameWindow::decreaseLineToLeft);
    connect(this, &GameWindow::rKeyPressed, this, &GameWindow::increaseLinetoUp);
    connect(this, &GameWindow::fKeyPressed, this, &GameWindow::decreaseLineToDown);
    //QPoint(activeLevel->playerBoats[0]->characters[0]->getWeaponPosition().x, activeLevel->playerBoats[0]->characters[0]->getWeaponPosition().y);
    //lineStart = QPoint(game->activeLevel->playerBoats[0]->characters[0]->getWeaponPosition().x, game->activeLevel->playerBoats[0]->characters[0]->getWeaponPosition().y);
    //lineEnd = QPoint(game->activeLevel->playerBoats[0]->characters[0]->getWeaponPosition().x, game->activeLevel->playerBoats[0]->characters[0]->getWeaponPosition().y);
    lineStart = QPoint(200,750);
    lineEnd = QPoint(200,750);

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
        emit rKeyPressed();
    }
    else if (event->key() == Qt::Key_F) {
        keyboardAngle -= 1;
        if (keyboardAngle < 0) {
            keyboardAngle = 0;
        }

        kcr.Angle(keyboardAngle);
        emit fKeyPressed();
    }
    else if (event->key() == Qt::Key_T) {
        keyboardPower += 0.025;
        if (keyboardPower > 1) {
            keyboardPower = 1;
        }

        kcr.Joystick(keyboardPower, 0);

        // Émettre un signal pour augmenter la longueur de la ligne
        //emit increaseLineLength(delta);
        emit tKeyPressed();
    }
    else if (event->key() == Qt::Key_G) {
        keyboardPower -= 0.025;
        if (keyboardPower < 0) {
            keyboardPower = 0;
        }

        kcr.Joystick(keyboardPower, 0);

        emit gKeyPressed();
    }
}

bool GameWindow::event(QEvent* event)
{
    if (event->type() == 1000) {
        QKeyEvent* ke = static_cast<QKeyEvent*>(event);
        ShowContent(0);
    }

    return QWidget::event(event);
}
