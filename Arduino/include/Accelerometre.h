
#ifndef ACCELEROMETRE_H
#define ACCELEROMETRE_H


enum etatAccelerometre
{
    AccelerometreEnabled = 1,
    AccelerometreDisabled = 2
};


class Accelerometre
{
private:
    etatAccelerometre etat;
    int pinX, pinY, pinZ;
    //int valueX, valueY, valueZ;


public:
    Accelerometre(int pX, int pY, int pZ);
    ~Accelerometre();
    
    etatAccelerometre GetEtat();
    void SetEtat(etatAccelerometre etatvoulu);

    bool GetX(int * val);
    bool GetY(int * val);
    bool GetZ(int * val);

    bool GetAll(int * valX, int* valY, int* valZ);
};




#endif