/* 
 * File:   Logger.C
 * Author: Nathan Hansen
 * 
 * Created on April 6, 2012, 9:27 AM
 */

#include "Logger.h"
#include <time.h>
using namespace Logging;
Logger::Logger() {
    //Ok lets do this
    if(ActiveLogger != 0){
        throw 1;
    } else {
        ActiveLogger = this;
    }
    if(ActiveLogger != this) {
        //Somebody else is the active logger. This isn't the best way of doing this but oh well.
        //Terminate this logger.
        throw 1;
    }
        
}

bool Logger::openLogs(std::string messageLog, std::string errorLog) {
    //Construct the objects.
    ErrorLog.open(errorLog, std::ios::app | std::ios::app);
    MessageLog.open(errorLog,std::ios::app | std::ios::app);
    if(!ErrorLog.is_open() || !MessageLog.is_open()) {
        //close the unopened one
        if(ErrorLog.is_open())
            ErrorLog.close();
        if(MessageLog.is_open())
            MessageLog.close();
        return false;
    }
}

Logger::Logger(const Logger& orig) {
}

Logger::~Logger() {
}

std::string convertTime(time_t* ptr){
    //Ok lets perform magic.
    char buff[1024];
    //Generates the date formate of MM/DD/YY HH:MM:SS
    size_t size = strftime(&buff, (size_t)1024, "%x %H:%M:%S", ptr);
    return std::string(&buff, size);
}



std::string Logger::constructMessage(std::string& message) {
    //Ok lets get this shit done.
    std::stringstream stream;
    stream << "[" << convertTime(time(NULL)) << "] " << message;
    
}