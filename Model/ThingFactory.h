/* 
 * File:   ThingFactory.h
 * Author: Cody Foltz
 *
 * Created on April 5, 2012, 12:56 PM
 */

#ifndef THINGFACTORY_H
#define	THINGFACTORY_H

#include <stdlib.h>
#include <vector>
#include <string>
#include <cstdlib>

#include "Thing.h"
#include "pugixml.hpp"

using namespace std;
using namespace Model;

namespace Model{
    
    class ThingFactory{
        
    private:
        vector<Thing> objectList;
        string objectFile;
        bool fileSet;
        
        bool ReadFromFile(vector<string> rawThings);
        void CreateThingFromVector(vector<string> rawThings);
        Thing ParseRawThingData(string rawThingData);
    
    public :
        
        ThingFactory();
        ThingFactory(string filename);
        
        ///Populates the Factory with every Thing that has a possibility of being 
        ///in the game world using the provided filename.
        void GenerateThings(string filename);
        
        ///Populates the Factory with every Thing that has a possibility of being
        ///in the game world from the file gave in the constructor.
        void GenerateThings();
        
        //Methods to obtain thing objects.
        Thing GetThingAt(int index);
        Thing GetThingWithID(int id);
        
        //Obtains a random Thing object.  All Thing object currently have equal chances
        //of being returned. If this is called enough times, it is possible to have every
        ///Thing return at some point.
        Thing GetRandomThing();
        
    };

}

#endif	/* THINGFACTORY_H */
