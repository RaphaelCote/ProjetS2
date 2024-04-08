#ifndef SCENE_H
#define SCENE_H

#include "../controls/EventListener.h"


class Scene : public EventListener
{

public:
    Scene();
    ~Scene();
    virtual void Update() = 0;
};

#endif