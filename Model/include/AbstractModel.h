/* 
 * File:   AbstractModel.h
 * Author: Nathan Hansen
 *
 * Created on March 26, 2012, 9:32 PM
 */

#ifndef ABSTRACTMODEL_H
#define	ABSTRACTMODEL_H

//project includes
#include "AbstractConsequence.h"
#include "AbstractTile.h"

namespace AbstractModelNameSpace {
    /**
     * A non threaded version of a map. 
     */
    class AbstractModel {
    public:
        /**
         * The Consequence of the call will retrieve various "consequences" 
         *      A move from the user program.
         *      One consequence from the user programs last move.
         *      A random occurrence such a flying space debris hitting the rover.
         *      The contents of the tile or tiles that the rover can identify examine.
         *      The Reason Why a rover could not preform the last move.
         * @return The Next Step in the simulation dubbed "consequence"
         */
        virtual AbstractConsequence* sufferConsequence() = 0;
        /**
         * Gets the basic tile information for the specified tile offset from the Top Left Corner of the map.
         * Contains only minimal information regarding the tile. No details about tile contents.
         * @param XoffSet
         * @param YoffSet
         * @return 
         */
        virtual AbstractTile * getTileInfo(int XoffSet, int YoffSet) = 0;
    private:
        
    };
}
#endif	/* ABSTRACTMODEL_H */

