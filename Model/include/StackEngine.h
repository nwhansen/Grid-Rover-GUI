/* 
 * File:   StackEngine.h
 * Author: Nathan Hansen
 *
 * Created on April 14, 2012, 11:34 AM
 */

#ifndef STACKENGINE_H
#define	STACKENGINE_H
#include "AbstractModel.h"
//#include "AbstractTile.h"
namespace StackModel {

    class StackEngine : AbstractModelNameSpace::AbstractEngine {
    public:
        StackEngine();
        virtual ~StackEngine();
        StackEngine(const StackEngine& orig);
        virtual void LoadEngine(String& configFile, String& thingsLibrary,String& errorLog, String& messageLog, String& mapFile = "");
        virtual AbstractModelNameSpace::AbstractEvent* next();
        virtual AbstractModelNameSpace::AbstractTile * getTileInfo(int XoffSet, int YoffSet);
        virtual void EndGame();
        virtual bool AddEvent(AbstractModelNameSpace::AbstractEvent* event);
    private:
        //Map object 
        AbstractModelNameSpace::AbstractTile** Map;
    };
}
#endif	/* STACKENGINE_H */

