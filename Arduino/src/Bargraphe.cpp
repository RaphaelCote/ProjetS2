
#include<Arduino.h>
#include"Bargraphe.h"

Bargraphe::Bargraphe(int pX, int pY, int pZ)
{
    for(int i = 0; i < NOMBRE_LED; i++)
    {
        pinMode(i+STARTING_PIN, OUTPUT);
    }
}

Bargraphe::~Bargraphe()
{

}

void Bargraphe::ActualiseBargraphe()
{
    int masque = 0x01;
    for(int i = 0; i < NOMBRE_LED; i++)
    {
        digitalWrite(i+STARTING_PIN, barLED&masque);
        masque >> 1;
    }
}

    
etatBargraphe Bargraphe::GetEtat()
{
    return etat;
}

void Bargraphe::SetEtat(etatBargraphe etatVoulu)
{
    etat = etatVoulu;
}


