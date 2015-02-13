//
//  scheduler_sjf.c
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/11/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "scheduler_sjf.h"
#include "scheduler_fcfs.h"

void schedule_sjf(struct ready_queue readyQueue)
{
    printf("Shortest Job First:\nTime Line:");
    pop_ready_queue(readyQueue, new_scheduler_statistics(), 0.0f);
}