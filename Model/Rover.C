#include "Rover.h"

using namespace Model;

bool Rover::AddThingToInventory(Thing item){
    
    if(item.GetVolume() + inventoryVolume <= maxInventoryVolume){
        inventory.push_back(item);
        return true;
    } else {
        return false;
    }
}
bool Rover::RemoveThingFromInventory(int ID){
 
    int count = inventory.size();
    for(std::vector<Thing >::iterator  i = inventory.begin(); i < inventory.end(); i++){
        if((*i).GetID() == ID){
            inventory.erase(i);
            return true;
        }
    }
    return false;
}


bool Rover::IncreaseScore(int points){
    score += points;
}

bool Rover::RemoveThingFromInventory(Thing item){
    RemoveThingFromInventory(item.GetID());
}

int Rover::GetScore(){
    
    return score;
}

int Rover::GetXCoord(){return xCoord;}
int Rover::GetYCoord(){return yCoord;}

bool Rover::SetXCoords(int x, int y){
    
    if(x < 0 || y < 0){
        return false;
    }
    
    xCoord = x;
    yCoord = y;
    return true;
}

int Rover::GetInventoryVolume(){ return inventoryVolume;}
int Rover::GetMaxCharge(){ return maxCharge;}
int Rover::GetCurrentCharge(){return currentCharge;}
int Rover::GetMaxInventoryVolume(){return maxInventoryVolume;}

void Rover::SetToMaxCharge(){ currentCharge = maxCharge;}
void Rover::DecreaseCharge(int amount){ currentCharge-=amount;}
void Rover::SetCharge(int charge){currentCharge = charge;}
