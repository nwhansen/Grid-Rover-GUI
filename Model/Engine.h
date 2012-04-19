/* 
 * File:   Engine.h
 * Author: Nathan Hansen
 *
 * Created on April 17, 2012, 3:31 PM
 */

#ifndef ENGINE_H
#define	ENGINE_H
#include <string>
#include <queue>

#include "Logger.h"
#include "Rover.h"
#include "Tile.h"
#include "TitanTime.h"
#include "Event.h"
#include "Result.h"
#include "ThingFactory.h"

typedef std::string String;

namespace Model {

    struct Sorter {

        bool operator()(Event* m1, Event * m2) {
            return (*m1) > (*m2);
        }
    };

    class Engine {
    public:
        static String empty;
        Engine(int width, int height, String& roverFile, String& thingsLibrary, String& errorLog, String& messageLog, String& configFile = empty, String& mapFile = empty);
        /**
         * Clean up out mess.
         */
        virtual ~Engine();
        /**
         * proceeds to preform the next event
         * @return What event occurred.
         */
        ResultType next();
        Tile * getTileInfo(int XoffSet, int YoffSet);
        /**
         * Unconditioanlly ends the game.
         */
        void EndGame();
        /**
         * Adds an event to the engine, if the event happens prior to current time it will return false and delete the event.
         * @param event the event to add
         * @return The result of the event addition.
         */
        bool AddEvent(Event* event);
        /**
         * Returns a pointer to the rover object
         * @param player The player number, this could be anything but as of now it must be 0
         * @return the player you requested
         */
        Rover * GetRover(int player);
        /**
         * Are we in a game?
         * @return 
         */
        bool gameInProgress() {
            return inProgress;
        };

        Titan::TitanTime getTime() {
            return currentTime;
        };
    private:
        bool inProgress;
        Titan::TitanTime currentTime;
        ThingFactory Factory;
        int Width, Height;
        Tile** Map;
        Rover player1;
        Logging::Logger Logs;

        std::priority_queue< Event*, std::vector<Event* >, Sorter > EventQueue;
    };
}

#endif	/* ENGINE_H */

