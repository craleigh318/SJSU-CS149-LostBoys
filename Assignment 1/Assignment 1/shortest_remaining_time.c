#include "shortest_remaining_time.h"

typedef struct List {
	int length;

	struct simulated_process * processes;

} List;

List init_list(int length) {
	List retList;
	retList.length = 0;

	return retList;
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
	List runningList = init_list(readyQueue.length);
	List completedList = init_list(readyQueue.length);

//	push_process_to_list(&runningList, readyQueue.processes[0]);
//
//	push_process_to_list(&runningList, readyQueue.processes[1]);
//
//	push_process_to_list(&runningList, readyQueue.processes[2]);
//
//	push_process_to_list(&runningList, readyQueue.processes[3]);

//	struct simulated_process currProcess = readyQueue.processes[0];
//	push_process_to_list(&runningList, currProcess);
//
//	struct simulated_process currProcess = readyQueue.processes[0];
//	push_process_to_list(&runningList, currProcess);
//
//	struct simulated_process currProcess = readyQueue.processes[0];
//	push_process_to_list(&runningList, currProcess);
//
//	struct simulated_process currProcess = readyQueue.processes[0];
//	push_process_to_list(&runningList, currProcess);


//	for(int i = 0; i < 4; i++){
//		printf("length: %i   arrival: %f   expected:%f   pri:%i\n",
//				runningList.length,
//				runningList.processes[i].arrivalTime,
//				runningList.processes[i].expectedRunTime,
//				runningList.processes[i].priority);
//	}

	while(curr_time < TIME_LIMIT) {
		if(readyQueue.processes[0].arrivalTime < curr_time &&
				readyQueue.length > 0) {
			push_process_to_list(&runningList, readyQueue.processes[0]);
			readyQueue.processes++;
			readyQueue.length--;
			quick_sort_run_time(runningList.processes, 0, runningList.length - 1);
		}
		//runningList.processes[0].expectedRunTime -= 1;
		curr_time++;
	}

	for(int i = 0; i < runningList.length; i++){
		printf("length: %i   arrival: %f   expected:%f   pri:%i\n",
				runningList.length,
				runningList.processes[i].arrivalTime,
				runningList.processes[i].expectedRunTime,
				runningList.processes[i].priority);
	}
}
