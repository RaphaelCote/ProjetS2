#ifndef GAMELOADER_H
#define GAMELOADER_H

#include "niveau.h"

class Gameloader
{
public:
    Gameloader();
    ~Gameloader();
    Niveau *getLevelFromJson(string filename);
};

#endif