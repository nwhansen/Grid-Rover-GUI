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

    enum TileType {
        Mountain, Plain, Rugged, Lake
    };

    class TileIterator {
    public:
        TileIterator(std::vector<Thing* > * myCollection, uint start);
        Thing* operator *();
        void operator ++();
        bool operator !=(const TileIterator& other);


    private:
        std::vector<Thing* >* items;
        uint pos;
    };

    class Tile {
    public:
        Tile() : type(Mountain) {}
        void setProperties(TileType);
        virtual ~Tile();
        
        TileType getTileType() { return type; }
        /**
         * Delete an item in the collection. 
         * @param toDelete
         */
        void deleteItem(Thing* toDelete);
        /**
         * Check if the tile contains an item
         * @param toCompare
         */
        bool contains(Thing* toCompare);
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

        static TileType to_tile_enum(int i) {
            switch (i) {
                case 0: return Mountain;
                case 1: return Plain;
                case 2: return Rugged;
                case 3: return Lake;
            }
        }
    private:
        TileType type;
        std::vector<Thing*> items;
        TileIterator* itr;
    };

}

#endif	/* TILE_H */

