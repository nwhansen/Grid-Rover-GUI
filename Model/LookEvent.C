/*
 * File:   LookEvent.C
 * Author: Lucas Adam M. Paul
 *
 * Created on 2012/04/17 20:08:19
 */

#include "LookEvent.h"
#include "Event.h"
#include "Engine.h"
#include "Tile.h"
#include "GetCommandEvent.h"
#include "TitanTime.h"
#include "Rover.h"
#include "RoverInterface.h"
#include "Result.h"

using namespace Model;

ResultType LookEvent::fire() {
    Titan::TitanTime delay(0, 0, 1);
    engine->AddEvent(new GetCommandEvent(m, completionTime.plus(delay)));
    int x = rover->GetXCoord();
    int y = rover->GetYCoord();
    Tile* roverTile = engine->getTileInfo(x, y);
    RoverInterface* ri = rover->GetRoverInterface();
    for (TileIterator i = roverTile->begin(); i != roverTile->end(); ++i) {
        ri->SendRoverCommand("Thing: " + i->GetID() + "\n");
    }
    return Look;
}

