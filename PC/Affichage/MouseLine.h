#include <QWidget>
#include <QTimer>
#include <QtWidgets>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
class MouseLine : public QWidget {

    Q_OBJECT
public:
    MouseLine()
    {
        // Cr�er un minuteur pour mettre � jour la position de la lig
        QTimer* timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MouseLine::updateLine);
        timer->start(10); // Mettre � jour toutes les 10 millisecondes
        initialMousePos = QCursor::pos();
        lineEnd = QPoint(0, 0);
        lineStart = QPoint(0, 0);
    }
    void paintEvent(QPaintEvent* event) override
    {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        // D�finir le style de la ligne en pointill�
        painter.setPen(QPen(Qt::black, 2, Qt::DotLine));

        // Dessiner la ligne
        painter.drawLine(lineStart, lineEnd);
        painter.drawEllipse(100, 100, 100, 100);
    }
    QPoint lineStart; // Point de d�part de la ligne
    QPoint lineEnd;
    QPoint initialMousePos; // Position initiale de la souris
public slots:
    void updateLine()
    {
        //paintEvent(this);
        // Obtenir la position actuelle de la souris
        QPoint currentMousePos = QCursor::pos();//get the position of the mouse cursor 

        // Limiter la position en X � 200 pixels de la position initiale
        int deltaX = currentMousePos.x() - initialMousePos.x();
        if (deltaX > 200)
            currentMousePos.setX(initialMousePos.x() + 200);
        else if (deltaX < -200)
            currentMousePos.setX(initialMousePos.x() - 200);

        // Mettre � jour le point d'arriv�e de la ligne avec la position actuelle de la souris
        lineEnd = mapFromGlobal(currentMousePos);
        update(); // Redessiner la ligne
    }
    void updateLineStart(const QPoint& newStart) {
        lineStart = newStart;
        update(); // Redessiner la ligne avec la nouvelle position de d�part
    }
    void increaseLineLength(int delta) {
        // Mettre � jour la position de fin de la ligne en fonction du delta
        lineEnd.rx() += delta; // Augmente la position x de la ligne de delta
        update(); // Redessiner la ligne avec la nouvelle longueur
    }

private:


    // Point d'arriv�e de la ligne


};
class KeyboardControlsLine: public QWidget
{

};