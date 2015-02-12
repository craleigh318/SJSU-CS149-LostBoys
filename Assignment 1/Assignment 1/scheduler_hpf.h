#include "simulated_process.h"
#include "scheduler_hpf.h"

void schedule_hpf(struct ready_queue readyQueue) {
	// 1st sort simulated processes in arrival time order - using Bubblesort
	int out, in;
	int queueSize = 26;
	struct ready_queue sorted = runningQueue; // Store runningQueue parameter into the sorted variable 
	for (out = 0; out < sorted.length; out++) {
		for (in = 0; in < sorted.length - 1; in++) {
			if (sorted[in].simulated_process.arrivalTime
					> sorted[out + 1].simulated_process.arrivalTime) {
				struct ready_queue arrival = sorted[in + 1];
				sorted[in + 1] = sorted[out];
				sorted[out] = arrival;
			}
		}
	}

	// 2nd create 4 priority queues label 1-4 priority && empty everything in it with 1 - highest 
	struct ready_queue priority1 = new_ready_queue(queueSize);
	struct ready_queue priority2 = new_ready_queue(queueSize);
	struct ready_queue priority3 = new_ready_queue(queueSize);
	struct ready_queue priority4 = new_ready_queue(queueSize);

	// 3rd With 'sort' completed, take the 1st element/process from sort, determine its priority and place it into the matching priority queue.   

	for (int i = 0; i <= queueSize; i++) // Go through entire sort 
			{
		if (sorted[i].process.priority == 1) // Get the process within the sort and see if the process's priority matches the priority's queue number  
				{
			priority1.add(sort[i]); // if their process's priority number is equal to 1, then add that process into the priority1 queue 
			sorted.remove(sorted[i]); // Since that priority is placed into the priority1 queue , remove it from the sort queue 
		} else if (sorted[i].process.priority == 2) {
			priority2.add(sorted[i]);
			sorted.remove(sorted[i]);
		} else if (sorted[i].process.priority == 3) {
			priority3.add(sorted[i]);
			sorted.remove(sorted[i]);
		} else // else the process's priority is 4
		{
			priority4.add(sorted[i]);
			sorted.remove(sorted[i]);
		}
	}
}

void preemptive(struct ready_queue readyQueue) {
// preemptive scheduling , use RR with a time slice of 1 quantum for each priority queue
}
void nonpreemptive(struct ready_queue readyQueue) {
// nonpreemptive scheduling , use FCFS
}
