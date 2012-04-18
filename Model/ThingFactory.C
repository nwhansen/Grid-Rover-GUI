#include "ThingFactory.h"

using namespace Model;


ThingFactory::ThingFactory(){
}
        
ThingFactory::ThingFactory(string filename){
    
}
        
void ThingFactory::GenerateThings(string filename){
    
}
        
//Methods to obtain abstract thing objects.
Thing ThingFactory::GetThingAt(int index){
    return objectList[index];
}
Thing ThingFactory::GetThingWithID(int id){
    
    return GetThingAt(id);
}

//TODO: Look into a way to do a "weighted" random.  Such that more rocks are choosen
//      over rare things. Much like real life.
Thing ThingFactory::GetRandomThing(){
    return objectList[rand() % objectList.size()];
}
