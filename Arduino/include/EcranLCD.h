
#ifndef ECRANLCD_H
#define ECRANLCD_H

#define pinRS 30
#define pinRW 30
#define pinENABLE 30


#define pinData1 30
#define pinData2 30
#define pinData3 30
#define pinData4 30
#define pinData5 30
#define pinData6 30
#define pinData7 30
#define pinData8 30


#define STARTING_PIN_LCD 30


enum etatEcranLCD
{
    EcranLCDEnabled = 1,
    EcranLCDDisabled = 2
};


class EcranLCD
{
private:
    etatEcranLCD etat;
        


public:
    EcranLCD();
    ~EcranLCD();
    
    etatEcranLCD GetEtat();
    void SetEtat(etatEcranLCD etatVoulu);
    void ActualiseEcranLCD(int puissance);

    bool EcrireCommande(char c);
    bool EcrireData(char c);

    
};




#endif