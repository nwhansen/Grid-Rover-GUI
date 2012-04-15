/*
 * File:   Event.h
 * Author: Lucas Adam M. Paul
 *
 * Created on 2012/04/10 20:44:48
 */

#ifndef EVENT_H
#define	EVENT_H

#include "AbstractEvent.h"
#include "AbstractTile.h"
#include "TitanTime.h"

namespace EventNameSpace {

    typedef void(*GameOver_t)();
    typedef AbstractModelNameSpace::AbstractTile(*GetTile_t)(int, int);
    typedef void(*InsertEvent_t)(AbstractModelNameSpace::AbstractEvent);

    /**
     * Represents an event in the game. Could be anything from a rover moving
     * from one square to another, to a rock falling, to Game Over.
     */
    class Event : public AbstractModelNameSpace::AbstractEvent {
    public:
        /**
         * Create a new event with given completion time. When fired, it will
         * use the given function pointers to do its work.
         */
        Event(Titan::TitanTime time,
              GameOver_t gameover,
              GetTile_t gettile,
              InsertEvent_t insertevent) : completionTime(time),
                                           gameOver(gameover),
                                           getTile(gettile),
                                           insertEvent(insertevent)
        {}

        /**
         * Define what it means to be less than another Event
         * @param other
         * @return
         */
        bool operator <(const AbstractModelNameSpace::AbstractEvent &other) {
            return completionTime < other.completionTime;
        }

        /**
         * Defines what it means for this Event to be greater than another.
         * @param other
         * @return
         */
        bool operator >(const AbstractModelNameSpace::AbstractEvent &other) {
            return completionTime > other.completionTime;
        }

    private:
        Titan::TitanTime completionTime;
        GameOver_t gameOver;
        GetTile_t getTile;
        InsertEvent_t insertEvent;
    }
}

#endif /* EVENT_H */
