#include "ThingFactory.h"

using namespace Model;


ThingFactory::ThingFactory(){
    fileSet = false;
}
        
ThingFactory::ThingFactory(string filename){
    objectFile = filename;
    fileSet = true;
}
        
void ThingFactory::GenerateThings(string filename){
    objectFile = filename;
    fileSet = true;
    GenerateThings();
}

///Populates the Factory with every Thing that has a possibility of being
///in the game world from the file gave in the constructor.
void ThingFactory::GenerateThings(){
    
    vector<string> rawThings;
    ReadFromFile( rawThings);
    CreateThingFromVector( rawThings );
    
}
        
//Methods to obtain abstract thing objects.
Thing* ThingFactory::GetThingWithName(string name){
    Thing* item = 0;
    for(int i = 0; i < objectList.size(); i++){
        item = &(objectList[i]);
        if(item->GetName() == name){
            return item;
        }
    }
    return item;
}
Thing* ThingFactory::GetThingWithID(int id){
    Thing* item = 0;
    for(int i = 0; i < objectList.size(); i++){
        item = &(objectList[i]);
        if(item->GetID() == id){
            return item;
        }
    }
    return item;
}

//TODO: Look into a way to do a "weighted" random.  Such that more rocks are choosen
//      over rare things. Much like real life.
Thing* ThingFactory::GetRandomThing(){
    
    uint size = objectList.size();
    if(size == 0){
        return 0;
    }
    return &(objectList[rand() % size]);
}


bool ThingFactory::ReadFromFile(vector<string> rawThings){
    
        string data;
//	ifstream infile;
//	infile.open (objectFile.c_str());
//      while(!infile.eof) 
//        {
//	        getline(infile,data); 
//                rawThings.push_back(data);
//        }
//	infile.close();
}
void ThingFactory::CreateThingFromVector(vector<string> rawThings){
    
    for(uint i = 0; i < rawThings.size(); i++ ){
        
        objectList[i] = ParseRawThingData(rawThings[i]);        
    }
    
}

Thing ThingFactory::ParseRawThingData(string rawThingData){
    
    string rawString;
    string name;
    uint id;
    uint volume;
    uint collectPoints;
    uint discoverPoints;
    
    int startIndex = rawThingData.find("name=");
    int endIndex = rawThingData.find("",  startIndex);
    name = rawThingData.substr( startIndex, endIndex- startIndex+1);
    
    startIndex = rawThingData.find("id=");
    endIndex = rawThingData.find("", startIndex);
    rawString = rawThingData.substr(startIndex, endIndex-startIndex+1);
    id = atoi(rawString.c_str());
    
    startIndex = rawThingData.find("volume=");
    endIndex = rawThingData.find("", startIndex);
    rawString = rawThingData.substr(startIndex, endIndex- startIndex+1);
    volume = atoi(rawString.c_str());
    
    startIndex = rawThingData.find("collectpoint=");
    endIndex = rawThingData.find("", startIndex);
    rawString = rawThingData.substr(startIndex, endIndex-startIndex+1);
    collectPoints = atoi(rawString.c_str());
    
    startIndex = rawThingData.find("discoverpoint=");
    endIndex = rawThingData.find("", startIndex);
    rawString = rawThingData.substr(startIndex, endIndex-startIndex+1);
    discoverPoints = atoi(rawString.c_str());
    
}

//ThingsData.txt