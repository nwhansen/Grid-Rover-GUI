#include "ThingFactory.h"

using namespace ThingNameSpace;


ThingFactory::ThingFactory(){
    this->objectList = new vector<AbstractThing>();
}
        
ThingFactory::ThingFactory(string filename){
    
}
        
ThingFactory::GenerateThings(string filename){
    
}
        
//Methods to obtain abstract thing objects.
AbstractThing ThingFactory::GetThingAt(int index){
    return objectList[index];
}
AbstractThing ThingFactory::GetThingWithID(int id){
    
    return GetThingAt(id);
}

//TODO: Look into a way to do a "weighted" random.  Such that more rocks are choosen
//      over rare things. Much like real life.
AbstractThing ThingFactory::GetRandomThing(){
    return objectList[rand() % objectList.size()];
}
