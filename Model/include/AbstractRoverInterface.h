/* 
 * File:   AbstractRoverInterface.h
 * Author: Nathan Hansen
 *
 * Created on April 4, 2012, 10:31 AM
 */

#ifndef ABSTRACTROVERINTERFACE_H
#define	ABSTRACTROVERINTERFACE_H
#include <string>
#include <stdarg.h>
#include <stdio.h>
namespace AbstractModelNameSpace {

    class AbstractRoverInterface {
    public:
        AbstractRoverInterface(std::string& roverName);
        std::string getRoverCommand();
        void SendRoverCommand(std::string& roverCommand);
        
    private:

    };
    
    
}


#endif	/* ABSTRACTROVERINTERFACE_H */

