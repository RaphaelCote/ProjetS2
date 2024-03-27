#ifndef MAPING_H
#define MAPING_H
#include "../Game/niveau.h"
//#include "scene.h"
class Maping
{
    public:
        void ScanHitboxes();
        Maping();
        ~Maping();
        Niveau activelevel;
        Vecteur<Hitbox> allHitboxObject;
    private:


};
#endif