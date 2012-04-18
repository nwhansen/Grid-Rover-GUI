/*
 * File:   LookEvent.C
 * Author: Lucas Adam M. Paul
 *
 * Created on 2012/04/17 20:08:19
 */

#include "Event.h"
#include "Engine.h"
#include "Tile.h"
#include "TitanTime.h"
#include "Rover.h"
#include "RoverInterface.h"
#include "Result.h"

namespace Model {

    ResultType LookEvent::fire() {
        Titan::TitanTime delay(0, 0, 1);
        engine->AddEvent(GetCommandEvent(m, time + delay));
        int x = rover->GetXCoord();
        int y = rover->GetYCoord();
        Tile* roverTile = engine->getTileInfo(x, y);
        RoverInterface* ri = rover->GetRoverInterface();
        for(TileIterator i = roverTile->begin(); i != roverTile->end(); ++i) {
            ri->SendRoverCommand("Thing: " + i->GetID() + "\n");
        }
        return Look;
    }
}