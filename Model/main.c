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
    Engine e(10, 10, "rand.exe", "", "error.txt", "message.txt");
    int r;
    int moves = 0, gets = 0, fails = 0;
    while((r = e.next()) != GameOver) 
        if(r == Move) moves++; 
        else if(r == Get) gets++;
        else if (r == Fail) fails++;
    printf("%s: %i\n%s: %i\n%s: %i", "Moves Made", moves, "Get Attempts:", gets ,"Fails:", fails);
    
    return (EXIT_SUCCESS);
}

