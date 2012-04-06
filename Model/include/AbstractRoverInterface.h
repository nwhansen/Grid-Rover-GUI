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
#include <sys/resource.h>
#include <sys/types.h>
#include <stdio.h>
namespace AbstractModelNameSpace {

    /**
     * An interface with the rover. This provides a full implementation, as the types of rover is not 
     * important to this class. No inheritance should be needed.
     */
    class AbstractRoverInterface {
    public:
        virtual ~AbstractRoverInterface();
        AbstractRoverInterface(std::string& roverName);
        std::string getRoverCommand();
        bool SendRoverCommand(std::string& roverCommand);
        /**
         * Closes and terminates the rover.
         */
        void CloseConnection();
        
    private:
#define EXIT_ROVER "GAME OVER"
        bool running;
        int pipes[2];
        pid_t pid;
    };
    
    
}


#endif	/* ABSTRACTROVERINTERFACE_H */

