//
//  queue_element.h
//  Queues for C
//
//  Created by Christopher Raleigh on 2015/26/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Queues_for_C__queue_element__
#define __Queues_for_C__queue_element__
#include <stdlib.h>

/*
 Points to a datum and the next element.
 */
typedef struct _queueElement {
    /*
     The datum for this element to hold.
     */
    void * datum;
    
    /*
     The element added after this element, if one exists.
     */
    struct _queueElement * next;
} QueueElement;

/*
 Creates a new queue element that points to the specified datum.
 */
QueueElement * new_queue_element(void * datum);

/*
 Deletes the specified queue element.
 */
void delete_queue_element(QueueElement * element);

#endif /* defined(__Queues_for_C__queue_element__) */
