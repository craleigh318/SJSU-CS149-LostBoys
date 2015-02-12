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
};

/*
 Returns a new simulated process with random values.
 */
struct simulated_process new_simulated_process();

#endif /* defined(__Assignment_1__simulated_process__) */
