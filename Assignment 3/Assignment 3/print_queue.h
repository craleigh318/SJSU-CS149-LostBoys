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
typedef struct {
    int size;
    char * jobs[PRINT_QUEUE_MAX_SIZE];
    bool locked;
} PrintQueue;

static PrintQueue mainPrintQueue;

/*
 Returns a new print queue.
 */
PrintQueue new_print_queue();

/*
 Adds a string to a print queue.
 
 Returns true if successful.
 */
bool add_print_job(PrintQueue * queue, char * job);

/*
 Prints the first-added job in a queue.
 
 Returns true if successful.
 */
bool print_next_job(PrintQueue * queue);

/*
 Entry point for the print queue thread.
 */
void thread_for_print_queue();

#endif /* defined(__Assignment_3__print_queue__) */
