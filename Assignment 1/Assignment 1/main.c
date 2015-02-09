//
//  main.c
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/05/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "system_headers.h"
#include "ready_queue.h"

void print_simulated_process(struct simulated_process * printingProcess)
{
    printf("Arrival Time: %f\nExpected Run Time: %f\nPriority: %d\n", printingProcess->arrivalTime, printingProcess->expectedRunTime, printingProcess->priority);
}

int main(int argc, const char * argv[])
{
    srand((unsigned int)time(NULL));
    int queueSize = 4;
    struct ready_queue randomQueue = new_ready_queue(queueSize);
    int i = 0;
    while (i < queueSize)
    {
        printf("Process %d:\n", ++i);
        print_simulated_process(&randomQueue.processes[i]);
        printf("\n");
    }
    delete_ready_queue(&randomQueue);
    return 0;
}