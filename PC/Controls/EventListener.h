#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include "eventParameters.h"
class EventListener
{
public:
    virtual void OnEnable() = 0;
    virtual void OnDisable() = 0;
};

#endif