/* 
 * File:   AbstractConsequence.h
 * Author: Nathan Hansen
 *
 * Created on March 26, 2012, 9:30 PM
 */

#ifndef ABSTRACTCONSEQUENCE_H
#define	ABSTRACTCONSEQUENCE_H
#include <string>
#include "AbstractConsequenceType.h"
namespace AbstractModelNameSpace {

    class AbstractConsequence {
    public:
        
        /**
         * @return the String representation of this consequence
         */
        //virtual std::string toString() {}
        
        //Note this operator is used for priority queue. 
        /**
         * Define what it means to be less than an other AbstractConsequence
         * @param other
         * @return 
         */
        virtual bool operator <(const AbstractConsequence &other) const = 0; 
        
        
        virtual bool operator()(const AbstractConsequence &l, const AbstractConsequence &r) const = 0;
        /**
         * Defines what it means for this Consequence to be greater than another.
         * @param other
         * @return 
         */
        virtual bool operator >(const AbstractConsequence &other) const = 0;
        
        AbstractConsequenceType getConsequenceType() {
            return Type;
        }
        
    protected:
        AbstractConsequenceType Type;

    };
}
#endif	/* ABSTRACTCONSEQUENCE_H */

