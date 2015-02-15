//
//  scheduler_statistics.h
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/11/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_1__scheduler_statistics__
#define __Assignment_1__scheduler_statistics__
#include "system_headers.h"

struct scheduler_statistics
{
    /*
     The amount of elapsed time from when a process
     enters the ready queue to when it completes execution.
     */
    float turnaround_time;
    
    /*
     Amount of time a process waits in the ready queue.
     */
    float waiting_time;
    
    /*
     In an interactive environment, the amount of elapsed time
     from when a request was submitted until the first response is produced.
     */
    float response_time;
    
    /*
     Number of processes that complete their execution per time unit.
     */
    int throughput;
};

/*
 Returns a new statistics object.
 */
struct scheduler_statistics new_scheduler_statistics();

#endif /* defined(__Assignment_1__scheduler_statistics__) */