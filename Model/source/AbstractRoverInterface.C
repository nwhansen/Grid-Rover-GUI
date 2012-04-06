/* 
 * File:   AbstractRoverInterface.C
 * Author: Nathan Hansen
 * 
 * Created on April 4, 2012, 10:31 AM
 */

#include "AbstractRoverInterface.h"
#include <sys/resource.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <stdio.h>

using namespace AbstractModelNameSpace;
void Error(bool, std::string);
std::string robot_filename = "";

AbstractRoverInterface::AbstractRoverInterface(std::string& filename) {
    int pipe_in[2], pipe_out[2];
    if (pipe(pipe_in))
        Error(true, "Couldn't setup pipe_in for robot " + filename, "Robot::start_process");

    if (pipe(pipe_out))
        Error(true, "Couldn't setup pipe_out for robot " + filename, "Robot::start_process");

    if ((pid = fork()) < 0)
        Error(true, "Couldn't fork childprocess for robot " + filename, "Robot::start_process");

    if (pid == 0) // Child process, to be the new robot
    {
        // Make pipe_out the standard input for the robot
        close(pipe_out[1]);
        dup2(pipe_out[0], STDIN_FILENO);

        // Make pipe_in the standard output
        dup2(pipe_in[1], STDOUT_FILENO);
        close(pipe_in[0]);

        // Make the pipes non-blocking
        //Not using non_blocking
        //        if (use_non_blocking) {
        //            int pd_flags;
        //            if ((pd_flags = fcntl(pipe_out[0], F_GETFL, 0)) == -1)
        //                Error(true, "Couldn't get pd_flags for pipe_out in robot " + robot_filename,
        //                    "Robot::start_process, child");
        //            pd_flags |= O_NONBLOCK;
        //            if (fcntl(pipe_out[0], F_SETFL, pd_flags) == -1)
        //                Error(true, "Couldn't change pd_flags for pipe_out in robot " + robot_filename,
        //                    "Robot::start_process, child");
        //
        //
        //            if ((pd_flags = fcntl(pipe_in[1], F_GETFL, 0)) == -1)
        //                Error(true, "Couldn't get pd_flags for pipe_in in robot " + robot_filename,
        //                    "Robot::start_process, child");
        //            pd_flags |= O_NONBLOCK;
        //            if (fcntl(pipe_in[1], F_SETFL, pd_flags) == -1)
        //                Error(true, "Couldn't change pd_flags for pipe_in in robot " + robot_filename,
        //                    "Robot::start_process, child");
        //        }

        // Check file attributes

        // Lower priority by one
        
        int old;
        if ((old = getpriority(PRIO_PROCESS, 0)) == -1)
            Error(true, "Couldn't get priority for robot " + filename,
                "Robot::start_process, child");
        if (setpriority(PRIO_PROCESS, 0, old + 1) == -1)
            Error(true, "Couldn't set priority for robot " + filename,
                "Robot::start_process, child");

        // Close all pipes not belonging to the robot
        //Todo: Get pipe cleaning complete.

        // Execute process. Should not return!
        running = true;
        if (execl(robot_filename.c_str(), robot_filename.c_str(), NULL) == -1) //Maybe.
            // we are in another process so exiting does not solve the problem
            Error(true, "Couldn't open robot " + filename,
                "Robot::start_process, child");
        running = false;
        Error(true, "Robot didn't execute, SHOULD NEVER HAPPEN!, error for " + filename,
                "Robot::start_process, child");
    } else {
        close(pipe_out[0]); // Close input side of pipe_out
        close(pipe_in[1]); // Close output side of pipe_in

        pipes[0] = pipe_out[1];
        pipes[1] = pipe_in[0];

    }

    // wait some time to let process start up
    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 40000; //  1/25 s

    select(FD_SETSIZE, NULL, NULL, NULL, &timeout);
}


std::string AbstractRoverInterface::getRoverCommand() {
    //Buffers
    char buffer[1024];
    if (read(pipes[1], buffer, sizeof(buffer)) < 0){
        //Error! quit
        return NULL;
    }
    return std::string(buffer);
}

bool AbstractRoverInterface::SendRoverCommand(std::string& roverCommand){
    if(write(pipes[0], roverCommand.c_str(), roverCommand.size())){
        //TODO: ERROR REPORT
        //Error report to log
        return false;
    }
    //Log something maybe.
    return true;
}

void AbstractRoverInterface::CloseConnection() {
    //Term the robot.
    SendRoverCommand(EXIT_ROVER);
    close(pipes[0]);
    close(pipes[1]);
    running = false;
}

AbstractRoverInterface::~AbstractRoverInterface() {
    //Term the rover
    
}