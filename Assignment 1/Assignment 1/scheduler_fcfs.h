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
#include "helper_functions.h"
#include "ready_queue.h"

/*
 First come, first served scheduling alogirthm.
 */
void schedule_fcfs(struct ready_queue readyQueue);

#endif /* defined(__Assignment_1__scheduler_fcfs__) */
