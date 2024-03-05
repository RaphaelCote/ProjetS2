#ifndef SCENE_H
#define SCENE_H

#include "../controls/EventListener.h"

using namespace std;

class Scene : public EventListener
{

public:
    Scene();
    ~Scene();
    virtual void Update() = 0;

private:
};

#endif