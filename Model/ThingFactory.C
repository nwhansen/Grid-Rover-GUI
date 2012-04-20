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


bool ThingFactory::ReadFromFile(vector<string> rawThings){
    
        string data;
	ifstream infile;
	infile.open (objectFile.c_str());
        while(!infile.eof) 
        {
	        getline(infile,data); 
                rawThings.push_back(data);
        }
	infile.close();
}
void ThingFactory::CreateThingFromVector(vector<string> rawThings){
    
    for(uint i = 0; i < rawThings.size(); i++ ){
        
        objectList[i] = ParseRawThingData(rawThings[i]);        
    }
    
}

Thing ThingFactory::ParseRawThingData(string rawThingData){
    
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
    id = rawThingData.substr(startIndex, endIndex-startIndex+1);
    
    startIndex = rawThingData.find("volume=");
    endIndex = rawThingData.find("", startIndex);
    volume = rawThingData.substr(startIndex, endIndex- startIndex+1);
    
    startIndex = rawThingData.find("collectpoint=");
    endIndex = rawThingData.find("", startIndex);
    collectPoints = rawThingData.substr(startIndex, endIndex-startIndex+1);
    
    startIndex = rawThingData.find("discoverpoint=");
    endIndex = rawThingData.find("", startIndex);
    discoverPoints = rawThingData.substr(startIndex, endIndex-startIndex+1);
    
    rawThingData.find
}

//ThingsData.txt