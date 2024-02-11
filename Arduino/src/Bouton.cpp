
#include "Boutton.h"
#include <Arduino.h>

Boutton::Boutton(int p)
{
    pinMode(p, INPUT);
    pin = p;
    timer = 0;
    etat = etatBoutton::BouttonEnabled;

}

Boutton::~Boutton()
{
}

void Boutton::Update()
{
    if(etat == etatBoutton::BouttonDisabled)
        return;

    if(digitalRead(pin) == ETAT_ON)
    {
        
    }
    
}


etatBoutton Boutton::GetEtat()
{

}