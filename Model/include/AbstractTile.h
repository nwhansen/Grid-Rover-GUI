/* 
 * File:   AbstractTile.h
 * Author: Nathan Hansen
 *
 * Created on March 28, 2012, 6:02 PM
 */

#ifndef ABSTRACTTILE_H
#define	ABSTRACTTILE_H
namespace AbstractModelNameSpace {
    class tiletype;
    class AbstractTile {
    public:
        virtual tiletype getTile() = 0;
    private:

    };
}
#endif	/* ABSTRACTTILE_H */

