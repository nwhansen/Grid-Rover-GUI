/*
 * File:   MoveEvent.c
 * Author: Lucas Adam M. Paul
 *
 * Created on 2012/04/14 18:34:28
 */

#include "Event.h"
#include "Tile.h"
#include "MoveEvent.h"
#include "TitanTime.h"
#include "Rover.h"

namespace Model {

    MoveEvent::MoveEvent(void* m,
              Titan::TitanTime time,
              GameOver_t gameover,
              GetTile_t gettile,
              InsertEvent_t insertevent,
              Rover& rover,
              char direction) : Event(time, gameover, gettile, insertevent),
                                rover(rover) {
        newx = rover.GetXCoord();
        newy = rover.GetYCoord();
        origin = (*getTile)(model, newx, newy);
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
        destination = (*getTile)(model, newx, newy);
    }

    bool MoveEvent::fire() {
        if (!origin.contains(&rover)) return false;
        origin->deleteItem(&rover);
        destination->addItem(&rover);
        rover.SetCoords(newx, newy);
        return true;
    }

}
