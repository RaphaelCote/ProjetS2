#ifndef GAMELOADER_H

#define GAMELOADER_H
#include "niveau.h"
class Gameloader
{
private:
public:
    Gameloader();
    ~Gameloader();
    Niveau *getLevelsFromJson(string filename);
};

#endif