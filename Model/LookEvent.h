/*
 * File:   MoveEvent.h
 * Author: Lucas Adam M. Paul
 *
 * Created on 2012/04/15 16:18:58
 */

#ifndef LOOKEVENT_H
#define	LOOKEVENT_H

#include "Event.h"
#include "TitanTime.h"
#include "Rover.h"
#include "Result.h"

namespace Model {

    class Engine;

    /**
     * Represents an observation event in the game.
     */
    class LookEvent : public Event {
    public:
        /**
         * Create a new event with given completion time. When fired, it will
         * use the given function pointers to do its work.
         */
        LookEvent(Engine* m,
                  Titan::TitanTime time,
                  Rover* r,
                  int objid) : Event(m, time),
                               rover(r);

        ResultType fire();

    private:
        Rover* rover;
        int target;
    }
}

#endif /* LOOKEVENT_H */
