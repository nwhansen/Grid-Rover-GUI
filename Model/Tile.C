/* 
 * File:   Tile.C
 * Author: Nathan Hansen
 * 
 * Created on April 17, 2012, 3:52 PM
 */

#include "Tile.h"

using namespace Model;

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
    return TileIterator(items.begin());
}

TileIterator Tile::end() {
    return TileIterator(items.end());
}

TileIterator::TileIterator(std::vector<Thing* >::iterator i) : pos(i) {
}

Thing* TileIterator::operator *() {
    return *pos;
}

void TileIterator::operator ++() {
    ++pos;
}

bool TileIterator::operator !=(const TileIterator& other) {
    return other.pos != this->pos;
}

