#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

class EventListener
{
public:
    virtual void OnEnable() = 0;
    virtual void OnDisable() = 0;
};

#endif