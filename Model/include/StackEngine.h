/* 
 * File:   StackEngine.h
 * Author: Nathan Hansen
 *
 * Created on April 14, 2012, 11:34 AM
 */

#ifndef STACKENGINE_H
#define	STACKENGINE_H
#include "AbstractModel.h"

class StackEngine : AbstractModelNameSpace::AbstractEngine {
public:
    StackEngine();
    virtual AbstractEvent* next() = 0;

    virtual AbstractTile * getTileInfo(int XoffSet, int YoffSet) = 0;

    
    virtual void EndGame() = 0;
    virtual bool AddEvent(AbstractEvent event) = 0;

private:

};

#endif	/* STACKENGINE_H */

