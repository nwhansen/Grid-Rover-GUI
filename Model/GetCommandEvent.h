/*
 * File:   GetCommandEvent.h
 * Author: Lucas Adam M. Paul
 *
 * Created on 2012/04/17 16:44:24
 */

#ifndef GETCOMMANDEVENT_H
#define	GETCOMMANDEVENT_H

#include "Event.h"
#include "TitanTime.h"
#include "Rover.h"
#include "RoverInterface.h"

namespace Model {

    class Engine;

    /**
     * Represents an opportunity for a rover to provide a high-level command
     * in the game.
     */
    class GetCommandEvent : public Event {
    public:

        /**
         * Create a new event with given completion time. When fired, it will
         * use the given function pointers to do its work.
         */
        GetCommandEvent(Engine* m, Titan::TitanTime time);

        ResultType fire();

    private:
    };
}

#endif /* GETCOMMANDEVENT_H */
