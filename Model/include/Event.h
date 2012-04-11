/*
 * File:   Event.h
 * Author: Lucas Adam M. Paul
 *
 * Created on 2012/04/10 20:44:48
 */

#ifndef EVENT_H
#define	EVENT_H

#include "AbstractModel.h"
#include "AbstractEvent.h"
#include "TitanTime.h"

namespace StackModelNameSpace {

    /**
     * Represents an event in the game. Could be anything from a rover moving
     * from one square to another, to a rock falling, to Game Over.
     */
    class Event : public AbstractModelNamespace::AbstractEvent {
    public:
        /**
         * Create a new event with given completion time. It will apply to the
         * given model when fired.
         */
        Event(Titan::TitanTime t, AbstractModelNamespace::AbstractModel m) : completionTime(t), model(m);

        /**
         * Define what it means to be less than another Event
         * @param other
         * @return
         */
        bool operator <(const AbstractModelNamespace::AbstractEvent &other) {
            return completionTime < other.completionTime;
        }

        /**
         * Defines what it means for this Event to be greater than another.
         * @param other
         * @return
         */
        bool operator >(const AbstractModelNamespace::AbstractEvent &other) {
            return completionTime > other.completionTime;
        }

    private:
        Titan::TitanTime completionTime;
        AbstractModelNamespace::AbstractModel& model;
    }
}

#endif /* EVENT_H */
