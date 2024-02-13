
#ifndef BARGRAPHE_H
#define BARGRAPHE_H

#define NOMBRE_LED 10
#define STARTING_PIN 22

enum etatBargraphe
{
    BargrapheEnabled = 1,
    BargrapheDisabled = 2
};


class Bargraphe
{
private:
    etatBargraphe etat;
    int pin1, pin2, pin3, pin4, pin5, pin6;
    int barLED;
    //int valueX, valueY, valueZ;
    void ActualiseBargraphe();


public:
    Bargraphe(int pX, int pY, int pZ);
    ~Bargraphe();
    
    etatBargraphe GetEtat();
    void SetEtat(etatBargraphe etatVoulu);


    void AllumeBargraphePuissance(int puissance);

    
};




#endif