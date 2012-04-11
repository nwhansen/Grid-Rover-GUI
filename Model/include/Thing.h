/* 
 * File:   Thing.h
 * Author: Cody Foltz
 *
 * Created on April 5, 2012, 12:57 PM
 */

#ifndef THING_H
#define	THING_H

#include "AbstractThing.h"

using namespace AbstractThingNameSpace;

namespace ThingNameSpace{
    
    class Thing : AbstractThing{
        
    private:
        
        
    public :
        Thing();
        Thing(int mass, int density, int collectPointValue, int discoverPointValue);

        // Method will return an integer based on the results of the tweak.
        // 0 = no change;
        // 1 = this became a new thing;
        // 2 = this created a thing;  Call method GetChild() to obtain the child;
        // 3 = disaster was created. ie. Rock hit rover, thing exploded in rover's "face";
        virtual int Tweak();
    };
}

#endif	/* THING_H */

