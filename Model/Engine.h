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

    class Engine {
    public:
        virtual ~Engine();
        void LoadEngine(int width, int height,String& roverFile, String& thingsLibrary, String& errorLog, String& messageLog, String& configFile = "", String& mapFile = "");
        Result next();
        Tile * getTileInfo(int XoffSet, int YoffSet);
        void EndGame();
        bool AddEvent(Event event);
        Rover* GetRover(int player);
    private:
        ThingFactory Factory;
        int Width, Height;
        Tile** Map;
        //int player1;
        Rover player1;
        Logging::Logger Logs;
        
        std::priority_queue< Event, std::vector<Event>, std::greater<Event> > EventQueue;
    };
}

#endif	/* ENGINE_H */

