/* 
 * File:   Rover.h
 * Author: Cody Foltz
 *
 * Created on April 5, 2012, 1:04 PM
 */

#ifndef ROVER_H
#define	ROVER_H

#include "Thing.h"
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
    public:
        Rover(int mass, int density, int collectPointValue,
                int discoverPointValue) : Thing(mass, density, collectPointValue, discoverPointValue) {
            
        }
        bool AddThingToInventory(Thing* item);
        bool RemoveThingFromInventory(int ID);
        bool RemoveThingFromInventory(Thing* item);
        bool IncreaseScore(int points);

        int GetXCoord();
        int GetYCoord();

        void SetXCoords(int x, int y);

        

    };

}


#endif	/* ROVER_H */

