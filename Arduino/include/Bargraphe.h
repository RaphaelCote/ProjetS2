
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
    
    int barLED;
    //int valueX, valueY, valueZ;
    void ActualiseBargraphe();


public:
    Bargraphe();
    ~Bargraphe();
    
    etatBargraphe GetEtat();
    void SetEtat(etatBargraphe etatVoulu);


    void AllumeBargraphePuissance(int puissance);
    void AllumeBits(int value);

    
};




#endif