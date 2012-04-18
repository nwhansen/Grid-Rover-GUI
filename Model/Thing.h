/* 
 * File:   AbstractThing.h
 * Author: Cody Foltz
 *
 * Created on April 5, 2012, 12:55 PM
 */

#ifndef THING_H
#define	THING_H

#include <string>
#include <vector>

using namespace std;

namespace Model{

    class Thing{

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
        void SetWeight(int weight){this->weight = weight;};
        void SetMass(int mass){this->mass = mass;};
        void SetDensity(int density){this->density = density;};
        void SetCollectPointValue(int collectPointValue){this->collectPointValue =collectPointValue;};
        void SetDiscoverPointValue(int discoverPointValue){this->discoverPointValue = discoverPointValue;};
        void SetVolume(int volume){this->volume = volume;};
        void SetName(string name){this->name = name;};
        
    public:
        //Get Methods
        int GetWeight(){return weight;};
        int GetMass(){return mass;};
        int GetDensity(){return density;};
        int GetVolume(){return volume;};
        int GetCollectPointValue(){return collectPointValue;};
        int GetDiscoverPointValue(){return discoverPointValue;};
        string GetThingDiscription(){return discription;};
        string GetName(){return name;};

        //Constructors
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
