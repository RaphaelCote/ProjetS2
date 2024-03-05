#ifndef LEVELGETTER_H
#define LEVELGETTER_H

#include <iostream>
#include <windows.h>

#include "../Vecteur.h"

using namespace std;

class LevelGetter
{
public: 
    LevelGetter();
    Vecteur<string> levels;
    int nbLevel = 0;
};


#endif