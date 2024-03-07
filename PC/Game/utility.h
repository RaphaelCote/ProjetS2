#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
//Class Timer

//timer fonctionnel, il sufit juste de decommenter le code correspondant dans le utility.h et utility.cpp (et inclure "#include <Arduino.h>")

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
    int x = 0;
    int y = 0;
};

struct Hitbox
{
    Coordonnee cordonnees; //en bas a gauche
    int height = 0;
    int width = 0;
};

struct Velocity 
{
    float puissance = 0;
    float angledeg = 0;
};

#endif
