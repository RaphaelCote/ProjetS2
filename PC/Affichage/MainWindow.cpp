#include"MainWindow.h"






MainWindow::MainWindow()
{
    
}


void MainWindow::Initialiser()
{
    widg = new QWidget();
    setCentralWidget(widg);
    minX = 0;
    minY = 0;
}

void MainWindow::addImage(Frank_PixMap* pixmap)
{
    vectorPixMap.append(pixmap);
}

void MainWindow::addImage(Frank_PixMap_Rotation* pixmap)
{
    vectorPixMapRotation.append(pixmap);
}

void MainWindow::removeImage(QString name)
{
    for (int i = 0; i < vectorPixMap.size(); i++)
    {
        if (vectorPixMap[i]->name == name)
        {
            vectorPixMap.removeAt(i);// retire l'�l�ment a l'index i
            // cout << "Removed: " << i << "  " << name;
            // Sleep(1000);
            return;
        }
    }

    for (int i = 0; i < vectorPixMapRotation.size(); i++)
    {
        if (vectorPixMapRotation[i]->name == name)
        {
            vectorPixMapRotation.removeAt(i);// retire l'�l�ment a l'index i
            // cout << "Removed: " << i << "  " << name;
            // Sleep(1000);
            return;
        }
    }
}

void MainWindow::removeAllImages()
{
    vectorPixMap.clear();
    vectorPixMapRotation.clear();
}


void MainWindow::refresh()
{
    update();
}

QPixmap MainWindow::rotatePixmap(const QPixmap& pixmap, qreal degrees) {
    QSize size = pixmap.size();
    QPixmap rotatedPixmap(size);
    rotatedPixmap.fill(Qt::transparent); // Fill with transparent color

    // Create a painter for the rotated pixmap
    QPainter painter(&rotatedPixmap);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    // Translate the painter's origin to the center of the image
    painter.translate(size.width() / 2, size.height() / 2);

    // Rotate the painter
    painter.rotate(degrees);

    // Draw the original pixmap onto the rotated pixmap
    painter.drawPixmap(-size.width() / 2, -size.height() / 2, pixmap);

    return rotatedPixmap;
}




void MainWindow::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    int windowHeight = this->height();

    //painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    for (int i = 0; i < vectorPixMap.length(); i++)
    {
        int x = 0;
        int y = 0;
        float angle = vectorPixMap[i]->rotation;
        if ( angle != 0)
        {
            QPixmap rotatedPixmap = rotatePixmap(vectorPixMap[i]->pix, vectorPixMap[i]->rotation);

            x = *(vectorPixMap[i]->x) + minX;
            y = windowHeight - *(vectorPixMap[i]->y) - vectorPixMap[i]->box.height + minY;

            painter.drawPixmap(x, y, rotatedPixmap);
            continue;
        }

        if (vectorPixMap[i]->couche == -1)
        {
            x = *(vectorPixMap[i]->x);
            y = windowHeight - *(vectorPixMap[i]->y) - vectorPixMap[i]->box.height;
        }
        else
        {
            x = *(vectorPixMap[i]->x) + minX;
            y = windowHeight - *(vectorPixMap[i]->y) - vectorPixMap[i]->box.height + minY;
        }


        painter.drawPixmap(x, y, vectorPixMap[i]->pix);
    }


    for (int i = 0; i < vectorPixMapRotation.length(); i++)
    {
        int x = 0;
        int y = 0;
        float angle = *(vectorPixMapRotation[i]->rotation);
        if (angle != 0)
        {
            QPixmap rotatedPixmap = rotatePixmap(vectorPixMapRotation[i]->pix, angle);

            x = *(vectorPixMapRotation[i]->x) + minX;
            y = windowHeight - *(vectorPixMapRotation[i]->y) - vectorPixMapRotation[i]->box.height + minY;

            painter.drawPixmap(x, y, rotatedPixmap);
            continue;
        }

        if (vectorPixMapRotation[i]->couche == -1)
        {
            x = *(vectorPixMapRotation[i]->x);
            y = windowHeight - *(vectorPixMapRotation[i]->y) - vectorPixMapRotation[i]->box.height;
        }
        else
        {
            x = *(vectorPixMapRotation[i]->x) + minX;
            y = windowHeight - *(vectorPixMapRotation[i]->y) - vectorPixMapRotation[i]->box.height + minY;
        }


        painter.drawPixmap(x, y, vectorPixMapRotation[i]->pix);
    }

}