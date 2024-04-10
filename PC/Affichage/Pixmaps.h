#ifndef PIXMAPS_H
#define PIXMAPS_H
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "../Game/utility.h"

struct Raph_PixMap
{
    QPixmap pix;
    int x;
    int y;
    //Coordonnee coor;
    Hitbox box;
    float rotation;
    int couche;
    std::string name;
};

struct Frank_PixMap
{
    QPixmap pix;
    int* x;
    int* y;
    //Coordonnee coor;
    Hitbox box;
    float rotation;
    int couche;
    std::string name;
};

struct Frank_PixMap_Rotation
{
    QPixmap pix;
    int* x;
    int* y;
    //Coordonnee coor;
    Hitbox box;
    float* rotation;
    int couche;
    std::string name;
};

#endif
