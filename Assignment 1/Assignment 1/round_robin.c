/*
 * round_robin.c
 *
 *  Created on: Feb 12, 2015
 *      Author: Saurav
 */


#include "round_robin.h"
#include "helper_functions.h"

int next_process(struct ready_queue readyQueue, float timeElapsed, int index) {
	int i = index+1;
	while(i != index) {
		if(i == readyQueue.length)
		   i = 0;
		else {
			if(readyQueue.processes[i].expectedRunTime > 0.0 && readyQueue.processes[i].arrivalTime < timeElapsed)
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
	if(readyQueue.processes[index].expectedRunTime > 0.0 && readyQueue.processes[index].arrivalTime < timeElapsed)
		return 1;
	else
		return 0;
}

int ready_processes(struct ready_queue readyQueue, float timeElapsed) {
	int i;
	int readyProcesses = 0;
	for(i = 0; i < readyQueue.length; i++){
		if (is_ready(readyQueue, i, timeElapsed)) {
			readyProcesses++;
		}
	}
	return readyProcesses;
}

void flag(struct ready_queue readyQueue, int index) {
	if(is_complete(readyQueue, index))
		readyQueue.processes[index].priority = 0;
}

int is_not_flagged(struct ready_queue readyQueue, int index) {
	if(readyQueue.processes[index].priority == 0)
		return 0;
	else
		return 1;
}

int throughput(struct ready_queue readyQueue) {
	int i;
	int completeProcesses = 0;
	for(i = 0; i < readyQueue.length; i++){
		if (is_complete(readyQueue, i)) {
			completeProcesses++;
		}

	}
	return completeProcesses;
}

void exec_round_robin(struct ready_queue readyQueue) {
    bool queueIsEmpty = (readyQueue.length <= 0);
    float timeElapsed = 0.0;
    if (queueIsEmpty)
    {
        printf("\nQueue is empty! Please enlarge queue next time.\n");
    }
    else {
    	int i = 0;
    	float totalWait = 0;
    	float totalTurnAround = 0;
    	float avgWait = 0;
    	float avgTurnaround = 0;
    	printf("Time Line:\n");
    	while(timeElapsed < TIME_LIMIT && throughput(readyQueue) < readyQueue.length) {

    		if(is_ready(readyQueue, i, timeElapsed)) {
    			readyQueue.processes[i].expectedRunTime--;
    			totalWait += ((ready_processes(readyQueue, timeElapsed) - 1) - throughput(readyQueue));
       			printf("P%d-", i+1);
    		}
    		else if (is_complete(readyQueue, i) && is_not_flagged(readyQueue, i)){
    			totalTurnAround += (timeElapsed - readyQueue.processes[i].arrivalTime);
    			flag(readyQueue, i);
    		}
    		i = next_process(readyQueue, timeElapsed, i);
    		timeElapsed++;
    	}
    	avgWait = totalWait/ready_processes(readyQueue, timeElapsed);
    	avgTurnaround = totalTurnAround/throughput(readyQueue);
    	printf("\n\nAverage Waiting Time: %f"
    			"\nAverage Turnaround Time: %f"
    			"\nThroughput: %d processes were completed"
    			"\n\n%f quantas have elapsed",
				avgWait, avgTurnaround, throughput(readyQueue),timeElapsed);
    }
}

void round_robin(struct ready_queue readyQueue) {
    printf("\nRound Robin ");
    exec_round_robin(readyQueue);
}

