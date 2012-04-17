/* 
 * File:   AbstractTile.h
 * Author: Nathan Hansen
 *
 * Created on March 28, 2012, 6:02 PM
 */

#ifndef ABSTRACTTILE_H
#define	ABSTRACTTILE_H
#include <vector>
#include "Thing.h"
namespace AbstractModelNameSpace {
    class AbstractTileIterator;
    class AbstractTile {
    public:
        /**
         * Delete an item in the collection. 
         * @param toDelete
         */
        virtual void deleteItem(AbstractThingNameSpace::AbstractThing *toDelete) = 0;
        /**
         * Check if the tile contains an item
         * @param toCompare
         */
        virtual void contains(AbstractThingNameSpace::AbstractThing *toCompare) =0;
        /**
         * Add an item to the collection.
         * @param toAdd
         */
        virtual void addItem(AbstractThingNameSpace::AbstractThing* toAdd) =0;
        /**
         * A method to begin iteration over a collection of the Abstract Tile
         * @return 
         */ 
        virtual AbstractTileIterator begin() = 0;
        /**
         * An iterator to define the end of a collection
         * @return 
         */
        virtual AbstractTileIterator end() = 0;
    protected:
        
    };
    class AbstractTileIterator {
        //THESE MUST BE IMPLIMENTED PROIR TO USING THE ABSTRACTILE
    public:
        virtual void operator ++() = 0;
        virtual bool operator ==(const AbstractTileIterator& other) = 0;
    };
}
#endif	/* ABSTRACTTILE_H */

