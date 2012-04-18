/* 
 * File:   StackTile.h
 * Author: Nathan Hansen
 *
 * Created on April 16, 2012, 9:32 AM
 */

#ifndef STACKTILE_H
#define	STACKTILE_H
#include "AbstractTile.h"
namespace StackModel {
    class StackIterator;

    class StackTile : AbstractModelNameSpace::AbstractTile {
    public:
        StackTile();
        virtual void deleteItem(AbstractThingNameSpace::AbstractThing *toDelete);
        virtual void contains(AbstractThingNameSpace::AbstractThing *toCompare);
        virtual void addItem(AbstractThingNameSpace::AbstractThing* toAdd);
        virtual AbstractModelNameSpace::AbstractTileIterator* begin();
        virtual AbstractModelNameSpace::AbstractTileIterator* end();

    private:
        
    };

    class StackIterator {
    public:
        virtual void operator ++();
        virtual bool operator ==(const AbstractModelNameSpace::AbstractTileIterator& other) = 0;
    private:

    };
}
#endif	/* STACKTILE_H */

