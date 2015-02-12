//
//  ready_queue.h
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/08/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_1__ready_queue__
#define __Assignment_1__ready_queue__
#include "system_headers.h"
#include "simulated_process.h"

/*
 A queue of simulated processes.
 */
struct ready_queue
{
    /*
     The number of processes in this queue.
     */
    int length;
    
    /*
     The processes, as an array.
     */
    struct simulated_process * processes;
};

/*
 Returns a new ready queue with the specified number of random processes.
 
 Call delete_ready_queue when done!
 */
struct ready_queue new_ready_queue(int length);

/*
 Returns a new ready queue with values copied from another ready queue.
 
 Call delete_ready_queue when done!
 */
struct ready_queue copy_ready_queue(struct ready_queue copyingReadyQueue);

/*
 Frees heap objects in the specified ready queue.
 */
void delete_ready_queue(struct ready_queue * deletingQueue);

/*
 Sorts a ready queue by arrival time
 */
void sort_ready_queue(struct ready_queue * sortingQueue);

#endif /* defined(__Assignment_1__ready_queue__) */
