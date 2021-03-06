#include "scheduler_srt.h"
#include "global_statistics.h"

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

void push_process_to_list(List* passQueue, struct simulated_process* a) {
    passQueue->processes[passQueue->length] = *a;
    passQueue->length++;
}

void schedule_SRT(struct ready_queue readyQueuePass) {
    int curr_time = 0;
    int time_slice = 1;
    int curr_identifier = -1;
    struct scheduler_statistics stats = new_scheduler_statistics();
    List runningList = init_list(readyQueuePass.length);
    List completedList = init_list(readyQueuePass.length);
    List readyQueue = init_list(readyQueuePass.length);
    readyQueue.length = readyQueuePass.length;
    int i;
    for(i = 0; i < readyQueue.length; i++) {
    	readyQueue.processes[i] = readyQueuePass.processes[i];
    }
    
    puts("\nShortest Remaining Time:");
    printf("Time Line: ");
    
    while(curr_time < TIME_LIMIT && completedList.length < readyQueue.length) {
        //Puts a process into the ready queue when it arrives
        while(readyQueue.processes[0].arrivalTime < curr_time) {
            push_process_to_list(&runningList, &readyQueue.processes[0]);
            stats.response_time += (curr_time - readyQueue.processes[0].arrivalTime);
            runningList.processes[0].timeEnteredReadyQueue = curr_time;
            readyQueue.processes++;
            readyQueue.length--;
            quick_sort_run_time(runningList.processes, 0, runningList.length - 1);
        }
        //Runs the shortest remaining time process from the ready queue
        if(runningList.length > 0) {
            //Runs the process
            runningList.processes[0].expectedRunTime -= time_slice;
            //Sets the waiting time when the process starts running and stores the time when the process starts running
            if(runningList.processes[0].flagVisited == 0) {
                stats.waiting_time += (curr_time - runningList.processes[0].timeEnteredReadyQueue);
                runningList.processes[0].timeStartsRunning = curr_time;
            }
            //Marks the process as visited
            runningList.processes[0].flagVisited = 1;
            //Print the current running process
            if(curr_identifier != runningList.processes[0].identifier)
                printf("P%i ", runningList.processes[0].identifier);
            //Marks the currently running process so no repeats in time line if the same process is running
            if(runningList.processes[0].identifier != 0)
                curr_identifier = runningList.processes[0].identifier;
            //Process is finished and is moved to the completed list
            if(runningList.processes[0].expectedRunTime < 0){
                push_process_to_list(&completedList, &runningList.processes[0]);
                stats.turnaround_time += (curr_time - completedList.processes[0].timeStartsRunning);
                runningList.processes++;
                runningList.length--;
            }
        }
        curr_time++;
    }
    stats.waiting_time /= (completedList.length + runningList.length);
    stats.turnaround_time /= completedList.length;
    stats.response_time /= (completedList.length + runningList.length);
    stats.throughput = completedList.length;
    add_to_global_statistics(stats);
    puts("");
}
