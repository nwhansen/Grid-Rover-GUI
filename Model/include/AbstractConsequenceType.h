/* 
 * File:   AbstractConsequenceType.h
 * Author: Nathan Hansen
 *
 * Created on March 28, 2012, 5:29 PM
 */

#ifndef ABSTRACTCONSEQUENCETYPE_H
#define	ABSTRACTCONSEQUENCETYPE_H
#include "AbstractModel.h"
namespace AbstractModelNameSpace {
    enum AbstractConsequenceType {
       //The float order if and only if they are equal. The higher up it is the higher priority it has.
        Metor, 
        Move, 
        Get 
    }; 
}

#endif	/* ABSTRACTCONSEQUENCETYPE_H */

