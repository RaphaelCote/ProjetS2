
#include<Arduino.h>
#include"Accelerometre.h"

Accelerometre::Accelerometre(int pX, int pY, int pZ)
{
    pinX = pX;
    pinY = pY;
    pinZ = pZ;

    pinMode(pX, INPUT);
    pinMode(pY, INPUT);
    pinMode(pZ, INPUT);
}

Accelerometre::~Accelerometre()
{

}
    
etatAccelerometre Accelerometre::GetEtat()
{
    return etat;
}

void Accelerometre::SetEtat(etatAccelerometre etatVoulu)
{
    etat = etatVoulu;
}


bool Accelerometre::GetX(int * val)
{
    if(etat == etatAccelerometre::AccelerometreDisabled)
        return false;
    
    *val = analogRead(pinX);

    return true;
}

bool Accelerometre::GetY(int * val)
{
    if(etat == etatAccelerometre::AccelerometreDisabled)
        return false;
    
    *val = analogRead(pinY);

    return true;
}

bool Accelerometre::GetZ(int * val)
{
    if(etat == etatAccelerometre::AccelerometreDisabled)
        return false;
    
    *val = analogRead(pinZ);

    return true;
}

bool Accelerometre::GetAll(int * valX, int* valY, int* valZ)
{
    
    if(etat == etatAccelerometre::AccelerometreDisabled)
        return false;
    
    *valX = analogRead(pinX);
    *valY = analogRead(pinY);
    *valZ = analogRead(pinZ);
    // Serial.print("x: ");
    // Serial.print(*valX);
    // Serial.print("   y: ");
    // Serial.print(*valY);
    // Serial.print("   z: ");
    // Serial.println(*valZ);

    return true;

}