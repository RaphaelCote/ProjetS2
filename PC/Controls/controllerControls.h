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

class ControllerControls : public Controls
{
    string comPort;
    string raw_msg;
    SerialPort *arduino; // doit etre un objet global!
    json messageReceived;
    json message_to_send;

    
    bool SendToSerial();
    bool RcvFromSerial();

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