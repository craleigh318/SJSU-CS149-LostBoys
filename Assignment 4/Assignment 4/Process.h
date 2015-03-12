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
#define TIME_LIMIT 60

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
    
    /*
     Returns the arrival time.
     */
    int getArrivalTime();
    
    /*
     Prints the attributes of this process.
     */
    void print();
    
    /*
     Overrides comparison method.
     */
    bool operator<(const Process& other) const;

    
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
    
    /*
     Returns a random arrival time.
     */
    int getRandomArrivalTime();
    
    int size;
    
    int duration;
    
    char name;
    
    int arrivalTime;
};

#endif /* defined(__Assignment_4__Process__) */
