/* 
 * File:   RoverCommunication.h
 * Author: Nathan Hansen
 *
 * Created on April 14, 2012, 10:23 AM
 */

#ifndef ROVERCOMMUNICATION_H
#define	ROVERCOMMUNICATION_H
#include "AbstractRoverInterface.h"
#include <string>
#include <sstream>
class RoverCommunication : AbstractModelNameSpace::AbstractRoverInterface {
public:
    RoverCommunication(std::string& filename) : AbstractRoverInterface(filename) {
        
    }
    virtual bool SendFormattedMessage(AbstractModelNameSpace::Communication& toSend);

    virtual AbstractModelNameSpace::Communication RecieveFormattedMessage();
private:
    std::stringstream remaining;
};

#endif	/* ROVERCOMMUNICATION_H */

