
#include "Boutton.h"
#include <Arduino.h>

Boutton::Boutton(int p)
{
    pinMode(p, INPUT);
    pin = p;
    timer = millis();
    etat = etatBoutton::BouttonEnabled;
    oldEtat = etat;

}

Boutton::~Boutton()
{
}

void Boutton::Update()
{
    if(etat == etatBoutton::BouttonDisabled)
        return;

    oldEtat = etat;
    

    if(etat != oldEtat)//changement d'etat
    {
        timer = millis();//reset timer
    }

    if(millis()- timer >=  DEBOUNCE_TIME_MS)//if debounce finished
    {
        if(digitalRead(pin) == ETAT_ON)
        {
            etat = etatBoutton::BouttonAppuyer;
        }
        else
        {
            etat = etatBoutton::BouttonRelacher;
        }
    }
    
}


etatBoutton Boutton::GetEtat()
{
    return etat;
}

void Boutton::SetEtat(etatBoutton etatVoulu)
{
    etat = etatVoulu;
}