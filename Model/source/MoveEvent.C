/*
 * File:   MoveEvent.c
 * Author: Lucas Adam M. Paul
 *
 * Created on 2012/04/14 18:34:28
 */

#include "Event.h"
#include "AbstractTile.h"
#include "MoveEvent.h"
#include "TitanTime.h"
#include "Rover.h"

namespace EventNameSpace {

    MoveEvent::MoveEvent(Titan::TitanTime time,
              GameOver_t gameover,
              GetTile_t gettile,
              InsertEvent_t insertevent,
              ThingNameSpace::Rover& rover,
              char direction) : Event(time, gameover, gettile, insertevent),
                                rover(rover) {
        // TODO: properly initialize tile pointers!
        origin = NULL;
        destination = NULL;
    }

    bool MoveEvent::fire() {
        // TODO: Check to see if the rover can actually make this move?
        rover.travel(*origin, *destination);
    }

}
