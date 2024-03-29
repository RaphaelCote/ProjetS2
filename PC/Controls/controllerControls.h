#ifndef CONTROLLERCONTROLS_H
#define CONTROLLERCONTROLS_H

#include <iostream>
#include <string>

#include "controls.h"
#include "../include/serial/SerialPort.hpp"
#include "../include/json.hpp"
#include "../raftWars.h"

using json = nlohmann::json;

#define BAUD 115200       // Frequence de transmission serielle
#define MSG_MAX_SIZE 1024 // Longueur maximale d'un message
#define GROSSEUR_TAB_ANGLE 10

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

    string comPort;
    string raw_msg;
    SerialPort *arduino;
    json messageReceived;
    json message_to_send;

    DWORD WINAPI threadFunction(LPVOID lpParam);

    bool SendToSerial();
    bool RcvFromSerial();
    etatJoystick GetJoyXMenu0(float *value);
    etatJoystick GetJoyYMenu0(float *value);
    etatBoutton GetBouttonMenu0(int boutton);

public:
    bool ready_to_send;
    bool ready_to_read;

    etatBoutton etatB1;
    etatBoutton oldEtatB1;
    etatBoutton etatB2;
    etatBoutton oldEtatB2;
    etatBoutton etatB3;
    etatBoutton oldEtatB3;
    etatBoutton etatB4;
    etatBoutton oldEtatB4;
    etatBoutton etatB5;
    etatBoutton oldEtatB5;

    etatJoystick etatJoyX;
    etatJoystick etatJoyY;
    etatJoystick oldEtatJoyX;
    etatJoystick oldEtatJoyY;

    float JoystickValX;
    float JoystickValY;

    float AngleManette;
    float Tab_AnglesManette[GROSSEUR_TAB_ANGLE];

    ControllerControls(EventManager *em, string com);
    void ThreadReceiveSerial();
    void ReceiveSerial();
    void UpdateAllValues();
    void InitializeSerial();
    void ListenForControls();
    void AddMessage(string name, int value);
    void AddMessage(string name, bool value);
    void AddMessage(string name, string value);
    void AddMessage(string name, float value);

    void GetValue(string name, int *value);
    void GetValue(string name, bool *value);
    void GetValue(string name, string *value);
    void GetValue(string name, float *value);

    bool SendMessageJson();
};

#endif