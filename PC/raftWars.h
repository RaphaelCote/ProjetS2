#ifndef RAFTWARS_H
#define RAFTWARS_H

#include "Controls/Controls.h"
#include "Controls/EventManager.h"
#include "tests.h"
#include "Scenes/scene.h"
#include "Game/inventory.h"
#include "Affichage/AffichageConsole.h"
#include "Controls/SoundManager.h"
#include <vector>
class MouseLine : public QWidget {
public:
    MouseLine()
    {
        // Créer un minuteur pour mettre à jour la position de la lig

        initialMousePos = QCursor::pos();
        lineEnd  = QPoint(0, 0);
        lineStart = QPoint(0, 0);
    }
    void paintEvent(QPaintEvent* event) override
    {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        // Définir le style de la ligne en pointillé
        painter.setPen(QPen(Qt::black, 2, Qt::DotLine));

        // Dessiner la ligne
        painter.drawLine(lineStart, lineEnd);
    }
    void updateLine()
    {
        // Obtenir la position actuelle de la souris
        QPoint currentMousePos = QCursor::pos();//get the position of the mouse cursor 

        // Limiter la position en X à 200 pixels de la position initiale
        /*int deltaX = currentMousePos.x() - initialMousePos.x();
        if (deltaX > 200)
            currentMousePos.setX(initialMousePos.x() + 200);
        else if (deltaX < -200)
            currentMousePos.setX(initialMousePos.x() - 200);*/

        // Mettre à jour le point d'arrivée de la ligne avec la position actuelle de la souris
        lineEnd = mapFromGlobal(currentMousePos);
        update(); // Redessiner la ligne
    }
    QPoint lineStart; // Point de départ de la ligne
    QPoint lineEnd;
    QPoint initialMousePos; // Position initiale de la souris
private:

    
    // Point d'arrivée de la ligne
   

};
extern EventManager *eventManager;
extern Controls *controls;
extern Tests *tests;
extern std::vector<Scene *> *scenes;
extern Inventory *inventory;
extern int activeScene;
extern LevelGetter *levelGetter;
extern AffichageConsole *cons;
extern SoundManager* soundManager;
extern MouseLine* mouseLine;
#endif