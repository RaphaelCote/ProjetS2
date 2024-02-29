
#ifndef JOYSTICK_H
#define JOYSTICK_H


#define MIDDLE 512
#define TRESHOLD 200
#define DEBOUNCE_TIME_MS_JOY 3


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


class Joystick
{
private:
    etatJoystick etat;
    etatJoystick oldEtat;
    unsigned long timer;
    int pinX, pinY;
    //int valueX, valueY, valueZ;


public:
    Joystick(int pX, int pY);
    ~Joystick();
    
    etatJoystick GetEtat();
    void SetEtat(etatJoystick etatvoulu);

    bool GetX(int * val);
    bool GetY(int * val);

    bool GetAll(int * valX, int* valY);

    etatJoystick updateJoystickMenuX();
    etatJoystick updateJoystickMenuY();
};




#endif