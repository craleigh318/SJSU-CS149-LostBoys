#include "simulated_process.h"
#include "scheduler_hpf.h"
#include "ready_queue.h"
#include "round_robin.h"
#include "scheduler_fcfs.h"

void schedule_hpf(struct ready_queue readyQueue) {
    printf("\nHighest Priority First:\n");
    // 1st create 4 priority queues label 1-4 priority && empty everything in it. 1 = Highest
    struct ready_queue priority1 = new_ready_queue(0);
    // Initialize priority1 with some generated simulated process
    // We have to get rid of the randomly generated process to nothing
    struct ready_queue priority2 = new_ready_queue(0);
    struct ready_queue priority3 = new_ready_queue(0);
    struct ready_queue priority4 = new_ready_queue(0);
   
    for (int i = 0; i <= readyQueue.length; i++) // Go through entire sort
    {
        if (readyQueue.processes[i].priority == 1) // Get the process within the sort and see if the process's priority matches the priority's queue number
        {
             add_ready_queue_process(&priority1, readyQueue.processes[i]); // if their process's priority number is equal to 1, then add that process into the priority1 queue
            //remove_ready_queue_process(&readyQueue, i); // Since that priority is placed into the priority1 queue , remove it from the sort queue
        } else if (readyQueue.processes[i].priority == 2) {
            add_ready_queue_process(&priority2, readyQueue.processes[i]);
            //remove_ready_queue_process(&readyQueue, i);
        } else if (readyQueue.processes[i].priority == 3) {
            add_ready_queue_process(&priority3, readyQueue.processes[i]);
            //remove_ready_queue_process(&readyQueue, i);
        } else // else the process's priority is 4
        {
            add_ready_queue_process(&priority4, readyQueue.processes[i]);
            //remove_ready_queue_process(&readyQueue, i);
        }
    }
    
    // 3rd after processes are sorted into their priority queue based on their priority number
    // Send the new priority queues to the preemptive (Round robin) & nonpreemptive (FCFS) methods.
    preemptive(priority1, priority2, priority3, priority4);
    nonpreemptive(priority1, priority2, priority3, priority4);
}

void preemptive(struct ready_queue readyQueue1,struct ready_queue readyQueue2,struct ready_queue readyQueue3,struct ready_queue readyQueue4) {
    // send the highest priority queue - which in this case is 1 - to method exec_round_robin(struct ready_queue readyQueue)
    // one at a time and then send the next priority queue - which is 2 - and keep going until we reach the lowest priority queue - 4
    round_robin(readyQueue1);
    round_robin(readyQueue2);
    round_robin(readyQueue3);
    round_robin(readyQueue4);
}

void nonpreemptive(struct ready_queue readyQueue1,struct ready_queue readyQueue2,struct ready_queue readyQueue3,struct ready_queue readyQueue4)
{
    // send the highest priority queue - which in this case 1 - to method schedule_fcfs(struct ready_queue readyQueue)
    // Then send the next priority queue - which is 2 - and keep going until we reach the lowest priority queue - 4
    schedule_fcfs(readyQueue1);
    schedule_fcfs(readyQueue2);
    schedule_fcfs(readyQueue3);
    schedule_fcfs(readyQueue4);
}
