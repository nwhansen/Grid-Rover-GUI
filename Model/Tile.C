/* 
 * File:   Tile.C
 * Author: Nathan Hansen
 * 
 * Created on April 17, 2012, 3:52 PM
 */

#include "Tile.h"

using namespace Model;

Tile::Tile() : type(Mountain) {
    //Can't do nothing since dealing with malloc is evil.
    //default to mountain. just to be safe
}

void Tile::setProperties(TileType t) {
    type = t;
}

Tile::~Tile() {
}

void Tile::deleteItem(Thing* toDelete) {
    for (std::vector<Thing* >::iterator i = items.begin(); i < items.end(); i++) {
        if (*i == toDelete) {
            items.erase(i);
        }
    }
}

bool Tile::contains(Thing* toCompare) {
    for (std::vector<Thing* >::iterator i = items.begin(); i < items.end(); i++) {
        if (*i == toCompare) {
            return true;
        }
    }
    return false;
}

void Tile::addItem(Thing* toAdd) {
    items.push_back(toAdd);
}

TileIterator Tile::begin() {
    return TileIterator(&items, 0);
}

TileIterator Tile::end() {
    return TileIterator(&items, items.size()-1);
}

TileIterator::TileIterator(std::vector<Thing* > * myCollection, uint start) {
    items = myCollection;
    pos = start;
}

Thing& TileIterator::operator *() {
    Thing& badProgramming = *(items->at(pos));
    return badProgramming;
}

void TileIterator::operator ++() {
    if(pos+1 == items->size()) return;
    pos++;
}

bool TileIterator::operator !=(const TileIterator& other) {
    if(other.items != this->items) {
        //Well aint this a problem
        return false; //Technically its a problem....
        //As the loop will never terminate but i guess this object can never equal another if
        //There collection is not the same
    }
    return other.pos != this->pos;
}

