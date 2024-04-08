#ifndef GAMELOADER_H

#define GAMELOADER_H
#include "niveau.h"

class Gameloader
{
private:
public:
    Gameloader();
    ~Gameloader();
    Niveau *getLevelFromJson(std::string filename);
};

#endif