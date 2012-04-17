/* 
 * File:   StackConsequence.h
 * Author: Nathan Hansen
 *
 * Created on March 29, 2012, 2:07 PM
 */

#ifndef STACKCONSEQUENCE_H
#define	STACKCONSEQUENCE_H
#include "AbstractConsequence.h"
#include "TitanTime.h"
#include "AbstractConsequenceType.h"

namespace StackModelNameSpace {

    class StackConsequence : public AbstractModelNameSpace::AbstractConsequence {
    public:
        StackConsequence(Titan::TitanTime FireTime, AbstractModelNameSpace::AbstractConsequenceType WhatAmI);
        StackConsequence(const StackConsequence& orig);
        virtual ~StackConsequence();
        
        std::string toString();
        
        bool operator<(const AbstractModelNameSpace::AbstractConsequence &other) const;
        
        bool operator ()(const AbstractModelNameSpace::AbstractConsequence &l, const AbstractModelNameSpace::AbstractConsequence &r) const;
        
        /**
         * Defines what it means for this Consequence to be greater than another.
         * @param other
         * @return 
         */
        bool operator>(const AbstractModelNameSpace::AbstractConsequence &other) const;
    private:
        
        Titan::TitanTime WhenToFire;
        
    };
}

#endif	/* STACKCONSEQUENCE_H */

