//
//  scheduler_sjf.h
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/11/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_1__scheduler_sjf__
#define __Assignment_1__scheduler_sjf__
#include "system_headers.h"
#include "ready_queue.h"

/*
 Shortest Job First scheduling alogirthm.
 */
void schedule_sjf(struct ready_queue readyQueue);

#endif /* defined(__Assignment_1__scheduler_sjf__) */