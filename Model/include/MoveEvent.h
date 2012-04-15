/*
 * File:   MoveEvent.h
 * Author: Lucas Adam M. Paul
 *
 * Created on 2012/04/14 13:48:24
 */

#ifndef MOVEEVENT_H
#define	MOVEEVENT_H

#include "Event.h"
#include "AbstractTile.h"
#include "TitanTime.h"
#include "Rover.h"

namespace EventNameSpace {

    /**
     * Represents a movement event in the game.
     */
    class MoveEvent : public Event {
    public:
        /**
         * Create a new event with given completion time. When fired, it will
         * use the given function pointers to do its work.
         */
        MoveEvent(Titan::TitanTime time,
                  GameOver_t gameover,
                  GetTile_t gettile,
                  InsertEvent_t insertevent,
                  ThingNameSpace::Rover& rover,
                  char direction);

        bool fire();

    private:
        ThingNameSpace::Rover& rover;
        AbstractModelNameSpace::AbstractTile* origin;
        AbstractModelNameSpace::AbstractTile* destination;
    }
}

#endif /* EVENT_H */
