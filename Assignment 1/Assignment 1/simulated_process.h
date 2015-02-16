//
//  simulated_process.h
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/05/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_1__simulated_process__
#define __Assignment_1__simulated_process__
#include "system_headers.h"

/*
 Represents a task for a processor to computer.
 */
struct simulated_process
{
    /*
     A name for each process.
     */
    int identifier;
    
    /*
     Ranges from 0.0 to 99.0.
     */
    float arrivalTime;
    
    /*
     Ranges from 0.1 to 10.0.
     */
    float expectedRunTime;
    
    /*
     Ranges from 1 to 4.  Lower values indicate higher priority.
     */
    int priority;
    
    /*
     Mark a process as being visited
     */
    
    int flagVisited;
    
    
    /*
     Mark a process as complete
     */
    
    int flagComplete;
    
    /*
     Holds the time when a process enters the ready queue
     */
    float timeEnteredReadyQueue;
    
    /*
     Holds the time when a process starts running
     */
    float timeStartsRunning;
};

/*
 Returns a new simulated process with random values.
 */
struct simulated_process new_simulated_process();

//REMOVE ME
struct simulated_process new_nonRandom_simulated_process(int identifier, float arrival, float runtime, int priority, int flagVisit, int flagComplete);

#endif /* defined(__Assignment_1__simulated_process__) */
