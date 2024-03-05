#ifndef CONTROLLERCONTROLS_H
#define CONTROLLERCONTROLS_H

#include <iostream>
#include <string>

#include "controls.h"
#include "../include/serial/SerialPort.hpp"
#include "../include/json.hpp"
using json = nlohmann::json;

#define BAUD 115200         // Frequence de transmission serielle
#define MSG_MAX_SIZE 1024 // Longueur maximale d'un message

using namespace std;

enum etatBoutton
{
    BouttonAppuyer = 1,
    BouttonRelacher = 0,
    BouttonTenuAppuyer = 2,
    BouttonEnabled = 3,
    BouttonDisabled = 4
};

enum etatJoystick
{
    JoystickEnabled = 1,
    JoystickDisabled = 2,
    JoystickMiddle = 3,
    JoystickRight = 4,
    JoystickUp = 5,
    JoystickLeft = 6,
    JoystickDown = 7
};


class ControllerControls : public Controls
{
    string comPort;
    string raw_msg;
    SerialPort *arduino; // doit etre un objet global!
    json messageReceived;
    json message_to_send;

    
    bool SendToSerial();
    bool RcvFromSerial();
    etatJoystick GetJoyXMenu0();
    etatJoystick GetJoyYMenu0();
    etatBoutton GetB1Menu0();

public:
    ControllerControls(EventManager *em, string com);
    void InitializeSerial();
    void ListenForControls();
    void AddMessage(string name, int value);
    void AddMessage(string name, bool value);
    void AddMessage(string name, string value);
    void AddMessage(string name, float value);

    void GetValue(string name, int* value);
    void GetValue(string name, bool* value);
    void GetValue(string name, string* value);
    void GetValue(string name, float* value);

    bool SendMessageJson();

    
    
    
};

#endif