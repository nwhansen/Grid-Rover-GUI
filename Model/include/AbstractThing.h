/* 
 * File:   AbstractThing.h
 * Author: Cody Foltz
 *
 * Created on April 5, 2012, 12:55 PM
 */

#ifndef ABSTRACTTHING_H
#define	ABSTRACTTHING_H

#include <string>
#include <vector>

using namespace std;

namespace AbstractThingNameSpace{

    class AbstractThing{

    protected:
        
        string name;
        int weight;
        int mass;
        int density;
        int volume;
        int collectPointValue;
        int discoverPointValue;
        string discription;
        
        //Set Methods
        SetWeight(int weight){this->weight = weight;};
        SetMass(int mass){this->mass = mass;};
        SetDensity(int density){this->density = density;};
        SetCollectPointValue(int collectPointValue){this->collectPointValue =collectPointValue;};
        SetDiscoverPointValue(int discoverPointValue){this->discoverPointValue = discoverPointValue;};
        SetVolume(int volume){this->volume = volume;};
        SetName(string name){this->name = name;};
        
    public:
        //Get Methods
        int GetWeight(){return weight;};
        int GetMass(){return mass;};
        int GetDensity(){return density;};
        int GetCollectPointValue(){return collectPointValue;};
        int GetDiscoverPointValue(){return discoverPointValue;};
        string GetThingDescription();
        string GetName(){return name;};

        //Constructors
        AbstractThing();
        AbstractThing(int mass, int density, int collectPointValue, int discoverPointValue);

        // Method will return an integer based on the results of the tweek.
        // 0 = no change;
        // 1 = this became a new thing;
        // 2 = this created a thing;  Call method GetChild() to obtain the child;
        // 3 = disaster was created. ie. Rock hit rover, thing exploded in rover's "face";
        virtual int Tweek() = 0;
    };

}
#endif	/* ABSTRACTTHING_H */
