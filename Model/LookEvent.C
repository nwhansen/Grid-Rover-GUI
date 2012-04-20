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
#include <sstream>

using namespace Model;

ResultType LookEvent::fire() {
    Titan::TitanTime delay(0, 0, 1);
    engine->AddEvent(new GetCommandEvent(engine, completionTime.plus(delay)));
    int x = rover->GetXCoord();
    int y = rover->GetYCoord();
    Tile* roverTile = engine->getTileInfo(x, y);
    RoverInterface* ri = rover->GetRoverInterface();
    for (TileIterator i = roverTile->begin(); i != roverTile->end(); ++i) {
    	Communication c;
    	c.command = "lookresult";
    	c.arguments.push_back("thing");
    	std::ostringstream oss;
		oss << (*i).GetID();
    	c.arguments.push_back(oss.str());
    	ri->SendFormattedMessage(c);
        //ri->SendRoverCommand(std::string("Thing: ") + (*i).GetID() + std::string("\n"));
    }
    return Look;
}

