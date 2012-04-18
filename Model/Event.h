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
#include "Result.h"

namespace Model {

    class Engine;

    /**
     * Represents an event in the game. Could be anything from a rover moving
     * from one square to another, to a rock falling, to Game Over.
     */
    class Event {
    public:

        /**
         * Create a new event with given completion time. When fired, it will
         * use the given function pointers to do its work.
         */
        Event(Engine* e,
                Titan::TitanTime time) : engine(e), completionTime(time) {
        }

        /**
         * Fire this event, applying its effects to the game state.
         */
        virtual ResultType fire() {};

        /**
         * Define what it means to be less than another Event
         * @param other
         * @return
         */
        bool operator<(const Event &other) const {
            //There is only one operator defined for TitanTime, so just flip the items such that the 
            //Operation is inverted.
            return other.completionTime > completionTime;
        }

        /**
         * Defines what it means for this Event to be greater than another.
         * @param other
         * @return
         */
        bool operator>(const Event &other) const {
            return completionTime > other.completionTime;
        }

    protected:
        Engine* engine;
        Titan::TitanTime completionTime;
    };
}

#endif /* EVENT_H */
