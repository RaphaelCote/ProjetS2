
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

#include "../Affichage/Pixmaps.h"
#include "../Controls/controllerControls.h"

class GameWidget : public QWidget {
    Q_OBJECT
public:
    GameWidget();

    void addImage(Frank_PixMap* pixmap);
    void addImage(Frank_PixMap_Rotation* pixmap);
    void addImage(Raph_PixMap* pixmap);
    void removeImage(std::string name);
    void removeAllImages();
    void refresh();
    QPixmap rotatePixmap(const QPixmap& pixmap, qreal degrees);
    void SetCheckedProjectile(int index);
    void StartMoteur(ControllerControls* controls);
    void StopMoteur();

    int minX;
    int minY;

    int rocketNum = 0;
    int grenadeNum = 0;

    int isZoomedOut = false;

protected:
    void paintEvent(QPaintEvent* event);

private:
    QVector<Frank_PixMap*> vectorPixMap;
    QVector<Frank_PixMap_Rotation*> vectorPixMapRotation;
    QVector<Raph_PixMap*> vectorPixMapRaph;

    std::vector<QPushButton*> projectileSelection;

    ControllerControls* controllerControls;
};


#endif // !MAINWINDOW_H