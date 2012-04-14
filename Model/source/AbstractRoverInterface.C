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
#include <unistd.h>

void func() {
    
}

using namespace AbstractModelNameSpace;

AbstractRoverInterface::AbstractRoverInterface(std::string& filename) {
    //Attempt to get the logger The thread will stall if 
    
    log->aquireLogger(log);
    if (log->activeLogger() == 0) {
        //Die?
        throw 1;
    }
    int pipe_in[2], pipe_out[2];
    if (pipe(pipe_in))
        log->Error(true,std::string("Couldn't setup pipe_in for rover " + filename));

    if (pipe(pipe_out))
        log->Error(true, std::string("Couldn't setup pipe_out for rover " + filename));

    if ((pid = fork()) < 0)
        log->Error(true, std::string("Couldn't fork child process for rover " + filename));

    if (pid == 0) // Child process, to be the new robot
    {
        // Make pipe_out the standard input for the robot
        close(pipe_out[1]);
        dup2(pipe_out[0], STDIN_FILENO);

        // Make pipe_in the standard output
        dup2(pipe_in[1], STDOUT_FILENO);
        close(pipe_in[0]);

        int old;
        if ((old = getpriority(PRIO_PROCESS, 0)) == -1)
            log->Error(true, "Couldn't get priority for rover " + filename);
        if (setpriority(PRIO_PROCESS, 0, old + 1) == -1)
            log->Error(true, "Couldn't set priority for rover " + filename);

        // Close all pipes not belonging to the robot
        //Todo: Get pipe cleaning complete.

        // Execute process. Should not return!
        running = true;
        if (execl(filename.c_str(), filename.c_str(), NULL) == -1) //Maybe.
            // we are in another process so exiting does not solve the problem
            log->Error(true, "Couldn't open robot " + filename);
        running = false;
        log->Error(true, "Robot didn't execute, SHOULD NEVER HAPPEN!, error for " + filename);
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
    size_t totalRead;
    if (totalRead = read(pipes[1], buffer, sizeof (buffer)) < 0) {
        log->Error(false, "Unable to read from robot. Sent null terminating character");
        return NULL;
    }
    return std::string(buffer, totalRead);
}

bool AbstractRoverInterface::SendRoverCommand(const std::string& roverCommand) {
    if (write(pipes[0], roverCommand.c_str(), roverCommand.size())) {
        //TODO: ERROR REPORT
        log->Error(true, "Unable to send message! Unknown reason");
        return false;
    }
    //Log something maybe.
    log->Message(false, "Sent message to rover");
    return true;
}

void AbstractRoverInterface::CloseConnection() {
    //Term the robot.
    SendRoverCommand(std::string(EXIT_ROVER));
    close(pipes[0]);
    close(pipes[1]);
    running = false;
}

AbstractRoverInterface::~AbstractRoverInterface() {
    //Term the rover

}
//using a socket pair instead.
#include <sys/types.h>
#include <sys/socket.h>
#define DATA1 "In Xanadu, did Kublai Khan..." 
#define DATA2 "A stately pleasure dome decree..."
void ex() {
    int sockets[2], child;
    char buf[1024];

    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockets) < 0) {
        perror("opening stream socket pair");
        exit(1);
    }

    if ((child = fork()) == -1)
        perror("fork");
    else if (child) { 
        /* This is the parent. */
        close(sockets[0]);
        if (read(sockets[1], buf, sizeof (buf)) < 0)
            perror("reading stream message");
        printf("-->%s\n", buf);
        if (write(sockets[1], DATA2, sizeof (DATA2)) < 0)
            perror("writing stream message");
        close(sockets[1]);
    } else { /* This is the child. */
        close(sockets[1]);
        if (write(sockets[0], DATA1, sizeof (DATA1)) < 0)
            perror("writing stream message");
        if (read(sockets[0], buf, sizeof (buf)) < 0)
            perror("reading stream message");
        printf("-->%s\n", buf);
        close(sockets[0]);
    }
}
