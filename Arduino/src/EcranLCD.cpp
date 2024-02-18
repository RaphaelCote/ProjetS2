
#include<Arduino.h>
#include"EcranLCD.h"

EcranLCD::EcranLCD()
{
    for(int i = 0; i < 8; i++)
    {
        pinMode(i+STARTING_PIN_LCD, OUTPUT);
    }
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

void EcranLCD::Initialisation()
{
    for(int i = 0; i < 11; i++)
    {
        pinMode(i+STARTING_PIN_LCD, OUTPUT);
        digitalWrite(i+STARTING_PIN_LCD, LOW);
    }


    etat = etatEcranLCD::EcranLCDEnabled;

    EcrireCommande(0x30);
    delay(10);
    EcrireCommande(0x38);
    //EcrireCommande(0x10);

    EcrireCommande(0x0C);//display on
    EcrireCommande(0x01);
    EcrireCommande(0x06);
}

bool EcranLCD::Cursor(bool state, int x, int y)
{
    if(state)
    {
        EcrireCommande(0x0D);//display on
    }
    else
    {
        EcrireCommande(0x0C);//display on
    }

    char c = y*0x40+x;
    EcrireCommande(c+0x80);
    return true;
}

void EcranLCD::ClearLCD()
{
    EcrireCommande(0x01);
}

bool EcranLCD::EcrireTableau(char tab[2][16], int length, int height)
{
    for (int i = 0; i < height; i++)
    {
        char c = i*0x40;
        EcrireCommande(c+0x80);
        for (int J = 0; J < length; J++)
        {
            EcrireData(tab[i][J]);
        }
        
    }

    return true;
}


bool EcranLCD::EcrireLigne(char *tab, int length, int height)
{
    char c = height*0x40;
    EcrireCommande(c+0x80);
    for (int J = 0; J < length; J++)
    {
        EcrireData(tab[J]);
    }

    return true;
}

bool EcranLCD::EcrireCharactere(char data, int x, int y)
{
    char c = y*0x40+x;
    EcrireCommande(c+0x80);
    EcrireData(data);
    return true;
}

bool EcranLCD::EcrireCommande(char c)
{
    int masque = 0x01;

    for(int i = 0; i < 8; i++)//setting the pins
    {
        if(c&masque)
        {
            digitalWrite(i+STARTING_PIN_LCD, HIGH);
        }
        else
        {
            digitalWrite(i+STARTING_PIN_LCD, LOW);
        }

        // Serial.print("Data: ");
        // Serial.print(int(c));
        // Serial.print("  masque: ");
        // Serial.print(masque);
        // Serial.print("   Reponse: ");
        // Serial.println(c&masque);
        
        
        masque = masque << 1;
    }

    digitalWrite(pinRS, LOW);
    digitalWrite(pinRW, LOW);
    digitalWrite(pinENABLE,HIGH);
    delayMicroseconds(1000);
    digitalWrite(pinENABLE, LOW);
    
    return true;
}

bool EcranLCD::EcrireData(char c)
{
    int masque = 0x01;
    for(int i = 0; i < 8; i++)//setting the pins
    {
        if(c&masque)
        {
            digitalWrite(i+STARTING_PIN_LCD, HIGH);
        }
        else
        {
            digitalWrite(i+STARTING_PIN_LCD, LOW);
        }
        // Serial.print("Lettre ");
        // Serial.print("Data: ");
        // Serial.print(int(c));
        // Serial.print("  masque: ");
        // Serial.print(masque);
        // Serial.print("   Reponse: ");
        // Serial.println(c&masque);
        
        masque = masque << 1;
    }
    
    digitalWrite(pinRS, HIGH);
    digitalWrite(pinRW, LOW);
    digitalWrite(pinENABLE,HIGH);
    delayMicroseconds(1000);
    digitalWrite(pinENABLE, LOW);
    
    return true;
}

