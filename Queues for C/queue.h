//
//  queue.h
//  Queues for C
//
//  Created by Christopher Raleigh on 2015/26/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Queues_for_C__queue__
#define __Queues_for_C__queue__
#include "queue_element.h"
#include <stdbool.h>

/*
 Adds and removes elements on a first-in first-out basis.
 */
typedef struct _queue {
    /*
     The queue's oldest element.
     */
    QueueElement * head;
    
    /*
     The queue's newest element.
     */
    QueueElement * tail;
} Queue;

/*
 Creates a new queue.
 */
Queue new_queue();

/*
 Returns true if this queue is empty.
 */
bool queue_is_empty(Queue * queue);

/*
 Adds the specified datum to the specified queue.
 */
void add_to_queue(Queue * queue, void * datum);

/*
 Removes and returns the head of this queue.
 */
void * remove_from_queue(Queue * queue);

#endif /* defined(__Queues_for_C__queue__) */
