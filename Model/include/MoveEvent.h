/*
 * File:   MoveEvent.h
 * Author: Lucas Adam M. Paul
 *
 * Created on 2012/04/14 13:48:24
 */

#ifndef MOVEEVENT_H
#define	MOVEEVENT_H

#include "Event.h"
#include "Tile.h"
#include "TitanTime.h"
#include "Rover.h"

namespace Model {

    /**
     * Represents a movement event in the game.
     */
    class MoveEvent : public Event {
    public:
        /**
         * Create a new event with given completion time. When fired, it will
         * use the given function pointers to do its work.
         */
        MoveEvent(void* m,
                  Titan::TitanTime time,
                  GameOver_t gameover,
                  GetTile_t gettile,
                  InsertEvent_t insertevent,
                  Rover& rover,
                  char direction);

        bool fire();

    private:
        Rover& rover;
        Tile* origin;
        Tile* destination;
        int newx, newy;
    };
}

#endif /* EVENT_H */
