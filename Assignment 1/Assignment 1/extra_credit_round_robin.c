///*
// * round_robin.c
// *
// *  Created on: Feb 12, 2015
// *      Author: Saurav
// */
//
//#include "round_robin.h"
//#include "helper_functions.h"
//#include "scheduler_statistics.h"
//
//
//int next_process(struct ready_queue readyQueue, float timeElapsed, int index) {
//	int i = index+1;
//	while(i != index) {
//		if(i == readyQueue.length)
//		   i = 0;
//		else {
//			if(readyQueue.processes[i].expectedRunTime > 0.0 && readyQueue.processes[i].arrivalTime <= timeElapsed)
//						return i;
//			i++;
//		}
//	}
//	return i;
//}
//
//int is_complete(struct ready_queue readyQueue, int index) {
//	if (readyQueue.processes[index].expectedRunTime <= 0.0)
//		return 1;
//	else
//		return 0;
//}
//
//int is_ready(struct ready_queue readyQueue, int index, float timeElapsed) {
//	if(readyQueue.processes[index].expectedRunTime > 0.0 && readyQueue.processes[index].arrivalTime <= timeElapsed)
//		return 1;
//	else
//		return 0;
//}
//
//int ready_processes(struct ready_queue readyQueue, float timeElapsed) {
//	int i;
//	int readyProcesses = 0;
//	for(i = 0; i < readyQueue.length; i++){
//		if (is_ready(readyQueue, i, timeElapsed))
//			readyProcesses++;
//	}
//	return readyProcesses;
//}
//
//int throughput(struct ready_queue readyQueue) {
//	int i;
//	int completeProcesses = 0;
//	for(i = 0; i < readyQueue.length; i++){
//		if (is_complete(readyQueue, i))
//			completeProcesses++;
//	}
//	return completeProcesses;
//}
//
//void exec_round_robin(struct ready_queue readyQueue1,struct ready_queue readyQueue2, struct ready_queue readyQueue3, struct ready_queue readyQueue4, struct scheduler_statistics statistics) {
//	int size1 = readyQueue.length; // priority queue 1
//        int size2 = readyQueue2.length; // priority queue 2
//        int size3 = readyQueue3.length;  
//        int size4 = readyQueue4.length;
//	int currentProcess;
//	int prevProcess = -1;
//        bool queueIsEmpty1 = (readyQueue1.length <= 0); // priority queue 1
//        bool queueIsEmpty2 = (readyQueue2.length <= 0);
//        bool queueIsEmpty3 = (readyQueue3.length <= 0);
//        bool queueIsEmpty4 = (readyQueue4.length <= 0);
//        float timeElapsed = 0;
//        if (queueIsEmpty1)
//        {
//            printf("\n Queue1 is empty! Please enlarge queue next time.\n");
//        }
//        else if (queueIsEmpty2)
//        {
//            printf("\n Queue2 is empty! Please enlarge queue next time.\n");
//        }
//        else if (queueIsEmpty3)
//        {
//            printf("\n Queue3 is empty! Please enlarge queue next time.\n");
//        }
//        else if (queueIsEmpty4)
//        {
//            printf("\n Queue4 is empty! Please enlarge queue next time.\n");
//        }
//        else 
//        {
//            
//    	int i = 0;
//    	float totalWait = 0;
//    	float totalTurnAround = 0.0;
//    	float totalResponseTime = 0.0;
//
//    	int completedFlag1[readyQueue1.length]; // Queue 1 
//    	memset(completedFlag1, 0, readyQueue1.length);
//
//    	int visitedFlag1[readyQueue1.length];
//    	memset(visitedFlag1, 0, readyQueue1.length);
//        
//        int completedFlag2[readyQueue2.length]; // Queue 2 
//    	memset(completedFlag2, 0, readyQueue2.length);
//
//    	int visitedFlag2[readyQueue2.length];
//    	memset(visitedFlag2, 0, readyQueue2.length);
//        
//        int completedFlag3[readyQueue3.length]; // Queue 3 
//    	memset(completedFlag3, 0, readyQueue3.length);
//
//    	int visitedFlag3[readyQueue3.length];
//    	memset(visitedFlag3, 0, readyQueue3.length);
//        
//        int completedFlag4[readyQueue4.length]; // Queue 4 
//    	memset(completedFlag4, 0, readyQueue4.length);
//
//    	int visitedFlag4[readyQueue4.length];
//    	memset(visitedFlag4, 0, readyQueue4.length);
//
//    	printf("Time Line:\n");
//    	while(timeElapsed < TIME_LIMIT && throughput(readyQueue) < size) {
//
//    		if(is_ready(readyQueue, i, timeElapsed)) {
//    			totalWait += (ready_processes(readyQueue, timeElapsed) - 1);
//    			readyQueue.processes[i].expectedRunTime--;
//
//    			if(readyQueue.processes[i].flagVisited == 0) {
//    				totalResponseTime += (timeElapsed - readyQueue.processes[i].arrivalTime);
//    				readyQueue.processes[i].flagVisited = 1;
//    			}
//    		}
//    		timeElapsed += 1.0;
//    		if (is_complete(readyQueue, i) && readyQueue.processes[i].flagComplete == 0){
//    			totalTurnAround += (timeElapsed - readyQueue.processes[i].arrivalTime);
//    			readyQueue.processes[i].flagComplete = 1;
//    		}
//
//    		currentProcess = readyQueue.processes[i].identifier; Meaning, I will take a process that has waited 5 quantas and move it up
//                // to priority 3 and if that same process waits another 5 quantas, go to priority 2 then 1 
//
//    		i = next_process(readyQueue, timeElapsed, i);
//
//    		if(currentProcess != prevProcess)
//    		{
//    			printf("P%d-", currentProcess);
//    			prevProcess = currentProcess;
//    		}
//                
//                // This is where the aging comes in, since instructions about extra credit were unclear.
//                // I'm just going to randomly pick a process from the lowest priority - 4 - queue and place it
//                // into the next priority queue - 3 - if it's waiting time is 5 quantas or more. 
//                
//                // There will be modifications to this code later today.
//                // That 3:45 a.m. life lol
//                
//    	}
//    	statistics.waiting_time = totalWait/size;
//    	statistics.turnaround_time = totalTurnAround/size;
//    	statistics.response_time = totalResponseTime/size;
//    	printf("\n\nAverage Waiting Time: %f"
//    			"\nAverage Turnaround Time: %f"
//    			"\nAverage Response Time: %f"
//    			"\nThroughput: %d processes were completed"
//    			"\n\n%f quantas have elapsed\n",
//				statistics.waiting_time, statistics.turnaround_time, statistics.response_time, throughput(readyQueue),timeElapsed);
//    }
//}
//
//void extra_credit_round_robin(struct ready_queue readyQueue1,struct ready_queue readyQueue2,struct ready_queue readyQueue3,struct ready_queue readyQueue4) {
//    printf("\n Extra Credit Round Robin ");
//    exec_round_robin(readyQueue, new_scheduler_statistics());
//}
//
//
