/* 
 * File:   StackConsequence.C
 * Author: Nathan Hansen
 * 
 * Created on March 29, 2012, 2:07 PM
 */

#include "StackConsequence.h"
using namespace StackModelNameSpace;
StackConsequence::StackConsequence(Titan::TitanTime FireTime, AbstractModelNameSpace::AbstractConsequenceType WhatAmI) {
    //Copy values around.
    this->WhenToFire = FireTime;
    this->Type = WhatAmI;
}

StackConsequence::StackConsequence(const StackConsequence& orig) {
}

StackConsequence::~StackConsequence() {
}

bool StackConsequence::operator >(const StackConsequence& other) const {
    //Ok First priority time.
    if(other.WhenToFire == this->WhenToFire){
        //Check priority.
        //TODO: Ensure its perfect.
        return this->Type > other.Type;
    } else return (this->WhenToFire > other.WhenToFire);
    
}

