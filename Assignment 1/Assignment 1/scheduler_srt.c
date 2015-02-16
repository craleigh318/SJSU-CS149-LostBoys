#include "scheduler_srt.h"

typedef struct List {
	int length;

	struct simulated_process * processes;

} List;

List init_list(int length) {
	List retList;
	retList.length = 0;
	retList.processes = malloc(length * sizeof(struct simulated_process));

	return retList;
}

void delete_list(List* delList) {
	free(delList->processes);
}

void copy_simulated_process(struct simulated_process* a, struct simulated_process* b) {
	a->arrivalTime = b->arrivalTime;
	a->expectedRunTime = b->expectedRunTime;
	a->priority = b->priority;
}

void push_process_to_list(List* passQueue, struct simulated_process a) {
	passQueue->processes[passQueue->length] = a;
	passQueue->length++;
}

void schedule_SRT(struct ready_queue readyQueue) {
	int curr_time = 0;
	int time_slice = 1;
	int curr_identifier = -1;
	List runningList = init_list(readyQueue.length);
	List completedList = init_list(readyQueue.length);

	puts("Shortest Remaining Time:");
	printf("Time Line: ");

	while(curr_time < TIME_LIMIT && completedList.length < readyQueue.length) {
		if(readyQueue.processes[0].arrivalTime < curr_time) {
			push_process_to_list(&runningList, readyQueue.processes[0]);
			readyQueue.processes++;
			readyQueue.length--;
			quick_sort_run_time(runningList.processes, 0, runningList.length - 1);
		}
		if(runningList.length > 0) {
			runningList.processes[0].expectedRunTime -= time_slice;
			if(curr_identifier != runningList.processes[0].identifier)
				printf("P%i ", runningList.processes[0].identifier);
			if(runningList.processes[0].identifier != 0)
				curr_identifier = runningList.processes[0].identifier;
			if(runningList.processes[0].expectedRunTime < 0){
				push_process_to_list(&completedList, runningList.processes[0]);
				runningList.processes++;
				runningList.length--;
			}
		}
		curr_time++;
	}

	printf("\n");

	//delete_list(&runningList);
	//delete_list(&completedList);
}
