/* 
 * File:   TitanTime.h
 * Author: Nathan Hansen
 *
 * Created on March 28, 2012, 1:19 PM
 */

#ifndef TITANTIME_H
#define	TITANTIME_H
#include <sstream>
#include <string>

/**
 * A namespace for everything specific to titan such as the time objects. Will techincally this doesn't have to be
 * a seperate namespace it may be expanded further.
 */
namespace Titan {

    /**
     * Provides the understanding of time comparisons for a stack organizations. 
     */
    class TitanTime {
    public:

        /**
         * Titan time begins at Day 0 Hour 0 and minute 0. Relative from touchdown. Time is immutable and cannot be changed.
         * @param days How many days from touchdown.
         * @param hours how many hours from touchdown
         * @param minutes how many minutes from touchdown 
         */
        TitanTime(unsigned int days = 0,
                unsigned int hours = 0,
                unsigned int minutes = 0
                ) : Days(days < 0 ? 0 : days),
        Hours(hours < 0 ? 0 : hours),
        Minutes(minutes < 0 ? 0 : minutes) {

        }

        /**
         * @return The date in string format of dd:hh:mm terminated by a new line.
         */
        std::string getTimeString() {
            std::stringstream ss;
            ss << Days << ":" << Hours << ":" << Minutes << std::endl;
            return ss.str();
        }

        /**
         * @return The total number of hours that have passed since touchdown, rounded down.
         * @remarks A day is converted into 24 titan minutes.
         */
        unsigned int getNumberOfHours() {
            return 24 * Days + Hours;
        }
        /**
         * @return The total number of minutes that have passed since touchdown, rounded down.
         * @remarks A hour is 60 titan minutes
         */
        unsigned int getNumberOfMinutes() {
            return (Days * 24 + Hours)*60 + Minutes;
        }
        /**
         * 
         * @return The number of days since touchdown, rounded down.
         */
        unsigned int getNumberOfDays() {
            return Days;
        }
        
        
        bool operator ==(TitanTime const &other) const {
            return this->Days == other.Days &&
                    this->Hours == other.Hours &&
                    this->Minutes == other.Minutes;
        }
        
        bool operator >(TitanTime const &other) const {
            //If the days are the same check the hours and same for hours
            return (this->Days != other.Days) ? //Check Days 
                this->Days > other.Days : (this->Hours != other.Hours) ? //Check Hours
                    this->Hours > other.Hours : (this->Minutes != Minutes) ? //Check Minutes
                    this->Minutes > other.Minutes : false; //They are equal in all effects therefor it is not greater.
        }
    private:
        unsigned int Days, Hours, Minutes;
        //A titan day is 15.945 earth days. 
    };
}
#endif	/* TITANTIME_H */

