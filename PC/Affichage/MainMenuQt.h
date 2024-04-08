#ifndef MAINMENUQT_H
#define MAINMENUQT_H

#include <QtWidgets>

#include "GenericMenu.h"

class MainMenuQt : public GenericMenu
{
	Q_OBJECT

public:
    MainMenuQt();
	void SelectChecked();
    int minX;
    int minY;

private:
	QVector<Frank_PixMap*> vectorPixMap;

protected:
    void paintEvent(QPaintEvent* event) override {
        Q_UNUSED(event);
        QPainter painter(this);

        int windowHeight = this->height();

        //painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
        for (int i = 0; i < vectorPixMap.length(); i++)
        {
            int x = 0;
            int y = 0;

            if (vectorPixMap[i]->couche == -1)
            {
                x = vectorPixMap[i]->coor.x;
                y = windowHeight - vectorPixMap[i]->coor.y - vectorPixMap[i]->box.height;
            }
            else
            {
                x = vectorPixMap[i]->coor.x + minX;
                y = windowHeight - vectorPixMap[i]->coor.y - vectorPixMap[i]->box.height + minY;
            }


            painter.drawPixmap(x, y, vectorPixMap[i]->pix);
        }

    }
};

#endif