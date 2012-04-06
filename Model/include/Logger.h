/* 
 * File:   Logger.h
 * Author: Nathan Hansen
 *
 * Created on April 6, 2012, 9:27 AM
 */

#ifndef LOGGER_H
#define	LOGGER_H
#include <string>
#include <iostream>
#include <fstream>
#include <pthread.h>

namespace Logging {

    class Logger {
    public:

        /**
         * The Current active logger. As only one should ever be opened.
         */
        static Logger* activeLogger() {
            return ActiveLogger;
        }
        /**
         * Create a logger object. If another active logger exists throws an exception.
         */
        Logger();
        Logger(const Logger& orig);
        /**
         * Attempts to open the logs specified by the paths. If either logger cannot be opened this will fail and close all connections.
         * @param messageLog The Message Log.
         * @param errorLog The Error Log
         * @return The result of opening the logs
         */
        bool openLogs(std::string messageLog, std::string errorLog);
        virtual ~Logger();
        
        void Error(bool console, std::string& message);
        
        /**
         * Log a Message to the Message log
         * @param console Write the console 
         * @param message The message to write to the log
         */
        void Message(bool console, std::string& message);
        
    private:
        static Logger* ActiveLogger = 0;
        std::ofstream ErrorLog;
        std::ofstream MessageLog;
        std::string constructMessage(std::string& message);
    };
}
#endif	/* LOGGER_H */

