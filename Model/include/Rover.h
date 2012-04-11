/* 
 * File:   Rover.h
 * Author: Cody Foltz
 *
 * Created on April 5, 2012, 1:04 PM
 */

#ifndef ROVER_H
#define	ROVER_H

#include "AbstractThing.h"
#include <vector>

using namespace std;
using namespace AbstractThingNameSpace;

namespace ThingNameSpace{
    
    class Rover{
        
    private:
        
        vector<AbstractThing> inventory;
        unsigned int score;
        unsigned int inventoryVolume;
        unsigned int maxInventoryVolume;
        unsigned int maxCharge;
        unsigned int currentCharge;
        
    public:
        
        bool AddThingToInventory(AbstractThing item);
        bool RemoveThingFromInventory(int ID);
        bool IncreaseScore(int points);
        
    };

}


#endif	/* ROVER_H */

