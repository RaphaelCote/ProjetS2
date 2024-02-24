#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
//Class Timer

//timer fonctionnel, il sufit juste de décommenter le code correspondant dans le utility.h et utility.cpp (et inclure "#include <Arduino.h>")

// class Timer {
// public:
//     Timer(unsigned long interval);//constructeur
//     bool check();// methode de la classe Timer

// private:
//     unsigned long previousMillis;    
//     unsigned long interval;
// };





struct Coordonnee
{
     int x;
     int y;
};

struct Hitbox
{
    int height;
    int width;
};

struct Velocity 
{
    float puissance;
    float angledeg;
};

#endif
