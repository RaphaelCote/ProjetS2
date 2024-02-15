#ifndef CONTROLS_H
#define CONTROLS_H

// #include <iostream>
#include <stdio.h>


using namespace std;

class Controls
{
public:
    // Pour faire des vrais contrôles (keyboard, manette), il faut juste implémenter cette méthode
    // qui va écouter pour des contrôles (touches, boutons) et appeler la bonne action à exécuter
    virtual void ListenForControls();

    // Actions
    void MainAction();
    void Back();
    void NextSelection();
    void PreviousSelection();
    void Menu();
    void Joystick(float x, float y);
    void Angle(float angle);
};

#endif