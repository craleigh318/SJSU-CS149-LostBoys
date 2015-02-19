//
//  print_queue.c
//  Assignment 3
//
//  Created by Christopher Raleigh on 2015/17/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "print_queue.h"

PrintQueue new_print_queue() {
    PrintQueue newQueue = {
        0,
        {0},
        false
    };
    return newQueue;
}

bool add_print_job(PrintQueue * queue, char * job) {
    if (!queue->locked) {
        queue->locked = true;
        queue->jobs[queue->size] = job;
        ++queue->size;
        queue->locked = false;
        return true;
    }
    return false;
}

bool print_next_job(PrintQueue * queue) {
    int queueSize = queue->size;
    if (!queue->locked && (queueSize > 0)) {
        queue->locked = true;
        char * nextJob = queue->jobs[0];
        int i;
        for (i = 0; i < (queueSize); ++i) {
            queue->jobs[i] = queue->jobs[i + 1];
        }
        --queue->size;
        puts(nextJob);
        queue->locked = false;
        return true;
    }
        return false;
}

void thread_loop_for_print_queue(PrintQueue * printQueue) {
    print_next_job(printQueue);
    thread_loop_for_print_queue(printQueue);
}

void * thread_for_print_queue(void * params) {
    mainPrintQueue = new_print_queue();
    thread_loop_for_print_queue(&mainPrintQueue);
    return NULL;
}