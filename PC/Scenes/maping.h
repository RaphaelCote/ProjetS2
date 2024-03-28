#ifndef MAPING_H
#define MAPING_H
#include "../vecteur.h"
#include "../Game/niveau.h"
#include "../Game/gameloader.h"
extern Niveau* activeLevel;
//#include "scene.h"
class Maping
{
    public:
        void ScanHitboxes(Niveau *niveau);
        Maping();
        ~Maping();
        Vecteur<Hitbox*> allHitboxObject;
        Gameloader gameloader;
    private:


};
#endif