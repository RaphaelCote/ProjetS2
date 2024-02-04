#ifndef CONTROLS_H
#define CONTROLS_H

// #include <iostream>
#include "controlEvents.h"

using namespace std;

// Pour utiliser les contrôles, il faut utiliser le meme controlEvents et écouter les actions qu'on veut recevoir
// Lorsqu'on ne veut plus recevori les actions (ex.: on a quitter un menu), il faut les enlever des actions écoutée
// https://learn.microsoft.com/en-us/cpp/cpp/event-handling-in-native-cpp?view=msvc-170
class Controls
{
public:
    ControlEvents controlEvents;
    Controls(ControlEvents ce);
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