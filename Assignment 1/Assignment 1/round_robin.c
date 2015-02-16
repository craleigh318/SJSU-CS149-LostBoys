/*
 * round_robin.c
 *
 *  Created on: Feb 12, 2015
 *      Author: Saurav
 */

#include "round_robin.h"
#include "helper_functions.h"
#include "scheduler_statistics.h"
#include "global_statistics.h"


int next_process(struct ready_queue readyQueue, float timeElapsed, int index) {
    int i = index+1;
    while(i != index) {
        if(i == readyQueue.length)
            i = 0;
        else {
            if(readyQueue.processes[i].expectedRunTime > 0.0 && readyQueue.processes[i].arrivalTime <= timeElapsed)
                return i;
            i++;
        }
    }
    return i;
}

int is_complete(struct ready_queue readyQueue, int index) {
    if (readyQueue.processes[index].expectedRunTime <= 0.0)
        return 1;
    else
        return 0;
}

int is_ready(struct ready_queue readyQueue, int index, float timeElapsed) {
    if(readyQueue.processes[index].expectedRunTime > 0.0 && readyQueue.processes[index].arrivalTime <= timeElapsed)
        return 1;
    else
        return 0;
}

int ready_processes(struct ready_queue readyQueue, float timeElapsed) {
    int i;
    int readyProcesses = 0;
    for(i = 0; i < readyQueue.length; i++){
        if (is_ready(readyQueue, i, timeElapsed))
            readyProcesses++;
    }
    return readyProcesses;
}

int throughput(struct ready_queue readyQueue) {
    int i;
    int completeProcesses = 0;
    for(i = 0; i < readyQueue.length; i++){
        if (is_complete(readyQueue, i))
            completeProcesses++;
    }
    return completeProcesses;
}

void exec_round_robin(struct ready_queue readyQueue, struct scheduler_statistics statistics) {
    int size = readyQueue.length;
    int currentProcess;
    int prevProcess = -1;
    bool queueIsEmpty = (readyQueue.length <= 0);
    float timeElapsed = 0;
    if (queueIsEmpty)
    {
        printf("\nQueue is empty! Please enlarge queue next time.\n");
    }
    else {
        int i = 0;
        float totalWait = 0;
        float totalTurnAround = 0.0;
        float totalResponseTime = 0.0;
        
        int completedFlag[readyQueue.length];
        memset(completedFlag, 0, readyQueue.length);
        
        int visitedFlag[readyQueue.length];
        memset(visitedFlag, 0, readyQueue.length);
        
        printf("\nTime Line: ");
        while(timeElapsed < TIME_LIMIT && throughput(readyQueue) < size) {
            
            if(is_ready(readyQueue, i, timeElapsed)) {
                totalWait += (ready_processes(readyQueue, timeElapsed) - 1);
                readyQueue.processes[i].expectedRunTime--;
                
                if(readyQueue.processes[i].flagVisited == 0) {
                    totalResponseTime += (timeElapsed - readyQueue.processes[i].arrivalTime);
                    readyQueue.processes[i].flagVisited = 1;
                }
            }
            timeElapsed += 1.0;
            if (is_complete(readyQueue, i) && readyQueue.processes[i].flagComplete == 0){
                totalTurnAround += (timeElapsed - readyQueue.processes[i].arrivalTime);
                readyQueue.processes[i].flagComplete = 1;
            }
            
            currentProcess = readyQueue.processes[i].identifier;
            
            i = next_process(readyQueue, timeElapsed, i);
            
            if(currentProcess != prevProcess)
            {
                printf("P%d ", currentProcess);
                prevProcess = currentProcess;
            }
        }
        printf("\n");
        statistics.waiting_time = totalWait/size;
        statistics.turnaround_time = totalTurnAround/size;
        statistics.response_time = totalResponseTime/size;
        statistics.throughput = throughput(readyQueue);
        add_to_global_statistics(statistics);
        //printf("\n%f quanta have elapsed\n", timeElapsed);
    }
}

void round_robin(struct ready_queue readyQueue) {
    printf("\nRound Robin ");
    exec_round_robin(readyQueue, new_scheduler_statistics());
}

