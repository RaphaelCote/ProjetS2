
#include<Arduino.h>
#include"Bargraphe.h"

Bargraphe::Bargraphe()
{
    for(int i = 0; i < NOMBRE_LED; i++)
    {
        pinMode(i+STARTING_PIN, INPUT);
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
        if(barLED&masque)
        {
            pinMode(i+STARTING_PIN, INPUT);
        }
        else
        {
            pinMode(i+STARTING_PIN, OUTPUT);
            digitalWrite(i+STARTING_PIN, LOW);
        }
        
        masque = masque << 1;
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

void Bargraphe::AllumeBargraphePuissance(int puissance)
{
    int i = 10;
    barLED = 0x00;

    while (i <= puissance)
    {
        barLED = barLED >> 1;
        barLED += 0x0200;
        i+=10;
    }
    ActualiseBargraphe();
}

void Bargraphe::AllumeBits(int value)
{
    barLED = value;
    ActualiseBargraphe();
}
