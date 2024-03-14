#ifndef GAMELOADER_H

#define GAMELOADER_H
#include "niveau.h"
class Gameloader
{
private:
public:
    Niveau *ptrniveau;

    Gameloader();
    ~Gameloader();
    void getLevelsFromJson();
};

#endif