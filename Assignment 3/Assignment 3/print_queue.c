//
//  print_queue.c
//  Assignment 3
//
//  Created by Christopher Raleigh on 2015/17/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "print_queue.h"

// prints to console
void thread_loop_for_print_queue() {
    if (!threaded_queue_is_empty(&printQueue)) {
        char * nextJob = remove_from_threaded_queue(&printQueue);
        puts(nextJob);
        free(nextJob);
        thread_loop_for_print_queue();
    }
}

void * thread_for_print_queue(void * params) {
    thread_loop_for_print_queue();
    return NULL;
}

bool print_pq(char * job) {
    bool emptyPrintQueue = threaded_queue_is_empty(&printQueue); // Checks to see if the threaded_queue is empty or not 
    char * jobCopy = strdup(job); // Keeps the old string 
    add_to_threaded_queue(&printQueue, jobCopy); 
    if (emptyPrintQueue) {
        pthread_create(&printThread, NULL, &thread_for_print_queue, NULL);
    }
    return true;
}
