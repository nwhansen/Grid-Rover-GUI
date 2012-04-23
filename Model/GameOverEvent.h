/*
 * File:   GameOverEvent.h
 * Author: Lucas Adam M. Paul
 *
 * Created on 2012/04/18 19:24:07
 */

#ifndef GAMEOVEREVENT_H
#define	GAMEOVEREVENT_H

#include "Event.h"
#include "TitanTime.h"
#include "Result.h"

namespace Model {

    class Engine;

    /**
     * Represents the end of the game.
     */
    class GameOverEvent : public Event {
    public:
        /**
         * Create a new event with given completion time.
         */
        GameOverEvent(Engine* m, Titan::TitanTime time) : Event(m, time) {
            
        }

        ResultType fire() {
            engine->EndGame();
            return GameOver;
        }

    private:
    };
}

#endif /* GAMEOVEREVENT_H */
