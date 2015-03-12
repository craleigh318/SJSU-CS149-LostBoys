//
//  Process.h
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/05/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_4__Process__
#define __Assignment_4__Process__
#include "SystemHeaders.h"

/*
 Represents a process on the PC.
 */
class Process {
    
public:
    /*
     Constructs a new process.
     */
    Process();
    
    /*
     The size, in MB.
     */
    int getSize();
    
    /*
     The duration, in seconds.
     */
    int getDuration();
    
    /*
     The one-letter name of this process.
     */
    char getName();
    
private:
    static const int allowedSizes[];
    
    static const int allowedDurations[];
    
    static char currentLetter;
    
    /*
     Returns a random int from the specified array.
     */
    int getRandomIntFromArray(const int * array, const int arraySize);
    
    /*
     Returns a random size less than or equal to the specified max.
     */
    int getRandomSize();
    
    /*
     Returns a random duration less than or equal to the specified max.
     */
    int getRandomDuration();
    
    /*
     Returns a unique name.
     */
    char getUniqueName();
    
    int size;
    
    int duration;
    
    char name;
};

#endif /* defined(__Assignment_4__Process__) */
