#ifndef EVENTPARAMETERS_H
#define EVENTPARAMETERS_H

class EventParameters
{
public:
    // EventListener *caller;
    float parameter1;
    float parameter2;

    EventParameters()
    {
        parameter1 = 0;
        parameter2 = 0;
    }

    EventParameters(float p1)
    {
        parameter1 = p1;
        parameter2 = 0;
    }

    EventParameters(float p1, float p2)
    {
        parameter1 = p1;
        parameter2 = p2;
    }
};

#endif