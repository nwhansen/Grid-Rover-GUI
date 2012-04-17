/* 
 * File:   Logger.C
 * Author: Nathan Hansen
 * 
 * Created on April 6, 2012, 9:27 AM
 */

#include "Logger.h"
#include <time.h>
#include <ostream>
#include <sstream>

using namespace Logging;

Logger* Logger::ActiveLogger = 0;
std::string convertTime(time_t * time);
std::string Logger::constructMessage(const std::string& message) {
    //Ok lets get this shit done.
    std::stringstream stream;
    time_t now = time(NULL);
    stream << "[" << convertTime(&now) << "] " << message;
    return stream.str();
}
Logger::Logger() {
    //Ok lets do this
    if (activeLogger() != 0) {
        throw 1;
    } else {
        ActiveLogger = this;
    }
    if (activeLogger() != this) {
        //Somebody else is the active logger. This isn't the best way of doing this but oh well.
        //Terminate this logger.
        throw 1;
    }
    pthread_mutex_init(&lock, NULL);
}

void Logger::aquireLogger(Logger*& toAssign) {
    //Spin wheels
    time_t start = time(NULL);
    //Time out after 5 seconds. 
    while (activeLogger() == 0 && 5.0 > difftime(time(NULL), start))
        usleep(100000);
    //If we time out ativelogger will return 0 therefor we wont have a problem. Or it will magically find us a logger and all will work. 
    toAssign = activeLogger();
}

bool Logger::openLogs(std::string& messageLog, std::string& errorLog) {
    //Construct the objects.
    if (messageLog.compare(errorLog) == 0) {
        return false;
    }
    ErrorLog.open(errorLog.c_str(), std::ios::app | std::ios::app);
    MessageLog.open(errorLog.c_str(), std::ios::app | std::ios::app);
    if (!ErrorLog.is_open() || !MessageLog.is_open()) {
        //close the unopened one
        if (ErrorLog.is_open())
            ErrorLog.close();
        if (MessageLog.is_open())
            MessageLog.close();
        return false;
    }
    return true;
}

Logger::Logger(const Logger& orig) {
    throw 1;
}

Logger::~Logger() {
    //Close log files
    ErrorLog.close();
    MessageLog.close();
    pthread_mutex_destroy(&lock);
    //Allow for another logger to be created.
    Logger::ActiveLogger = 0;
}

std::string convertTime(time_t* ptr) {
    //Ok lets perform magic.
    char buff[1024];
    
    //Generates the date formate of MM/DD/YY HH:MM:SS
    size_t size = strftime(buff, (size_t) 1024, "%x %H:%M:%S", localtime(ptr));
    return std::string(buff, size);
}

void Logger::Error(bool console,const std::string& message) {
    if (!ErrorLog.is_open()) return;
    pthread_mutex_lock(&lock);
    if (console) {
        //Output to the console in the error console
        std::cerr << constructMessage(message);
    }
    ErrorLog << constructMessage(message);
    pthread_mutex_unlock(&lock);
}

void Logger::Message(bool console, const std::string& message) {
    if (!MessageLog.is_open()) return;
    pthread_mutex_lock(&lock);
    if (console) {
        std::cout << constructMessage(message);
    }
    MessageLog << constructMessage(message);
    pthread_mutex_unlock(&lock);
}

