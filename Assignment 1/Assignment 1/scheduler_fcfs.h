//
//  scheduler_fcfs.h
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/10/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_1__scheduler_fcfs__
#define __Assignment_1__scheduler_fcfs__
#include "system_headers.h"
#include "ready_queue.h"
#include "scheduler_statistics.h"

/*
 First come, first served scheduling alogirthm.
 */
void schedule_fcfs(struct ready_queue readyQueue);

/*
 Runs processes, one by one.
 */
void pop_ready_queue(struct ready_queue readyQueue, struct scheduler_statistics statistics, float timeElapsed);

/*
 Finishes run and print statistics.
 */
void finish_run(struct scheduler_statistics statistics);

#endif /* defined(__Assignment_1__scheduler_fcfs__) */
