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
    bool Thread_Actif;
    etatBoutton etatB1;
    etatBoutton oldEtatB1;

    etatJoystick etatJoyX;
    etatJoystick etatJoyY;
    etatJoystick oldEtatJoyX;
    etatJoystick oldEtatJoyY;

    string comPort;
    string raw_msg;
    SerialPort *arduino;
    json messageReceived;
    json message_to_send;

    

    
    DWORD WINAPI threadFunction(LPVOID lpParam);
    
    bool SendToSerial();
    bool RcvFromSerial();
    etatJoystick GetJoyXMenu0();
    etatJoystick GetJoyYMenu0();
    etatBoutton GetBouttonMenu0(int boutton);

public:
    bool ready_to_send;
    bool ready_to_read;

    ControllerControls(EventManager *em, string com);
    void ThreadReceiveSerial();
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