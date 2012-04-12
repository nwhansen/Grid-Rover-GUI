#include "Rover.h"

using namespace ThingNameSpace;

//Checks to see if the rover is in the tile pointA.
//If the rover is in pointA, the rover will be moved to pointB.  Also will check the inverse incase
//the tiles are backwards.
//If the rover is in neither tile, function will return false;
bool Rover::Travel(AbstractTile *pointA, AbstractTile *pointB){
    
    //TODO: Check to see if Rover is actually in pointA.
                //If rover is not in pointA, check pointB incase they called it backwards.
                //Still no rover. Return false;
    
    //TODO: Move the rover from pointA to pointB
        //If successful, return true; Otherwise Return false;
    pointA->getTile();
    pointB->getTile();
    
    return false;
}


bool Rover::AddThingToInventory(AbstractThing item){
    
    if(item.GetVolume() + inventoryVolume <= maxInventoryVolume){
        inventory.push_back(item);
        return true;
    } else {
        return false;
    }
}
bool Rover::RemoveThingFromInventory(int ID){
    
}
bool Rover::IncreaseScore(int points){
    score += points;
}

bool Rover::RemoveThingFromInventory(AbstractThing item){
    
}


