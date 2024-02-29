
#ifndef MOTEUR_H
#define MOTEUR_H



enum etatMoteur
{
    MoteurEnabled = 1,
    MoteurDisabled = 2
};


class Moteur
{
private:
    etatMoteur etat;
    int pin1;
    
    


public:
    Moteur(int pin);
    ~Moteur();
    
    etatMoteur GetEtat();
    void SetEtat(etatMoteur etatVoulu);


    void ActualiseMoteur(int puissance);

    
};




#endif