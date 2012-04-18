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

using namespace std;
using namespace Model;

namespace Model{
    
    class ThingFactory{
        
    private:
        vector<AbstractThing> objectList;
        string objectXMLDataFile;
    
    public :
        
        ThingFactory();
        ThingFactory(string filename);
        
        GenerateThings(string filename);
        
        //Methods to obtain abstract thing objects.
        AbstractThing GetThingAt(int index);
        AbstractThing GetThingWithID(int id);
        AbstractThing GetRandomThing();
        
    };

}

#endif	/* THINGFACTORY_H */
