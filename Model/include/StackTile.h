/* 
 * File:   StackTile.h
 * Author: Nathan Hansen
 *
 * Created on March 28, 2012, 5:40 PM
 */

#ifndef STACKTILE_H
#define	STACKTILE_H
#include "AbstractTile.h"

namespace StackModelNameSpace {

    class StackTile : public AbstractModelNameSpace::AbstractTile {
    public:
        StackTile();
        StackTile(const StackTile& orig);
        virtual ~StackTile();
    private:
        //A collection of items
        //Tile
    };
}
#endif	/* STACKTILE_H */

