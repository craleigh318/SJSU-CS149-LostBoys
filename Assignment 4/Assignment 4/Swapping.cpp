//
//  Swapping.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/08/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Swapping.h"

/*bool CompareProcesses::operator()(Process * process1, Process * process2) {
    return (process1->getArrivalTime() > process2->getArrivalTime());
}*/

int swapWithAlgorithm(std::queue<Process *> processQueue,
                       bool (* algorithm)(MainMemory * memory, Process * process)) {
    MainMemory memory;
    int currentTime;
    for (currentTime = 0; currentTime < TIME_LIMIT; ++currentTime) {
        bool processAdded = true;
        bool printLine = false;
        while(processAdded) {
            Process * nextProcess = processQueue.front();
        	processAdded = algorithm(&memory, nextProcess);
			if (processAdded) {
				nextProcess->setTimeAdded(currentTime);
				std::cout << "Added process " << nextProcess->getName() << "\n";
				processQueue.pop();
				printLine = true;
                memory.incrementProcessAdded(1);
			}
        }
        if(printLine) {
			std::cout << "Second " << currentTime << '\n';
			memory.print();
			std::cout << '\n';
        }
        printLine = false;
        std::vector<Partition> allProcess = Partition::getPartitionsInMemoryWithProcesses(&memory);
        for(std::vector<Process*>::size_type i = 0; i != allProcess.size(); i++) {
        	if(allProcess[i].getProcess()->getDuration() + allProcess[i].getProcess()->getTimeAdded() == currentTime) {
        		std::cout << "Removed process " << allProcess[i].getProcess()->getName() << "\n";
        		allProcess[i].removeProcess();
        		printLine = true;
        	}
        }
        if(printLine) {
            std::cout << "Second " << currentTime << '\n';
            memory.print();
            std::cout << '\n';
        }
    }
    std::cout << "Number of processes added " << memory.getProcessAdded() << '\n';
    return memory.getProcessAdded();
}

void swappingStart() {
    std::cout << "Swapping:\n";
    const int executeTimes = 5;
    std::queue<Process *> orderedProcesses[executeTimes];
    const int queueSize = 200;
    int i;
    for (int j = 0; j < executeTimes; j++) {
    	for(i = 0; i < queueSize; i++){
			Process * newProcess = new Process();
			newProcess->print();
			std::cout << '\n';
			orderedProcesses[j].push(newProcess);
    	}
    	Process::resetNameCounter();
    }

    // Put your algorithms here.
    int avgProcessInMemory = 0;
    std::cout << "First Fit:\n";
    for(int i = 0; i < executeTimes; i++)
    	avgProcessInMemory += swapWithAlgorithm(orderedProcesses[i], &startFirstFitSwapping);
    std::cout << "First Fit Average number of processes: " << avgProcessInMemory / executeTimes;

    avgProcessInMemory = 0;
    std::cout << "Next Fit:\n";
    for(int i = 0; i < executeTimes; i++)
    	avgProcessInMemory += swapWithAlgorithm(orderedProcesses[i], &startNextFit);
    std::cout << "Next Fit Average number of processes: " << avgProcessInMemory / executeTimes;

    avgProcessInMemory = 0;
    std::cout << "Best Fit:\n";
    for(int i = 0; i < executeTimes; i++)
    	avgProcessInMemory += swapWithAlgorithm(orderedProcesses[i], &startBestFit);
    std::cout << "Best Fit Average number of processes: " << avgProcessInMemory / executeTimes;

    avgProcessInMemory = 0;
    std::cout << "Worst Fit:\n";
    for(int i = 0; i < executeTimes; i++)
    	avgProcessInMemory += swapWithAlgorithm(orderedProcesses[i], &startWorstFit);
    std::cout << "Worst Fit Average number of processes: " << avgProcessInMemory / executeTimes;

    // Deleting processes when done.
    for (int j = 0; j < executeTimes; j++) {
    	for(i = 0; i < queueSize; i++) {
			Process * nextProcess = orderedProcesses[j].front();
			delete nextProcess;
			orderedProcesses[j].pop();
    	}
    }
}
