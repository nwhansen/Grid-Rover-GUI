/*
 * File:   MoveEvent.c
 * Author: Lucas Adam M. Paul
 *
 * Created on 2012/04/14 18:34:28
 */

#include "Event.h"
#include "Engine.h"
#include "Tile.h"
#include "MoveEvent.h"
#include "TitanTime.h"
#include "Rover.h"
#include "RoverInterface.h"

namespace Model {

    MoveEvent::MoveEvent(Engine* m,
              Titan::TitanTime time,
              Rover& rover,
              char direction) : Event(m, time),
                                rover(rover) {
        newx = rover.GetXCoord();
        newy = rover.GetYCoord();
        origin = engine->getTileInfo(newx, newy);
        switch (direction){
            case 'n':
                newy--;
                break;
            case 's':
                newy++;
                break;
            case 'e':
                newx++;
                break;
            case 'w':
                newx--;
                break;
        }
        destination = engine->getTileInfo(newx, newy);
    }

    bool MoveEvent::fire() {
        if (!origin.contains(&rover)) return false;
        origin->deleteItem(&rover);
        destination->addItem(&rover);
        rover.SetCoords(newx, newy);
        return true;
    }

}
