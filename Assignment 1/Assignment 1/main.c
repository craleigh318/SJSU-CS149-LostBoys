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
#include "scheduler_sjf.h"
#include "scheduler_srt.h"
#include "round_robin.h"
#include "global_statistics.h"
#include "helper_functions.h"


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

void print_statistics()
{
    
    int throughput = globalStatistics.throughput / NUM_TRIALS;
    float avgTurnaround = globalStatistics.turnaround_time / (float)NUM_TRIALS;
    float avgWaitTime = globalStatistics.waiting_time / (float)NUM_TRIALS;
    float avgResponse = globalStatistics.response_time / (float)NUM_TRIALS;
    printf("\nAvg. Turnaround Time: %f\nAvg. Wait Time: %f\nAvg. Response Time: %f\nAvg. Throughput: %d\n\n",
           avgTurnaround, avgWaitTime, avgResponse, throughput);
}

void run_one_scheduler(void (* scheduler_name)(struct ready_queue), struct ready_queue runningQueue)
{
    struct ready_queue queueCopy;
    for (int i = 0; i < NUM_TRIALS; ++i)
    {
        queueCopy = copy_ready_queue(runningQueue);
        scheduler_name(queueCopy);
        delete_ready_queue(&queueCopy);
    }
    print_statistics();
    reset_global_statistics();
}

/*
 Call your scheduling algorithms here.
 */
void run_schedulers(struct ready_queue runningQueue)
{
    run_one_scheduler(&schedule_fcfs, runningQueue);
    run_one_scheduler(&schedule_sjf, runningQueue);
    run_one_scheduler(&schedule_SRT, runningQueue);
    run_one_scheduler(&round_robin, runningQueue);
    /*
     struct ready_queue queueFCFS = copy_ready_queue(runningQueue);
     schedule_fcfs(queueFCFS);
     delete_ready_queue(&queueFCFS);
     
     struct ready_queue queueSJF = copy_ready_queue(runningQueue);
     schedule_sjf(queueSJF);
     delete_ready_queue(&queueSJF);
     
     struct ready_queue queueSRT = copy_ready_queue(runningQueue);
     schedule_SRT(queueSRT);
     delete_ready_queue(&queueSRT);
     
     struct ready_queue queueRR = copy_ready_queue(runningQueue);
     round_robin(queueRR);
     delete_ready_queue(&queueRR);
     */
    
    //    struct ready_queue queueHPF = copy_ready_queue(runningQueue);
    //    schedule_hpf(queueHPF);
    //    delete_ready_queue(&queueHPF);
}

int main(int argc, const char * argv[])
{
    srand((unsigned int)time(NULL));
    
    
    reset_global_statistics();
    int queueSize = 32;
    struct ready_queue randomQueue = new_ready_queue(queueSize);
    
    sort_ready_queue(&randomQueue);
    set_ready_queue_identifier(&randomQueue);
    print_ready_queue(randomQueue);
    
    run_schedulers(randomQueue);
    delete_ready_queue(&randomQueue);
    return 0;
}
