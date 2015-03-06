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
    static const int allowedSizes[];
    
    static const int allowedDurations[];
    
    /*
     Returns a random size less than or equal to the specified max.
     */
    static int getRandomSize(int max);
    
    /*
     Returns a random duration less than or equal to the specified max.
     */
    static int getRandomDuration(int max);
    
    /*
     Constructor.
     */
    Process(int size, int duration);
    
    /*
     Returns the size in MB.
     */
    int getSize();
    
    /*
     Returns the duration in seconds.
     */
    int getDuration();
    
private:
    int size;
    
    int duration;
    
    /*
     Returns a random int from the specified array.
     */
    static int getRandomIntFromArray(const int array[], const int arraySize, int max);
};

#endif /* defined(__Assignment_4__Process__) */
