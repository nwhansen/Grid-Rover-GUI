/* 
 * File:   Tile.C
 * Author: Nathan Hansen
 * 
 * Created on April 17, 2012, 3:52 PM
 */

#include "Tile.h"

using namespace Model;

Tile::Tile() : type(Mountain){
    //Can't do nothing since dealing with malloc is evil.
    //default to mountain. just to be safe
}

void Tile::setProperties(TileType t){
    type = t;
}

Tile::~Tile() {
}

void Tile::deleteItem(Thing* toDelete) {
    for(std::vector<Thing* >::iterator i = items.begin(); i < items.end(); i++){
        if(*i == toDelete){
            items.erase(i);
        }
    }
}

bool Tile::contains(Thing* toCompare) {
    for(std::vector<Thing* >::iterator i = items.begin(); i < items.end(); i++){
        if(*i == toCompare){
            return true;
        }
    }
    return false;
}

void Tile::addItem(Thing* toAdd) {
    items.push_back(toAdd);
}

TileIterator Tile::begin() {
    //
}

TileIterator Tile::end() {
    //
}

void TileIterator::operator ++() {
}

bool TileIterator::operator <(const TileIterator& other) {
}

