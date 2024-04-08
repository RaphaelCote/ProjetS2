#ifndef LEVELGETTER_H
#define LEVELGETTER_H

#include <iostream>
#include <windows.h>
#include <vector>


class LevelGetter
{
public: 
    LevelGetter();
    std::vector<std::string> levels;
    int nbLevel = 0;
};


#endif