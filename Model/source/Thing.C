#include "Thing.h"

using namespace ThingNameSpace;

Thing::Thing()
{
    
}
Thing::Thing(int mass, int density, int collectPointValue, int discoverPointValue) 
        : AbstractThing(mass, density, collectPointValue, discoverPointValue){
    
}

// Method will return an integer based on the results of the tweak.
// 0 = no change;
// 1 = this became a new thing;
// 2 = this created a thing;  Call method GetChild() to obtain the child;
// 3 = disaster was created. ie. Rock hit rover, thing exploded in rover's "face";
virtual int Thing::Tweak(){
    
    return 0;
}