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

void swapWithAlgorithm(std::queue<Process *> processQueue,
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
				processQueue.pop();
				printLine = true;
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
}

void swappingStart() {
    std::cout << "Swapping:\n";
    std::queue<Process *> orderedProcesses;
    const int queueSize = 100;
    int i;
    for (i = 0; i < queueSize; ++i) {
        Process * newProcess = new Process();
        newProcess->print();
        std::cout << '\n';
        orderedProcesses.push(newProcess);
    }
    // Put your algorithms here.
    std::cout << "First Fit:\n";
    swapWithAlgorithm(orderedProcesses, &startFirstFitSwapping);

    std::cout << "Next Fit:\n";
    //swapWithAlgorithm(orderedProcesses, &startNextFit);

    std::cout << "Best Fit:\n";
    //swapWithAlgorithm(orderedProcesses, &startBestFit);

    std::cout << "Worst Fit:\n";
    //swapWithAlgorithm(orderedProcesses, &startWorstFit);
    // Deleting processes when done.
    for (i = 0; i < queueSize; ++i) {
        Process * nextProcess = orderedProcesses.front();
        delete nextProcess;
        orderedProcesses.pop();
    }
}
