/*
 * Auteurs : Shubham Anand
 * Récupéré le : 8 février 2024
 * lien : https://medium.com/@alwayswannaly/applied-event-driven-programming-with-c-b2f6977f0b72
 * Modifié : Raphael Côté, février 2024
 * Modifications : Changer le paramêtre int des fonctions pour un EventParameter
 *                 Ajout de la fonction off qui retire un listener de la liste
 */

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <functional>

#include "eventParameters.h"
#include "eventListener.h"

class EventManager
{

private:
    std::map<std::string, std::vector<void (*)(EventParameters)>> events;

public:
    EventManager() {
    }

    EventManager *on(std::string event_name, void (*callback)(EventParameters))
    {

        // we're using a pointer to reference `events[event_name]` so as
        // to get reference to original object and not the copy object.
        std::vector<void (*)(EventParameters)> *listeners = &events[event_name];

        // if this listener is already registered, we wont add it again
        if (std::find(listeners->begin(), listeners->end(), callback) != listeners->end())
        {
            return this;
        }

        listeners->push_back(callback);

        return this;
    }

    bool off(std::string event_name, void (*callback)(EventParameters))
    {

        // we're using a pointer to reference `events[event_name]` so as
        // to get reference to original object and not the copy object.
        std::vector<void (*)(EventParameters)> *listeners = &events[event_name];

        // if this listener is already registered, we wont add it again
        if (std::find(listeners->begin(), listeners->end(), callback) != listeners->end())
        {
            listeners->erase(std::find(listeners->begin(), listeners->end(), callback));
            return true;
        }

        return false;
    }

    bool emit(std::string event_name, EventParameters param)
    {
        std::vector<void (*)(EventParameters)> listeners = events[event_name];

        if (listeners.size() == 0)
            return false;

        // Run all the listeners associated with the event
        for (int idx = 0; idx < listeners.size(); idx += 1)
        {
            void (*func)(EventParameters) = listeners.at(idx);

            listeners[idx](param);
        }

        return true;
    }
};

#endif