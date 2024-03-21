#ifndef GAMELOADER_H
#define GAMELOADER_H

#include "level.h"

class Level;

class Gameloader
{
public:
    Gameloader();
    ~Gameloader();
    Level *getLevelFromJson(string filename);
};
#endif