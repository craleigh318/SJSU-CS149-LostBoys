//
//  process_scheduler.h
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/10/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_1__process_scheduler__
#define __Assignment_1__process_scheduler__
#include "system_headers.h"
#include "ready_queue.h"

/*
 Pushes processes to a scheduling algorithm.
 */
struct process_scheduler
{
    /*
     Schedule all processes in the specified ready queue.
     */
    void (* scheduleReadyQueue)(struct ready_queue schedulingQueue);
};

#endif /* defined(__Assignment_1__process_scheduler__) */