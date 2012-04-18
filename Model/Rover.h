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
        unsigned int score;
        unsigned int inventoryVolume;
        unsigned int maxInventoryVolume;
        unsigned int maxCharge;
        unsigned int currentCharge;
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
        bool RemoveThingFromInventory(Thing item);
        bool IncreaseScore(int points);

        int GetXCoord();
        int GetYCoord();

        bool SetXCoords(int x, int y);

        RoverInterface GetRoverInterface(){return interface;};

    };

}


#endif	/* ROVER_H */

