
#include<Arduino.h>
#include"EcranLCD.h"

EcranLCD::EcranLCD()
{
    etat = etatEcranLCD::EcranLCDEnabled;
}

EcranLCD::~EcranLCD()
{

}
    
etatEcranLCD EcranLCD::GetEtat()
{
    return etat;
}

void EcranLCD::SetEtat(etatEcranLCD etatVoulu)
{
    etat = etatVoulu;
}



bool EcranLCD::EcrireCommande(char c)
{
    int masque = 0x01;
    for(int i = 0; i < 8; i++)
    {
        if(c&masque)
        {
            digitalWrite(i+STARTING_PIN_LCD, HIGH);
        }
        else
        {
            digitalWrite(i+STARTING_PIN_LCD, LOW);
        }
        
        masque = masque >> 1;
    }

    digitalWrite(pinRS, LOW);
    digitalWrite(pinRW, LOW);
    digitalWrite(pinENABLE,HIGH);
    delay(1);
    digitalWrite(pinENABLE, LOW);
}

bool EcranLCD::EcrireData(char c)
{
    int masque = 0x01;
    for(int i = 0; i < 8; i++)
    {
        if(c&masque)
        {
            digitalWrite(i+STARTING_PIN_LCD, HIGH);
        }
        else
        {
            digitalWrite(i+STARTING_PIN_LCD, LOW);
        }
        
        masque = masque >> 1;
    }
    
    digitalWrite(pinRS, HIGH);
    digitalWrite(pinRW, LOW);
    digitalWrite(pinENABLE,HIGH);
    delay(1);
    digitalWrite(pinENABLE, LOW);
}

