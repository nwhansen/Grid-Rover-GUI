/* 
 * File:   Tile.h
 * Author: Nathan Hansen
 *
 * Created on April 17, 2012, 3:52 PM
 */

#ifndef TILE_H
#define	TILE_H
#include <vector>
#include "Thing.h"

namespace Model {
    
    class TileIterator {
        //THESE MUST BE IMPLIMENTED PROIR TO USING THE ABSTRACTILE
    public:
        void operator ++();
        bool operator ==(const TileIterator& other);
    private:
        std::vector<Thing>* items;
    };
    
    class Tile {
    public:
        Tile();
        virtual ~Tile();
        /**
         * Delete an item in the collection. 
         * @param toDelete
         */
        void deleteItem(Thing* toDelete);
        /**
         * Check if the tile contains an item
         * @param toCompare
         */
        void contains(Thing* toCompare);
        /**
         * Add an item to the collection.
         * @param toAdd
         */
        void addItem(Thing* toAdd);
        /**
         * A method to begin iteration over a collection of the Abstract Tile
         * @return 
         */
        TileIterator begin();
        /**
         * An iterator to define the end of a collection
         * @return 
         */
        TileIterator end();

    private:
        std::vector<Thing*> items;
        TileIterator* itr;
    };

}

#endif	/* TILE_H */

