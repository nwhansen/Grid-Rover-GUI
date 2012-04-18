/* 
 * File:   Rover.h
 * Author: Cody Foltz
 *
 * Created on April 5, 2012, 1:04 PM
 */

#ifndef ROVER_H
#define	ROVER_H

#include "Thing.h"
#include "RoverInterface.h"
#include <vector>

using namespace std;
using namespace Model;

namespace Model {

    class Rover : public Thing {
    private:

        vector<Thing> inventory;
        int score;
        int inventoryVolume;
        int maxInventoryVolume;
        int maxCharge;
        int currentCharge;
        RoverInterface interface;
        int xCoord;
        int yCoord;
        

    public:
        Rover(int mass, int density, int collectPointValue,
                int discoverPointValue, RoverInterface roverInterface) : Thing(int mass, int density, int collectPointValue, int discoverPointValue) {
            interface = roverInterface;
        }
        
        ///Adds a Thing into the rover's inventory.
        ///Returns true if the item is successfully added to the inventory.
        ///Returns false if the item is unable to be added to the inventory.
        ///Reason for the failure would be due to the item's volume being greater than 
        ///the amount of space available.
        bool AddThingToInventory(Thing item);
        
        ///Removes the item that has the id of the said ID.
        ///Returns true if the Rover contains said item and is now removed.
        ///Returns false if the Rover does NOT contain said item initially. 
        bool RemoveThingFromInventory(int ID);
        
        ///The same as using Remove with ID as the parameter.
        bool RemoveThingFromInventory(Thing item);
        
        ///Change the score by a specified amount.
        ///ie. if the score is 5 and points is 2 then the score would now be 7.
        /// if the score is 7 and points is -6 then the score would now be 1.
        bool IncreaseScore(int points);

        ///Gets the X Coordinate where the rover resides within the map.
        int GetXCoord();
        
        ///Gets the Y Coordinate where the rover resides within the map.
        int GetYCoord();

        ///Sets the X and Y Coordinates where the rover resides within the map.
        bool SetXCoords(int x, int y);

        ///Returns the RoverInterface object for this rover.
        RoverInterface GetRoverInterface(){return interface;};

    };

}


#endif	/* ROVER_H */

