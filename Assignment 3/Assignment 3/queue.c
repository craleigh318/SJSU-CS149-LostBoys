//
//  queue.c
//  Queues for C
//
//  Created by Christopher Raleigh on 2015/26/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "queue.h"

Queue new_queue() {
    Queue newQueue;
    newQueue.head = NULL;
    newQueue.tail = NULL;
    return newQueue;
}

bool queue_is_empty(Queue * queue) {
    return !queue->head;
}

void add_to_queue(Queue * queue, void * datum) {
    QueueElement * newTail = new_queue_element(datum);
    if (queue_is_empty(queue)) {
        queue->head = newTail;
    } else {
        queue->tail->next = newTail;
    }
    queue->tail = newTail;
}

void * remove_from_queue(Queue * queue) {
    QueueElement * oldHead = queue->head;
    void * returnDatum = oldHead->datum;
    queue->head = oldHead->next;
    delete_queue_element(oldHead);
    if (queue_is_empty(queue)) {
        queue->tail = NULL;
    }
    return returnDatum;
}