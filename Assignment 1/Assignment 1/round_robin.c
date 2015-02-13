/*
 * round_robin.c
 *
 *  Created on: Feb 12, 2015
 *      Author: Saurav
 */


#include "round_robin.h"
#include "helper_functions.h"

void exec_round_robin(struct ready_queue readyQueue)
{
    bool queueIsEmpty = (readyQueue.length <= 0);
    float timeElapsed = 0.0;
    if (queueIsEmpty)
    {
        printf("\nQueue is empty! Please enlarge queue next time.\n");
    }
    else {
    	int i = 0;
    	int done = 0;
    	printf("There are %d elements in the queue!\n", readyQueue.length);
    	while(timeElapsed < TIME_LIMIT && done < readyQueue.length) {
    		if(i == readyQueue.length) {
    			i = 0;
    		}
    		if(readyQueue.processes[i].expectedRunTime > 0.0) {
    			readyQueue.processes[i].expectedRunTime--;
    			timeElapsed++;
    			printf("P%d ", i+1);
    		}
    		else {
    			done++;
    		}
    		 i++;
    	}
    	printf("\nTime elapsed: %f....%d process(es) were completed", timeElapsed, done);
    }
}

void round_robin(struct ready_queue readyQueue)
{
    printf("\nRound Robin:\n");
    exec_round_robin(readyQueue);
}

