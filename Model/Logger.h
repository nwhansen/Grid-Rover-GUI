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
            return Logger::ActiveLogger;
        }

        /**
         * Create a logger object. If another active logger exists throws an exception.
         */
        Logger();

        /**
         * Though Shall not COPY!
         * Throws an exception don't do it.
         */
        Logger(const Logger& orig);

        /**
         * Attempts to open the logs specified by the paths. If either logger cannot be opened this will fail and close all connections.
         * Also if the log files are the same the logger will return false with no logs opened.
         * @param messageLog The Message Log.
         * @param errorLog The Error Log
         * @return The result of opening the logs
         */
        bool openLogs(const std::string& messageLog, const std::string& errorLog);

        virtual ~Logger();

        void Error(bool console, const std::string& message);

        /**
         * Log a Message to the Message log
         * @param console Write the console 
         * @param message The message to write to the log
         */
        void Message(bool console, const std::string& message);

        /**
         * Attempts to aquire a logger. Will not create a logger. 
         * This will not create a logger. It will time out after 5 seconds and return without modifying the variable
         * @param toAssign the logger pointer to assign the active logger.
         */
        static void aquireLogger(Logger*& toAssign);

        static void writeToLog(Logging::Logger* theLog, const std::string& message, bool error = false) {
            if (theLog == 0) {
                return;
            }
            if (error) theLog->Error(false, message);
            else theLog->Message(false, message);
        }
    private:
        static Logger* ActiveLogger;
        pthread_mutex_t lock;
        std::ofstream ErrorLog;
        std::ofstream MessageLog;
        std::string constructMessage(const std::string& message);
    };
}
#endif	/* LOGGER_H */

