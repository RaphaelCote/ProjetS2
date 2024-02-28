
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

etatBoutton Boutton::Update()
{
    if(etat == etatBoutton::BouttonDisabled)
        return etat;

    oldEtat = etat;
    

    if(etat != oldEtat)//changement d'etat
    {
        timer = millis();//reset timer
    }

    if(millis()- timer >=  DEBOUNCE_TIME_MS)//if debounce finished
    {
        if(digitalRead(pin) == ETAT_ON)//change l'etat du boutton
        {
            etat = etatBoutton::BouttonAppuyer;
        }
        else
        {
            etat = etatBoutton::BouttonRelacher;
        }
    }
    return etat;
}


etatBoutton Boutton::GetEtat()
{
    return etat;
}

void Boutton::SetEtat(etatBoutton etatVoulu)
{
    etat = etatVoulu;
}