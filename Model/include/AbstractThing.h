/* 
 * File:   AbstractThing.h
 * Author: Cody Foltz
 *
 * Created on April 5, 2012, 12:55 PM
 */

#ifndef ABSTRACTTHING_H
#define	ABSTRACTTHING_H

namespace AbstractThingNameSpace{

    class AbstractThing{

    protected:
        int weight;
        int mass;
        int density;
        int collectPointValue;
        int discoverPointValue;

    public:
        GetWeight();
        GetMass();
        GetDensity();
        GetCollectPointValue();
        GetDiscoverPointValue();

    };

}
#endif	/* ABSTRACTTHING_H */

