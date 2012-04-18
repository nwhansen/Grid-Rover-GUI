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
#include "Result.h"

namespace Model {

    MoveEvent::MoveEvent(Engine* m,
              Titan::TitanTime time,
              Rover* r,
              char direction) : Event(m, time),
                                rover(r) {
        newx = rover->GetXCoord();
        newy = rover->GetYCoord();
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

    ResultType MoveEvent::fire() {
        if (!origin.contains(rover)) return Fail;
        origin->deleteItem(rover);
        destination->addItem(rover);
        rover.SetCoords(newx, newy);
        return Move;
    }

}