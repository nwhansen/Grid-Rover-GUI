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
#include "Logger.h"
#include <pthread.h>
#include "Communication.h"

namespace AbstractModelNameSpace {

    /**
     * An interface with the rover. Different None Abstract Rover Interfaces should only modify the Send Formatted Message.
     * 
     */
    class AbstractRoverInterface {
    public:
        virtual ~AbstractRoverInterface();
        /**
         * Constructs and forks the child process (rover-control program) all messages are blocking.
         * @param roverName The Rover Filename.
         */
        AbstractRoverInterface(std::string& roverfilename);
        std::string getRoverCommand();
        /**
         * Send a message to the rover. Must be properly formated
         * @param roverCommand The command to send
         * @return The Result of the message.
         */
        bool SendRoverCommand( const std::string& roverCommand);
        /**
         * Closes and terminates the rover.
         */
        void CloseConnection();
        
        virtual bool SendFormattedMessage(Communication& toSend);
        
        virtual Communication RecieveFormattedMessage();
    protected: 
#define EXIT_ROVER "GAME OVER"
        Logging::Logger* log;
        bool running;
        int pipes[2];
        pid_t pid;
    };
    
    
}


#endif	/* ABSTRACTROVERINTERFACE_H */

