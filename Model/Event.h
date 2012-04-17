/*
 * File:   Event.h
 * Author: Lucas Adam M. Paul
 *
 * Created on 2012/04/10 20:44:48
 */

#ifndef EVENT_H
#define	EVENT_H

#include "Tile.h"
#include "TitanTime.h"

namespace Model {

    class Engine;

    typedef void(*GameOver_t)(void*);
    typedef Tile(*GetTile_t)(void*, int, int);
    typedef void(*InsertEvent_t)(void*, Event);

    /**
     * Represents an event in the game. Could be anything from a rover moving
     * from one square to another, to a rock falling, to Game Over.
     */
    class Event{
    public:
        /**
         * Create a new event with given completion time. When fired, it will
         * use the given function pointers to do its work.
         */
        Event(Engine* m,
              Titan::TitanTime time) : model(m)
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
        Engine* engine;
        Titan::TitanTime completionTime;
    };
}

#endif /* EVENT_H */
