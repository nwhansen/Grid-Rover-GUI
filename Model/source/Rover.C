#include "Rover.h"

using namespace Model;

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


