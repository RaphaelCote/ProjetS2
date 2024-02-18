
#ifndef ECRANLCD_H
#define ECRANLCD_H

#define pinRS 51
#define pinRW 52
#define pinENABLE 53


#define pinData1 30
#define pinData2 30
#define pinData3 30
#define pinData4 30
#define pinData5 30
#define pinData6 30
#define pinData7 30
#define pinData8 30


#define STARTING_PIN_LCD 43


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
    void Initialisation();
    void ClearLCD();

    etatEcranLCD GetEtat();
    void SetEtat(etatEcranLCD etatVoulu);
    void ActualiseEcranLCD(int puissance);

    bool Cursor(bool state, int x, int y);

    bool EcrireTableau(char tab[2][16], int length, int height);
    bool EcrireLigne(char *tab, int length, int height);

    bool EcrireData(char data, int x, int y);

    bool EcrireCommande(char c);
    bool EcrireData(char c);

    
};




#endif