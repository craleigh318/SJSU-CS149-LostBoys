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
#include "threaded_queue.h"

/*
 Prints to the console.
 */
static ThreadedQueue printQueue;

/*
 Thread for print queue.
 */
static pthread_t printThread;

/*
 Adds a string to the print queue.
 Returns true if successful.
 */
bool print_pq(char * job);

/*
 Entry point for the print queue thread.
 */
void * thread_for_print_queue(void * params);

#endif /* defined(__Assignment_3__print_queue__) */
