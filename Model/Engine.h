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
#include "Event.h"
#include "Result.h"
#include "ThingFactory.h"

typedef std::string String;
namespace Model {
    struct Sorter {
        bool operator()(Event* m1, Event* m2) {
            return (*m1) > (*m2);
        }
    };
    class Engine {
    public:
        
        Engine(int width, int height, String& roverFile, String& thingsLibrary, String& errorLog, String& messageLog, String& configFile = "", String& mapFile = "");
        
        virtual ~Engine();
        ResultType next();
        Tile * getTileInfo(int XoffSet, int YoffSet);
        void EndGame();
        bool AddEvent(Event event);
        Rover * GetRover(int player);
    private:
        ThingFactory Factory;
        int Width, Height;
        Tile** Map;
        Rover player1;
        Logging::Logger Logs;

        std::priority_queue< Event* , std::vector<Event* >, Sorter > EventQueue;
    };
}

#endif	/* ENGINE_H */

