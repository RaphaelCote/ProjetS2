
#include<Arduino.h>
#include"Moteur.h"

Moteur::Moteur(int pin)
{
    pin1 = pin;
    etat = etatMoteur::MoteurEnabled;
}

Moteur::~Moteur()
{

}

void Moteur::ActualiseMoteur(int puissance)
{
    if(etat == etatMoteur::MoteurDisabled)
        return;

    analogWrite(pin1, puissance);
}

    
etatMoteur Moteur::GetEtat()
{
    return etat;
}

void Moteur::SetEtat(etatMoteur etatVoulu)
{
    etat = etatVoulu;
}


