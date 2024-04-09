
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

#include "../Affichage/Pixmaps.h"

class GameWidget : public QWidget {
    Q_OBJECT
public:
    GameWidget();

    void addImage(Frank_PixMap* pixmap);
    void addImage(Frank_PixMap_Rotation* pixmap);
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
    QVector<Frank_PixMap_Rotation*> vectorPixMapRotation;
};


#endif // !MAINWINDOW_H