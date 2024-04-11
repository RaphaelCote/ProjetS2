#include <QtWidgets>

#include "GameWidget.h"

GameWidget::GameWidget()
{
    minX = 0;
    minY = 0;

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignTop);

    projectileSelection.push_back(new QPushButton(" ", this));
    projectileSelection.push_back(new QPushButton(" ", this));
    projectileSelection.push_back(new QPushButton(" ", this));

    projectileSelection[0]->setCheckable(true);
    projectileSelection[1]->setCheckable(true);
    projectileSelection[2]->setCheckable(true);

    projectileSelection[0]->setChecked(true);

    int widthPercentage = 10;
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    //sizePolicy.setHorizontalStretch(widthPercentage);
    sizePolicy.setHorizontalPolicy(QSizePolicy::Expanding);

    int height = 100;
    int width = 100;

    projectileSelection[0]->setMinimumWidth(width);
    projectileSelection[0]->setMaximumWidth(width);
    projectileSelection[0]->setMinimumHeight(height);
    projectileSelection[0]->setMaximumHeight(height);
    projectileSelection[0]->setSizePolicy(sizePolicy);

    projectileSelection[1]->setMinimumWidth(width);
    projectileSelection[1]->setMaximumWidth(width);
    projectileSelection[1]->setMinimumHeight(height);
    projectileSelection[1]->setMaximumHeight(height);
    projectileSelection[1]->setSizePolicy(sizePolicy);

    projectileSelection[2]->setMinimumWidth(width);
    projectileSelection[2]->setMaximumWidth(width);
    projectileSelection[2]->setMinimumHeight(height);
    projectileSelection[2]->setMaximumHeight(height);
    projectileSelection[2]->setSizePolicy(sizePolicy);

    projectileSelection[0]->setStyleSheet("QPushButton {"
        " border:4px outset; "
        " border-radius: 8px; "
        " border-color: rgb(255, 160, 48); "
        " color:rgb(0, 0, 0); "
        " background-color: rgb(255, 74, 49);  "
        " opacity : 150; "
        " font: 24pt 'Cooper Black'; "
        "qproperty-alignment: 'AlignCenter';"
        " min-width: 0px;"
        " max - width: 10000px; }"
        "QPushButton:checked {"
        " background-color: rgb(3, 215, 252);"
        " border-color: rgb(17, 97, 173); }"
    );

    projectileSelection[1]->setStyleSheet("QPushButton {"
        " border:4px outset; "
        " border-radius: 8px; "
        //" border-color: rgb(255, 160, 48); "
        " border-color: darkgrey; "
        " color:rgb(0, 0, 0); "
        //" background-color: rgb(255, 74, 49);  "
        " background-color: grey;  "
        " opacity : 150; "
        " font: 24pt 'Cooper Black'; "
        "qproperty-alignment: 'AlignCenter';"
        " min-width: 0px;"
        " max - width: 10000px; }"
        "QPushButton:checked {"
        " background-color: rgb(3, 215, 252);"
        " border-color: rgb(17, 97, 173); }"
    );

    projectileSelection[2]->setStyleSheet("QPushButton {"
        " border:4px outset; "
        " border-radius: 8px; "
        //" border-color: rgb(255, 160, 48); "
        " border-color: darkgrey; "
        " color:rgb(0, 0, 0); "
        //" background-color: rgb(255, 74, 49);  "
        " background-color: grey;  "
        " opacity : 150; "
        " font: 24pt 'Cooper Black'; "
        "qproperty-alignment: 'AlignCenter';"
        " min-width: 0px;"
        " max - width: 10000px; }"
        "QPushButton:checked {"
        " background-color: rgb(3, 215, 252);"
        " border-color: rgb(17, 97, 173); }"
    );

    QVBoxLayout* ballLayout = new QVBoxLayout(this);

    QPixmap ball("Images/Projectile/Ball.png");
    QLabel* BallImage = new QLabel(this);
    BallImage->setPixmap(ball.scaled(35, 35, Qt::KeepAspectRatio));
    BallImage->setAlignment(Qt::AlignCenter);
    ballLayout->addWidget(BallImage);

    projectileSelection[0]->setLayout(ballLayout);

    QVBoxLayout* rocketLayout = new QVBoxLayout(this);

    QPixmap rocket("Images/Projectile/Missile.png");
    QLabel* RocketImage = new QLabel(this);
    RocketImage->setPixmap(rocket.scaled(110, 73, Qt::KeepAspectRatio));
    RocketImage->setAlignment(Qt::AlignCenter);
    rocketLayout->addWidget(RocketImage);

    projectileSelection[1]->setLayout(rocketLayout);

    QVBoxLayout* grenadeLayout = new QVBoxLayout(this);
    QPixmap Grenade("Images/Projectile/Grenade.png");
    QLabel* GrenadeImage = new QLabel(this);
    GrenadeImage->setPixmap(Grenade.scaled(140, 50, Qt::KeepAspectRatio));
    GrenadeImage->setAlignment(Qt::AlignCenter);
    grenadeLayout->addWidget(GrenadeImage);

    projectileSelection[2]->setLayout(grenadeLayout);

    // Ajouter les QPushButton dans un QHBoxLayout pour le positionner en haut � gauche
    QHBoxLayout* projectilLayout = new QHBoxLayout();
    projectilLayout->addWidget(projectileSelection[0]);
    projectilLayout->addWidget(projectileSelection[1]);
    projectilLayout->addWidget(projectileSelection[2]);
    projectilLayout->addStretch();

    mainLayout->addLayout(projectilLayout);
}

void GameWidget::addImage(Frank_PixMap* pixmap)
{
    vectorPixMap.append(pixmap);
}

void GameWidget::addImage(Frank_PixMap_Rotation* pixmap)
{
    vectorPixMapRotation.append(pixmap);
}

void GameWidget::addImage(Raph_PixMap* pixmap)
{
    vectorPixMapRaph.append(pixmap);
}

void GameWidget::removeImage(std::string name)
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

    for (int i = 0; i < vectorPixMapRaph.size(); i++)
    {
        if (vectorPixMapRaph[i]->name == name)
        {
            vectorPixMapRaph.removeAt(i);// retire l'�l�ment a l'index i
            // cout << "Removed: " << i << "  " << name;
            // Sleep(1000);
            return;
        }
    }
}

void GameWidget::removeAllImages()
{
    vectorPixMap.clear();
    vectorPixMapRotation.clear();
    vectorPixMapRaph.clear();
}


void GameWidget::refresh()
{
    update();
}

QPixmap GameWidget::rotatePixmap(const QPixmap& pixmap, qreal degrees) {
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

void GameWidget::SetCheckedProjectile(int index)
{
    for (int i = 0; i < projectileSelection.size(); i++)
    {
        if (i == index)
        {
            projectileSelection[i]->setChecked(true);
        }
        else
        {
            projectileSelection[i]->setChecked(false);
        }
    }
}

void GameWidget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    if (isZoomedOut) {
        painter.scale(0.5, 0.5);
    }
    else {
        painter.scale(1, 1);
    }

    int windowHeight = this->height();

    for (int i = 0; i < vectorPixMapRaph.length(); i++)
    {
        int x = 0;
        int y = 0;
        float angle = vectorPixMapRaph[i]->rotation;
        if (angle != 0)
        {
            QPixmap rotatedPixmap = rotatePixmap(vectorPixMapRaph[i]->pix, vectorPixMapRaph[i]->rotation);

            x = vectorPixMapRaph[i]->x + minX;
            y = windowHeight - vectorPixMapRaph[i]->y - vectorPixMapRaph[i]->box.height + minY;

            painter.drawPixmap(x, y, rotatedPixmap);
            continue;
        }

        if (vectorPixMapRaph[i]->couche == -1)
        {
            x = vectorPixMapRaph[i]->x;
            y = windowHeight - vectorPixMapRaph[i]->y - vectorPixMapRaph[i]->box.height;
        }
        else
        {
            x = vectorPixMapRaph[i]->x + minX;
            y = windowHeight - vectorPixMapRaph[i]->y - vectorPixMapRaph[i]->box.height + minY;
        }


        painter.drawPixmap(x, y, vectorPixMapRaph[i]->pix);
    }


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

    if (rocketNum > 0) {
        projectileSelection[1]->setStyleSheet("QPushButton {"
            " border:4px outset; "
            " border-radius: 8px; "
            " border-color: rgb(255, 160, 48); "
            //" border-color: darkgrey; "
            " color:rgb(0, 0, 0); "
            " background-color: rgb(255, 74, 49);  "
            //" background-color: grey;  "
            " opacity : 150; "
            " font: 24pt 'Cooper Black'; "
            "qproperty-alignment: 'AlignCenter';"
            " min-width: 0px;"
            " max - width: 10000px; }"
            "QPushButton:checked {"
            " background-color: rgb(3, 215, 252);"
            " border-color: rgb(17, 97, 173); }"
        );
    }
    else {
        projectileSelection[1]->setStyleSheet("QPushButton {"
            " border:4px outset; "
            " border-radius: 8px; "
            //" border-color: rgb(255, 160, 48); "
            " border-color: darkgrey; "
            " color:rgb(0, 0, 0); "
            //" background-color: rgb(255, 74, 49);  "
            " background-color: grey;  "
            " opacity : 150; "
            " font: 24pt 'Cooper Black'; "
            "qproperty-alignment: 'AlignCenter';"
            " min-width: 0px;"
            " max - width: 10000px; }"
            "QPushButton:checked {"
            " background-color: rgb(3, 215, 252);"
            " border-color: rgb(17, 97, 173); }"
        );
    }

    if (grenadeNum > 0) {
        projectileSelection[2]->setStyleSheet("QPushButton {"
            " border:4px outset; "
            " border-radius: 8px; "
            " border-color: rgb(255, 160, 48); "
            //" border-color: darkgrey; "
            " color:rgb(0, 0, 0); "
            " background-color: rgb(255, 74, 49);  "
            //" background-color: grey;  "
            " opacity : 150; "
            " font: 24pt 'Cooper Black'; "
            "qproperty-alignment: 'AlignCenter';"
            " min-width: 0px;"
            " max - width: 10000px; }"
            "QPushButton:checked {"
            " background-color: rgb(3, 215, 252);"
            " border-color: rgb(17, 97, 173); }"
        );
    }
    else {
        projectileSelection[2]->setStyleSheet("QPushButton {"
            " border:4px outset; "
            " border-radius: 8px; "
            //" border-color: rgb(255, 160, 48); "
            " border-color: darkgrey; "
            " color:rgb(0, 0, 0); "
            //" background-color: rgb(255, 74, 49);  "
            " background-color: grey;  "
            " opacity : 150; "
            " font: 24pt 'Cooper Black'; "
            "qproperty-alignment: 'AlignCenter';"
            " min-width: 0px;"
            " max - width: 10000px; }"
            "QPushButton:checked {"
            " background-color: rgb(3, 215, 252);"
            " border-color: rgb(17, 97, 173); }"
        );
    }
}