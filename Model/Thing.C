#include "Thing.h"

using namespace Model;

Thing::Thing()
{
    
}
Thing::Thing(string name, uint id, uint collectPointValue, uint discoverPointValue) 
{
    this->name = name;
    this->ID = id;
    this->collectPointValue = collectPointValue;
    this->discoverPointValue = discoverPointValue;
}

// Method will return an integer based on the results of the tweak.
// 0 = no change;
// 1 = this became a new thing;
// 2 = this created a thing;  Call method GetChild() to obtain the child;
// 3 = disaster was created. ie. Rock hit rover, thing exploded in rover's "face";
//int Thing::Tweak(){
//    
//    return 0;
//}
