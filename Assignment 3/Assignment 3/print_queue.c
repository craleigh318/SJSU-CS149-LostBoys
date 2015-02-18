//
//  print_queue.c
//  Assignment 3
//
//  Created by Christopher Raleigh on 2015/17/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "print_queue.h"

struct print_queue new_print_queue() {
    struct print_queue newQueue = {
        0,
        {0}
    };
    return newQueue;
}

bool add_print_job(struct print_queue * queue, char * job) {
    queue->jobs[queue->size] = job;
    ++queue->size;
    return true;
}

bool print_next_job(struct print_queue * queue) {
    int queueSize = queue->size;
    if (queueSize > 0) {
        char * nextJob = queue->jobs[0];
        int i;
        for (i = 0; i < (queueSize); ++i) {
            queue->jobs[i] = queue->jobs[i + 1];
        }
        --queue->size;
        puts(nextJob);
        return true;
    }
    else {
        return false;
    }
}