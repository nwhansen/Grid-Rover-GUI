/* 
 * File:   Engine.h
 * Author: Nathan Hansen
 *
 * Created on April 17, 2012, 3:31 PM
 */

#ifndef ENGINE_H
#define	ENGINE_H
#include <string>
#include "Logger.h"
#include "Rover.h"
typedef std::string String;
class Event{
    
};
class Result{
    
};
class Tile{
    
};
namespace Model {

    class Engine {
    public:
        void LoadEngine(String& configFile, String& thingsLibrary, String& errorLog, String& messageLog, String& mapFile = "");
        Result* next();
        Tile * getTileInfo(int XoffSet, int YoffSet);
        void EndGame();
        bool AddEvent(Event event);
        Rover* GetRover(int player);
        
    private:
        Rover player1;
        Logging::Logger logs;
    };
}

#endif	/* ENGINE_H */

