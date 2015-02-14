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
    float turnaround_time;
    float waiting_time;
    float response_time;
    int throughput;
};

/*
 Returns a new statistics object.
 */
struct scheduler_statistics new_scheduler_statistics();

#endif /* defined(__Assignment_1__scheduler_statistics__) */