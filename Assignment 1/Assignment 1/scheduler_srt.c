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

int partition_run_time(struct simulated_process * a, int l, int r) {
    float pivot;
    struct simulated_process t;
    int i, j;
    pivot = a[l].expectedRunTime;
    i = l;
    j = r + 1;

    while (1) {
        do
            ++i;
        while (a[i].expectedRunTime <= pivot && i <= r);
        do
            --j;
        while (a[j].expectedRunTime > pivot);
        if (i >= j)
            break;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    t = a[l];
    a[l] = a[j];
    a[j] = t;
    return j;
}

void quick_sort_run_time(struct simulated_process * a, int l, int r) {
    int j;

    if (l < r) {
        j = partition_run_time(a, l, r);
        quick_sort_run_time(a, l, j - 1);
        quick_sort_run_time(a, j + 1, r);
    }
}

void schedule_SRT(struct ready_queue readyQueue) {
	int curr_time = 0;
	int time_slice = 1;
	List runningList = init_list(readyQueue.length);
	List completedList = init_list(readyQueue.length);

	while(curr_time < TIME_LIMIT && completedList.length < readyQueue.length) {
		if(readyQueue.processes[0].arrivalTime < curr_time) {
			push_process_to_list(&runningList, readyQueue.processes[0]);
			readyQueue.processes++;
			readyQueue.length--;
			quick_sort_run_time(runningList.processes, 0, runningList.length - 1);
		}
		if(runningList.length > 0) {
			runningList.processes[0].expectedRunTime -= time_slice;
			if(runningList.processes[0].expectedRunTime < 0){
				push_process_to_list(&completedList, runningList.processes[0]);
				runningList.processes++;
				runningList.length--;
			}
		}
		curr_time++;
	}

	puts("Running List");
	for(int i = 0; i < runningList.length; i++){
		printf("length: %i   arrival: %f   expected:%f   pri:%i\n",
				runningList.length,
				runningList.processes[i].arrivalTime,
				runningList.processes[i].expectedRunTime,
				runningList.processes[i].priority);
	}

	puts("Completed List");
	for(int i = 0; i < completedList.length; i++){
		printf("length: %i   arrival: %f   expected:%f   pri:%i\n",
				completedList.length,
				completedList.processes[i].arrivalTime,
				completedList.processes[i].expectedRunTime,
				completedList.processes[i].priority);
	}

	printf("\n");

	delete_list(runningList);
	delete_list(completedList);
}
