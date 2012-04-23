/* 
 * File:   main.c
 * Author: Nathan Hansen
 *
 * Created on April 17, 2012, 3:32 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Engine.h"
#include "Logger.h"
/*
 * 
 */
using namespace std;

int main(int argc, char** argv) {
    Engine e(10, 10, "blah.sh", "", "error.txt", "message.txt");
    int r;
    while((r = e.next()) != GameOver) if(r != Fail) printf("%i\n",r);
    
    Logging::Logger * log;
    Logging::Logger::aquireLogger(log);
    printf("%i",log);
    log->Message(false,"Hi");
    return (EXIT_SUCCESS);
}

