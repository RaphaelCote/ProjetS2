#ifndef CONTROLS_H
#define CONTROLS_H

// #include <iostream>
#include <stdio.h>
#include "EventManager.h"
#include "EventParameters.h"


class Controls
{
public:
    EventManager *eventManager;
    Controls(EventManager *em);
    // Pour faire des vrais contrôles (keyboard, manette), il faut juste implémenter cette méthode
    // qui va écouter pour des contrôles (touches, boutons) et appeler la bonne action à exécuter
    virtual void ListenForControls() = 0;
    virtual void AddMessage(std::string name, int value){}
    virtual bool SendMessageJson(){return true;}
    virtual void GetValue(std::string name, float* value){}
    virtual void ReceiveSerial()= 0;

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