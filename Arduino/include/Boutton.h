
#ifndef BOUTTON_H
#define BOUTTON_H

#define DEBOUNCE_TIME_MS 5
#define TEMPS_TENU_APPUYER_MS 500
#define ETAT_ON 1
#define ETAT_OFF 0


enum etatBoutton
{
    BouttonAppuyer = 1,
    BouttonRelacher = 0,
    BouttonTenuAppuyer = 2,
    BouttonEnabled = 3,
    BouttonDisabled = 4
};


class Boutton
{
private:
    etatBoutton etat;
    etatBoutton oldEtat;
    unsigned long timer;
    int pin;


public:
    Boutton(int p);
    ~Boutton();
    etatBoutton Update();
    etatBoutton GetEtat();
    void SetEtat(etatBoutton etatVoulu);
};




#endif