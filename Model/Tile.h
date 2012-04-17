/* 
 * File:   Tile.h
 * Author: Nathan Hansen
 *
 * Created on April 17, 2012, 3:52 PM
 */

#ifndef TILE_H
#define	TILE_H
#include <vector>
class Thing;

namespace Model {
    class TileIterator;
    class Tile {
    public:
        Tile();
        virtual ~Tile();
        /**
         * Delete an item in the collection. 
         * @param toDelete
         */
        virtual void deleteItem(Thing* toDelete);
        /**
         * Check if the tile contains an item
         * @param toCompare
         */
        virtual void contains(Thing* toCompare);
        /**
         * Add an item to the collection.
         * @param toAdd
         */
        virtual void addItem(Thing* toAdd);
        /**
         * A method to begin iteration over a collection of the Abstract Tile
         * @return 
         */ 
        virtual TileIterator begin();
        /**
         * An iterator to define the end of a collection
         * @return 
         */
        virtual TileIterator end();
        
    private:
        std::vector<Thing*> items;
        TileIterator* itr;
    };
    class TileIterator {
        //THESE MUST BE IMPLIMENTED PROIR TO USING THE ABSTRACTILE
    public:
        virtual void operator ++();
        virtual bool operator ==(const TileIterator& other);
    private:
        std::vector<Thing>* items;
    };
}

#endif	/* TILE_H */

