#include "simulated_process.h"
#include "scheduler_hpf.h"

void schedule_hpf(struct ready_queue readyQueue) {
    // 1st sort simulated processes in arrival time order - using Bubblesort
    int out, in;
    int queueSize = 26;
    struct ready_queue sorted = readyQueue; // Store runningQueue parameter into the sorted variable
    for (out = 0; out < sorted.length; out++) {
        for (in = 0; in < sorted.length - 1; in++) {
            if (sorted.processes[in].arrivalTime
                > sorted.processes[out + 1].arrivalTime) {
                struct simulated_process arrival = sorted.processes[in + 1];
                sorted.processes[in + 1] = sorted.processes[out];
                sorted.processes[out] = arrival;
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
        if (sorted.processes[i].priority == 1) // Get the process within the sort and see if the process's priority matches the priority's queue number
        {
            //priority1.add(sort[i]); // if their process's priority number is equal to 1, then add that process into the priority1 queue
            //sorted.remove(sorted[i]); // Since that priority is placed into the priority1 queue , remove it from the sort queue
        } else if (sorted.processes[i].priority == 2) {
            //priority2.add(sorted[i]);
            //sorted.remove(sorted[i]);
        } else if (sorted.processes[i].priority == 3) {
            //priority3.add(sorted[i]);
            //sorted.remove(sorted[i]);
        } else // else the process's priority is 4
        {
            //priority4.add(sorted[i]);
            //sorted.remove(sorted[i]);
        }
    }
    
    // 4th, once the priority queues are sorted in their respective queue
    // Send all the queues to the preemptive [FCFS] & nonpreemptive[
}

// preemptive scheduling , use RR with a time slice of 1 quantum for each priority queue
void preemptive(struct ready_queue readyQueue1,struct ready_queue readyQueue2,struct ready_queue readyQueue3,struct ready_queue readyQueue4) {
	// send the highest priority queue - which in this case is 1 - to method exec_round_robin(struct ready_queue readyQueue)
	// one at a time and then send the next priority queue - which is 2 - and keep going until we reach the lowest priority queue - 4
	//		exec_round_robin(readyQueue1);
	//		exec_round_robin(readyQueue2);
	//		exec_round_robin(readyQueue3);
	//		exec_round_robin(readyQueue4);
}

// nonpreemptive scheduling , use FCFS
void nonpreemptive(struct ready_queue readyQueue1,struct ready_queue readyQueue2,struct ready_queue readyQueue3,struct ready_queue readyQueue4)
{
	// send the highest priority queue - which in this case 1 - to method schedule_fcfs(struct ready_queue readyQueue)
	// Then send the next priority queue - which is 2 - and keep going until we reach the lowest priority queue - 4
	//		schedule_fcfs(readyQueue1);
	//		schedule_fcfs(readyQueue2);
	//		schedule_fcfs(readyQueue3);
	//		schedule_fcfs(readyQueue4);
}
