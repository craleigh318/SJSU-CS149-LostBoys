//
////
////  scheduler_fcfs.c
////  Assignment 1
////
////  Created by Christopher Raleigh on 2015/10/02.
////  Copyright (c) 2015 Lost Boys. All rights reserved.
////
//
//#include "scheduler_fcfs.h"
//#include "helper_functions.h"
//#include "global_statistics.h"
//
//void finish_run(struct scheduler_statistics statistics)
//{
//    add_to_global_statistics(statistics);
//}
//
//void pop_ready_queue(struct ready_queue readyQueue1,struct ready_queue readyQueue2,struct ready_queue readyQueue3,struct ready_queue readyQueue4 struct scheduler_statistics statistics, float timeElapsed)
//{
//    //Do not overrite this algorithm!
//    int numPops = statistics.throughput;
//    bool queueIsEmpty = (numPops >= readyQueue.length);
//    if (queueIsEmpty)
//    {
//        printf("\nQueue is empty! Please enlarge queue next time.\n");
//    }
//    if (queueIsEmpty || (timeElapsed >= TIME_LIMIT))
//    {
//        finish_run(statistics);
//    }
//    else
//    {
//        struct simulated_process nextProcess = readyQueue.processes[numPops];
//        float newTimeElapsed;
//        float nextArrivalTime = nextProcess.arrivalTime;
//        if (nextArrivalTime > timeElapsed)
//        {
//            newTimeElapsed = ceilf(nextArrivalTime);
//            statistics.response_time += (newTimeElapsed - timeElapsed);
//        }
//        else
//        {
//            statistics.turnaround_time += (timeElapsed + nextProcess.expectedRunTime - nextProcess.arrivalTime);
//            statistics.waiting_time += (timeElapsed - nextProcess.arrivalTime);
//            ++statistics.throughput;
//            printf(" P%d", nextProcess.identifier);
//            newTimeElapsed = timeElapsed + nextProcess.expectedRunTime;
//        }
//        pop_ready_queue(readyQueue, statistics, newTimeElapsed);
//    }
//}
//
//void extra_credit_fcfs(struct ready_queue readyQueue1,struct ready_queue readyQueue2,struct ready_queue readyQueue3,struct ready_queue readyQueue4)
//{
//    printf("Extra Credit First Come, First Served:\nTime Line:");
//    pop_ready_queue(readyQueue1, readyQueue2, readyQueue3, readyQueue4, new_scheduler_statistics(), 0.0f);
//}


// This will be updated later today that 3:45 AM life lol 
