/*
 * File:   AbstractEvent.h
 * Author: Lucas Adam M. Paul
 *
 * Created on 2012/04/08 17:13:48
 */

#ifndef ABSTRACTEVENT_H
#define	ABSTRACTEVENT_H

namespace AbstractModelNameSpace {

    /**
     * Represents an event in the game. Could be anything from a rover moving
     * from one square to another, to a rock falling, to Game Over.
     */
    class AbstractEvent {
    public:
        /**
         * This method will apply the effects of this Event to the game state.
         * @return true on success, false if the event could not be applied
         */
        virtual bool fire() = 0;

        /**
         * Define what it means to be less than another Event
         * @param other
         * @return
         */
        virtual bool operator <(const AbstractEvent &other) const = 0;

        /**
         * Defines what it means for this Event to be greater than another.
         * @param other
         * @return
         */
        virtual bool operator >(const AbstractEvent &other) const = 0;
    }
}

#endif /* ABSTRACTEVENT_H */
