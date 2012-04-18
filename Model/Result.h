/* 
 * File:   Result.h
 * Author: Nathan Hansen
 *
 * Created on April 17, 2012, 4:52 PM
 */

#ifndef RESULT_H
#define	RESULT_H

namespace Model {

    enum ResultType {
        Move, Get, Look, Fail
    };

    class Result {
    public:
        Result(ResultType type);
        Result(const Result& orig);
        virtual ~Result();
        ResultType getResultType();
        
    private:
        ResultType me;
        char dir;
        
    };
}

#endif	/* RESULT_H */

