/* 
 * File:   AbstractModel.h
 * Author: Nathan Hansen
 *
 * Created on March 26, 2012, 9:32 PM
 */

#ifndef ABSTRACTMODEL_H
#define	ABSTRACTMODEL_H
#include "TitanTime.h"
#include "AbstractRoverInterface.h"
//project includes

class AbstractEvent;

namespace AbstractModelNameSpace {

    /**
     * A non threaded version of a map. 
     */
    class AbstractEngine {
    public:

        /**
         * The Consequence of the call will retrieve various "consequences" 
         *      A move from the user program.
         *      One consequence from the user programs last move.
         *      A random occurrence such a flying space debris hitting the rover.
         *      The contents of the tile or tiles that the rover can identify examine.
         *      The Reason Why a rover could not preform the last move.
         * @return The Next Step in the simulation dubbed "consequence"
         */
        virtual AbstractEvent* next() = 0;

        /**
         * Gets the basic tile information for the specified tile offset from the Top Left Corner of the map.
         * Contains only minimal information regarding the tile. No details about tile contents.
         * @param XoffSet
         * @param YoffSet
         * @return 
         */
        virtual AbstractTile * getTileInfo(int XoffSet, int YoffSet) = 0;

        /**
         * Returns the current time in titan time.
         * @return The time
         */
        Titan::TitanTime getTime() {
            return CurrentTime;
        }
        
        /**
         * End this GridRover game. The next call to Next will run the end game tasks.
         */
        virtual void EndGame() = 0;
        
        /**
         * Attempts to add an event to the event queue. If the event occured prior to the current time then this will fail.
         * @param event The event to add
         * @return The result of adding it.
         */
        virtual bool AddEvent(AbstractEvent event) = 0;

        /**
         * A helper method so that the abstractEvent can get tiles without an explicit function, and can instead use a function pointer.
         * @param model The Model that the event propegated from.
         * @param XoffSet The X-offSet that is of interest from the top left corner
         * @param YoffSet The Y-offSet that is of interest from the top left corner
         * @return The Abstract Tile of interest.
         * @thows Cast Exception if the void* is not of type AbstractModel or its dependents.
         */
        static AbstractTile * EventAddHelper(void* model, int XoffSet, int YoffSet) {
            //Attempt to cast
            return ((AbstractEngine)model)->getTileInfo(XoffSet, YoffSet);
        }
        
        /**
         * Ends the parameters game For good.
         * @param model The game engine to end.
         * @throws Cast Exception if the model is not of type AbstractModel or its derivatives
         */
        static void EventEndHelper(void* model) {
            ((AbstractEngine*)model)->EndGame();
        }
    private:
        
        /**
         * The current time in the simulation, Event cannot occur before this time.
         */
        Titan::TitanTime CurrentTime;

        /**
         * The Communication with the rover. All communication must be contained and used by this object.
         */
        AbstractRoverInterface CommProtacal;
    };
}

#endif	/* ABSTRACTMODEL_H */

