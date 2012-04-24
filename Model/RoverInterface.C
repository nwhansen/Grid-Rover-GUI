/* 
 * File:   AbstractRoverInterface.C
 * Author: Nathan Hansen
 * 
 * Created on April 4, 2012, 10:31 AM
 */

#include "RoverInterface.h"
#include <sys/resource.h>
#include <sys/stat.h>
#include <stdarg.h> 
#include <stdio.h>
#include <unistd.h>


using namespace Model;

RoverInterface::RoverInterface(std::string& filename) {
    //Attempt to get the logger The thread will stall if 
    logger = 0;
    //Logging::Logger::aquireLogger(logger);

    int pipe_in[2], pipe_out[2];
    if (pipe(pipe_in))
        Logging::Logger::writeToLog(logger, "Couldn't setup pipe_in for rover " + filename, true);

    if (pipe(pipe_out))
        Logging::Logger::writeToLog(logger, "Couldn't setup pipe_in for rover " + filename, true);

    if ((pid = fork()) < 0)
        Logging::Logger::writeToLog(logger, "Couldn't fork child process for rover " + filename, true);

    if (pid == 0) { //The child process!
        // Make pipe_out the standard input for the robot
        close(pipe_out[1]);
        dup2(pipe_out[0], STDIN_FILENO);

        // Make pipe_in the standard output
        dup2(pipe_in[1], STDOUT_FILENO);
        close(pipe_in[0]);

        int old;
        if ((old = getpriority(PRIO_PROCESS, 0)) == -1)
            Logging::Logger::writeToLog(logger, "Couldn't get priority for rover " + filename, true);
        if (setpriority(PRIO_PROCESS, 0, old + 1) == -1)
            Logging::Logger::writeToLog(logger, "Couldn't set priority for rover " + filename, true);

        // Close all pipes not belonging to the robot
        //Todo: Get pipe cleaning complete.

        // Execute process. Should not return!
        running = true;
        if (execl(filename.c_str(), filename.c_str(), NULL) == -1);
        //Maybe.
        // we are in another process so exiting does not solve the problem
        Logging::Logger::writeToLog(logger, "Couldn't open robot " + filename, true);
        running = false;
        //exit(-1); //Terminate angry.
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
    running = true;
    select(FD_SETSIZE, NULL, NULL, NULL, &timeout);
}

std::string RoverInterface::getRoverCommand() {
    //Buffers
    char buffer[1024];
    for (int i = 0; i < sizeof (buffer); i++) {
        buffer[i] = '\0'; //Clear the damn buffer.
    }
    size_t totalRead;
    if (read(pipes[1], buffer, 1024) < 0) {
        Logging::Logger::writeToLog(logger, "Unable to read from robot.", true);
        return std::string("");
    }
    return std::string(buffer);
}

bool RoverInterface::SendRoverCommand(const std::string& roverCommand) {
    if (write(pipes[0], roverCommand.c_str(), roverCommand.size())) {
        //TODO: ERROR REPORT
        //Logging::Logger::writeToLog(logger, "Unable to send message! Pipe may be closed", true);
        return false;
    }
    //Log something maybe.
    Logging::Logger::writeToLog(logger, "Sent message to rover" + roverCommand, false);
    return true;
}

void RoverInterface::CloseConnection() {
    //Term the robot.
    if (this->running)return;
    SendRoverCommand(std::string(EXIT_ROVER));
    close(pipes[0]);
    close(pipes[1]);
    running = false;
    Logging::Logger::writeToLog(logger, "Closed the rover, hopefully");
}

std::vector<std::string> split(const std::string &s, char delim);

bool RoverInterface::SendFormattedMessage(Communication& toSend) {
    std::stringstream toWrite(toSend.command);
    toWrite << " ";
    for (unsigned int i = 0; i < toSend.arguments.size(); i++) {
        if (i == (toSend.arguments.size() - 1)) {
            toWrite << toSend.arguments[i] << std::endl;
        } else toWrite << toSend.arguments[i] << " ";
    }
    return this->SendRoverCommand(toWrite.str());
}

Communication RoverInterface::RecieveFormattedMessage() {
    //This is going to suck...
    //We need to read from the buffer and only send back one formated command. if we get more we will need to cache the info.
    remaining << this->getRoverCommand();
    //Utilizing get line 
    std::string roverMessage;
    std::getline(remaining, roverMessage);
    //Ok lets try this.
    //Lets assume only valid communication.
    if (roverMessage.length() == 0)
        return Communication();
    //Lets splot this shit!
    std::vector<std::string> brokenMessage = split(roverMessage, ' ');
    if (brokenMessage.size() == 0)
        return Communication();
    Communication message;
    message.command = brokenMessage[0];
    //Start at one to skip the first element. There is most likely an easier way to do this but it works for now.
    for (unsigned int i = 1; i < brokenMessage.size(); i++) {
        message.arguments.push_back(brokenMessage[i]);
    }
    return message;
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    return split(s, delim, elems);
}

RoverInterface::~RoverInterface() {
    //Term the rover
    CloseConnection();
}
/*
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
        close(sockets[0]);
        if (read(sockets[1], buf, sizeof (buf)) < 0)
            perror("reading stream message");
        printf("-->%s\n", buf);
        if (write(sockets[1], DATA2, sizeof (DATA2)) < 0)
            perror("writing stream message");
        close(sockets[1]);
    } else { 
        close(sockets[1]);
        if (write(sockets[0], DATA1, sizeof (DATA1)) < 0)
            perror("writing stream message");
        if (read(sockets[0], buf, sizeof (buf)) < 0)
            perror("reading stream message");
        printf("-->%s\n", buf);
        close(sockets[0]);
    }
}
 */

