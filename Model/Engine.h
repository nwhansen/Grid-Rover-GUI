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

        /**
         * A helper method so that the abstractEvent can get tiles without an explicit function, and can instead use a function pointer.
         * @param model The Model that the event propegated from.
         * @param XoffSet The X-offSet that is of interest from the top left corner
         * @param YoffSet The Y-offSet that is of interest from the top left corner
         * @return The Abstract Tile of interest.
         * @thows Cast Exception if the void* is not of type AbstractModel or its dependents.
         */
        static Tile * EventTileHelper(void* model, int XoffSet, int YoffSet) {
            //Attempt to cast
            return ((Engine*) model)->getTileInfo(XoffSet, YoffSet);
        }

        static void EventAddHelper(void* model, Event e) {
            ((*Engine)model)->AddEvent(e);
            return;
        }

        /**
         * Ends the parameters game For good.
         * @param model The game engine to end.
         * @throws Cast Exception if the model is not of type AbstractModel or its derivatives
         */
        static void EventEndHelper(void* model) {
            ((Engine*) model)->EndGame();
        }

    private:
        Logging::Logger logs;
    };
}

#endif	/* ENGINE_H */

