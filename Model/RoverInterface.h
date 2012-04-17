/* 
 * File:   AbstractRoverInterface.h
 * Author: Nathan Hansen
 *
 * Created on April 4, 2012, 10:31 AM
 */

#ifndef ROVERINTERFACE_H
#define	ROVERINTERFACE_H
#include <string>
#include <stdarg.h>
#include <pthread.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sstream>

#include "Logger.h"
#include "Communication.h"

namespace Model {

    /**
     * An interface with the rover. Different None Abstract Rover Interfaces should only modify the Send Formatted Message.
     * 
     */
    class RoverInterface {
    public:
        virtual ~RoverInterface();
        /**
         * Constructs and forks the child process (rover-control program) all messages are blocking.
         * @param roverName The Rover Filename.
         */
        RoverInterface(std::string& roverfilename);
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
        bool SendFormattedMessage(Communication& toSend);
        Communication RecieveFormattedMessage();
    private: 
        std::stringstream remaining;
#define EXIT_ROVER "GAME OVER"
        Logging::Logger* log;
        bool running;
        int pipes[2];
        pid_t pid;
    };
    
    
}


#endif	/* ABSTRACTROVERINTERFACE_H */

