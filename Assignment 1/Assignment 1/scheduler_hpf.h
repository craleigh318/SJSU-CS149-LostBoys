#ifndef __Assignment_1__scheduler_hpf__
#define __Assignment_1__scheduler_hpf__
#include "system_headers.h"
#include "ready_queue.h"

/*
 Highest priority first scheduling algorithm.
 */
void schedule_hpf(struct ready_queue readyQueue);

/*
 Sending priority queues (all 4) to FCFS
 */
void nonpreemptive(struct ready_queue readyQueue1,struct ready_queue readyQueue2,struct ready_queue readyQueue3,struct ready_queue readyQueue4);

/*
 Sending priority queues (all 4) to Round Robin for 1 quantum
 */

void preemptive(struct ready_queue readyQueue1,struct ready_queue readyQueue2,struct ready_queue readyQueue3,struct ready_queue readyQueue4);

#endif /* defined(__Assignment_1__scheduler_hpf__) */
