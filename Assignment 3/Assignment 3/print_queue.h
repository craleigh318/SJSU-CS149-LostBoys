//
//  print_queue.h
//  Assignment 3
//
//  Created by Christopher Raleigh on 2015/17/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_3__print_queue__
#define __Assignment_3__print_queue__
#include "system_headers.h"
#define PRINT_QUEUE_MAX_SIZE 8

/*
 Prints to the console.
 */
struct print_queue {
    int size;
    char * jobs[PRINT_QUEUE_MAX_SIZE];
    bool locked;
};

/*
 Returns a new print queue.
 */
struct print_queue new_print_queue();

/*
 Adds a string to a print queue.
 */
bool add_print_job(struct print_queue * queue, char * job);

/*
 Prints the first-added job in a queue.
 */
bool print_next_job(struct print_queue * queue);

#endif /* defined(__Assignment_3__print_queue__) */
