
#ifndef MAINWINDOW_H
#define MAINWINDOW_H




#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "../Game/utility.h"



struct Frank_PixMap
{
    QPixmap pix;
    int* x;
    int* y;
    Hitbox box;
    float rotation;
    int couche;
    QString name;
};



class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();

    void Initialiser();
    void addImage(Frank_PixMap* pixmap);
    void removeImage(QString name);
    void removeAllImages();
    void refresh();
    QPixmap rotatePixmap(const QPixmap& pixmap, qreal degrees);


    int minX;
    int minY;

protected:
    void paintEvent(QPaintEvent* event);

private:
    QVector<Frank_PixMap*> vectorPixMap;

    QWidget* widg;
};


#endif // !MAINWINDOW_H