 
 // Job: highest priority first (HPF) both nonpreemptive and preemptive
 
// Assume only one CPU and one ready queue. Sort the simulated processes so that they
// enter the queue in arrival time order. Your process scheduler can do process switching
// only at the start of each time quantum. For this assignment, only consider CPU time for
// each process (no I/O wait times, no process switching overhead).

// For preemptive scheduling, use RR with a time slice of 1 quantum for each
// priority queue. 

#include "ready_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>


int main(int argc, const char * argv[])
{
    srand((unsigned int)time(NULL));
	int time = 0; // Starts at 0 time to allow our algorithm to run 5 times
	while(time != 5) // Ends at 5 times 
		{
    int queueSize = 100; // queueSize
	// This is the one generating the simulated_process 
    struct ready_queue randomQueue = new_ready_queue(queueSizeA); // This is the one ready queue 
	print_ready_queue(randomQueue);
    run_schedulers(randomQueue); // Where HPF happens
    delete_ready_queue(&randomQueue); // Deallocate memory
	quanta++;
		}
    return 0;
}
// Each created process's name ( such as A,B,C ...) , arrival time, expected run time, and priority 
void print_simulated_process(struct simulated_process printingProcess)
{
    printf("Arrival Time: %f\nExpected Run Time: %f\nPriority: %d\n", printingProcess.arrivalTime,
           printingProcess.expectedRunTime, printingProcess.priority);
}

void print_ready_queue(struct ready_queue printingQueue)
{
    int i;
    for (i = 0;  i < printingQueue.length; i++)
    {
        printf("Process %c:\n", i + 'A');
        print_simulated_process(printingQueue.processes[i]);
        printf("\n");
    }
}

// Scheduling algorithm here
void run_schedulers(struct ready_queue runningQueue)
{
	// 1st sort simulated processes in arrival time order - using Bubblesort
	int out;
	int in;
	int queueSize = 30; // queueSize
	struct ready_queue copy = new_ready_queue(runningQueue);
	for (out = 0; out < copy.length; out++)
	{
		for (in = 0; in < copy.length-1; in++)
		{
			if(copy[in].simulated_process.arrivalTime > copy[out+1].simulated_process.arrivalTime)
			{
				struct ready_queue arrival = copy[in+1]; 
				copy[in+1] = copy[out];
				copy[out] = arrival;
			}
		}
	}
	
    // 2nd create 4 priority queues from 1-4 priority && clear everything in them but have the ready queue empty 
	struct ready_queue priority1 = new_ready_queue(queueSize); 
    struct ready_queue priority2 = new_ready_queue(queueSize);	
	struct ready_queue priority3 = new_ready_queue(queueSize);
	struct ready_queue priority4 = new_ready_queue(queueSize);
	
	// 3rd from the sorted simulated process in step 1, place them into their respective ready queues 
	
	for(int i = 0; i <= queueSize; i++) // Go through the whole sorted queue from step 1 starting at the beginning index
	{
		if(copy[i].process.priority == 1) // Get the process within the queue and get its priority number 
		{
			priority1.add(copy[i]); // if their priority number is equal to 1, then add that process into the priority1 queue 
			copy.remove(copy[i]); // Since that priority is placed into the priority1 queue , remove it from the copy queue 
		}
		else if(copy[i].process.priority == 2)
		{
			priority2.add(copy[i]);
			copy.remove(copy[i]);
		}
		else if(copy[i].process.priority == 3)
		{
			priority3.add(copy[i]);
			copy.remove(copy[i]);
		}
		else // else the process's priority is 4
		{
			priority4.add(copy[i]); // add that process into priority 4 
			copy.remove(copy[i]);
		}
	}
	
	// 4th calculate statistics for the processes for the run 
	// Average turnaround, waiting, and response time and throughput 
	// Given arrivalTime , expectedRunTime, and priority  
	// arrivalTime with total waiting time? 
	
	
}

