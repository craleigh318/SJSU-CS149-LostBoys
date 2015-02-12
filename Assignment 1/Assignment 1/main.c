//
//  main.c
//  Assignment 1
//
//  Created by Christopher Raleigh on 2015/05/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "system_headers.h"
#include "ready_queue.h"
#include "scheduler_fcfs.h"
#include "shortest_remaining_time.h"

void print_simulated_process(struct simulated_process printingProcess)
{
    printf("Arrival Time: %f\nExpected Run Time: %f\nPriority: %d\n", printingProcess.arrivalTime,
           printingProcess.expectedRunTime, printingProcess.priority);
}

void print_ready_queue(struct ready_queue printingQueue)
{
    int queueSize = printingQueue.length;
    int i = 0;
    while (i < queueSize)
    {
        printf("Process %d:\n", (i + 1));
        print_simulated_process(printingQueue.processes[i]);
        printf("\n");
        ++i;
    }
}

/*
 Call your scheduling algorithms here.
 */
void run_schedulers(struct ready_queue runningQueue)
{
    struct ready_queue queueFCFS = copy_ready_queue(runningQueue);
    schedule_fcfs(runningQueue);
    delete_ready_queue(&queueFCFS);

    struct ready_queue queueSRT = copy_ready_queue(runningQueue);
    schedule_SRT(queueSRT);
    delete_ready_queue(&queueSRT);
}

int main(int argc, const char * argv[])
{
    srand((unsigned int)time(NULL));
    int queueSize = 32;
    struct ready_queue randomQueue = new_ready_queue(queueSize);
    sort_ready_queue(&randomQueue);
    print_ready_queue(randomQueue);

    run_schedulers(randomQueue);
    delete_ready_queue(&randomQueue);
    return 0;
}
