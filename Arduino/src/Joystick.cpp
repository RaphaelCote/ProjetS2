
#include<Arduino.h>
#include"Joystick.h"

Joystick::Joystick(int pX, int pY)
{
    pinX = pX;
    pinY = pY;
    

    pinMode(pX, INPUT);
    pinMode(pY, INPUT);
    
}

Joystick::~Joystick()
{

}
    
etatJoystick Joystick::GetEtat()
{
    return etat;
}

void Joystick::SetEtat(etatJoystick etatVoulu)
{
    etat = etatVoulu;
}


bool Joystick::GetX(int * val)
{
    if(etat == etatJoystick::JoystickDisabled)
        return false;
    
    *val = analogRead(pinX);

    return true;
}

bool Joystick::GetY(int * val)
{
    if(etat == etatJoystick::JoystickDisabled)
        return false;
    
    *val = analogRead(pinY);

    return true;
}



bool Joystick::GetAll(int * valX, int* valY)
{
    
    if(etat == etatJoystick::JoystickDisabled)
        return false;
    
    *valX = analogRead(pinX);
    *valY = analogRead(pinY);
   

    return true;

}



etatJoystick Joystick::updateJoystickMenuX()
{
    if(etat == etatJoystick::JoystickDisabled)
        return etat;

    oldEtat = etat;
    

    if(etat != oldEtat)//changement d'etat
    {
        timer = millis();//reset timer
    }

    if(millis()- timer >=  DEBOUNCE_TIME_MS_JOY)//if debounce finished
    {
        if(analogRead(pinX) >= MIDDLE+TRESHOLD)//update valueX
        {
            etat = etatJoystick::JoystickLeft;
        }
        else if(analogRead(pinX) <= MIDDLE-TRESHOLD)
        {
            etat = etatJoystick::JoystickRight;
        }
        else
        {
            etat = etatJoystick::JoystickMiddle;
        }
    }
    return etat;

}



etatJoystick Joystick::updateJoystickMenuY()
{
    if(etat == etatJoystick::JoystickDisabled)
        return etat;

    oldEtat = etat;

    if(millis()- timer >=  DEBOUNCE_TIME_MS_JOY)//if debounce finished
    {
        
        if(analogRead(pinY) >= MIDDLE+TRESHOLD)//update valueY
        {
            etat = etatJoystick::JoystickUp;
            // Serial.println("UP");
        }
        else if(analogRead(pinY) <= MIDDLE-TRESHOLD)
        {
            etat = etatJoystick::JoystickDown;
            // Serial.println("DOWN");
        }
        else
        {
            etat = etatJoystick::JoystickMiddle;
            // Serial.println("MIDDLE");
        }

        if(oldEtat != etat)
        {
            timer = millis();//reset timer
        }
    }
    return etat;
}