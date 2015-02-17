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
#include "scheduler_hpf.h"
#include "round_robin.h"
#include "global_statistics.h"
#include "helper_functions.h"

static struct ready_queue trials[5];

void print_simulated_process(struct simulated_process printingProcess)
{
    printf("Arrival Time: %f\nExpected Run Time: %f\nPriority: %d\n", printingProcess.arrivalTime,
           printingProcess.expectedRunTime, printingProcess.priority);
}

void print_ready_queue(int j)
{
    int queueSize = trials[j].length;
    int i = 0;
    while (i < queueSize)
    {
        printf("Process %d (Trial %d):\n", (i + 1), (j + 1));
        print_simulated_process(trials[j].processes[i]);
        printf("\n");
        ++i;
    }
}

void print_statistics()
{
    
    int throughput = globalStatistics.throughput / NUM_TRIALS;
    float avgTurnaround = globalStatistics.turnaround_time / (float)NUM_TRIALS / throughput;
    float avgWaitTime = globalStatistics.waiting_time / (float)NUM_TRIALS / throughput;
    float avgResponse = globalStatistics.response_time / (float)NUM_TRIALS / throughput;
    printf("\nAvg. Turnaround Time: %f\nAvg. Wait Time: %f\nAvg. Response Time: %f\nAvg. Throughput: %d\n\n",
           avgTurnaround, avgWaitTime, avgResponse, throughput);
}

void run_one_scheduler(void (* scheduler_name)(struct ready_queue))
{
    int i = 0;
    while (i < NUM_TRIALS)
    {
        scheduler_name(trials[i]);
        ++i;
    }
    print_statistics();
    reset_global_statistics();
}

/*
 Call your scheduling algorithms here.
 */
void run_schedulers()
{
    run_one_scheduler(&schedule_fcfs);
    run_one_scheduler(&schedule_sjf);
    run_one_scheduler(&schedule_SRT);
    run_one_scheduler(&round_robin);
    run_one_scheduler(&schedule_hpf);
}

int main(int argc, const char * argv[])
{
    // Test 
    srand((unsigned int)time(NULL));
    reset_global_statistics();
    int i;
    for (i = 0; i < NUM_TRIALS; ++i)
    {
        trials[i] = new_ready_queue(queueSize);
        sort_ready_queue(&trials[i]);
        set_ready_queue_identifier(&trials[i]);
        print_ready_queue(i);
    }
    run_schedulers();
    return 0;
}
