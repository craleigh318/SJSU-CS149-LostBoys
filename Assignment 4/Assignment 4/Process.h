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
typedef struct {
    
    /*
    The size in MB.
    */
    int size;
    
    /*
     The duration in seconds.
     */
    int duration;
    
} Process;

static const int allowedSizes[] = {
    5,
    11,
    17,
    31
};

static const int allowedDurations[] = {
    1,
    2,
    3,
    4,
    5
};

/*
 Constructs and returns a new process.
 */
Process newProcess(int size, int duration);

/*
 Returns a random int from the specified array.
 */
int getRandomIntFromArray(const int * array, const int arraySize, int max);

/*
 Returns a random size less than or equal to the specified max.
 */
int getRandomSize(int max);

/*
 Returns a random duration less than or equal to the specified max.
 */
int getRandomDuration(int max);

#endif /* defined(__Assignment_4__Process__) */
