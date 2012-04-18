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

namespace Model {

    class Thing {
    protected:

        string name;
        uint weight;
        uint mass;
        uint density;
        uint ID;
        uint volume;
        uint collectPointValue;
        uint discoverPointValue;
        string discription;
        //Set Methods

        void SetWeight(uint weight) {
            this->weight = weight;
        };

        void SetMass(uint mass) {
            this->mass = mass;
        };

        void SetDensity(uint density) {
            this->density = density;
        };

        void SetCollectPointValue(uint collectPointValue) {
            this->collectPointValue = collectPointValue;
        };

        void SetDiscoverPointValue(uint discoverPointValue) {
            this->discoverPointValue = discoverPointValue;
        };

        void SetVolume(uint volume) {
            this->volume = volume;
        };

        void SetName(string name) {
            this->name = name;
        };

    public:
        //Get Methods

        uint GetWeight() {
            return weight;
        };

        uint GetMass() {
            return mass;
        };

        uint GetDensity() {
            return density;
        };

        uint GetVolume() {
            return volume;
        };

        uint GetCollectPointValue() {
            return collectPointValue;
        };

        uint GetDiscoverPointValue() {
            return discoverPointValue;
        };

        uint GetID() {
            return ID;
        };

        string GetThingDiscription() {
            return discription;
        };

        string GetName() {
            return name;
        };
        //Constructors
        Thing();
        Thing(uint id,uint mass, uint density, uint collectPointValue, uint discoverPointValue);

        // Method will return an integer based on the results of the tweak.
        // 0 = no change;
        // 1 = this became a new thing;
        // 2 = this created a thing;  Call method GetChild() to obtain the child;
        // 3 = disaster was created. ie. Rock hit rover, thing exploded in rover's "face";
        virtual int Tweak();
    };

}
#endif	/* THING_H */
