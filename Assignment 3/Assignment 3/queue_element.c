//
//  queue_element.c
//  Queues for C
//
//  Created by Christopher Raleigh on 2015/26/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "queue_element.h"

QueueElement * new_queue_element(void * datum)
    {
    QueueElement * newQueueElement = malloc(sizeof(QueueElement));
    newQueueElement->datum = datum; 
    newQueueElement->next = NULL;
    return newQueueElement;
}

void delete_queue_element(QueueElement * element) {
    free(element);
}