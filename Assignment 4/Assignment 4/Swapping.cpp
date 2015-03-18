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
                       bool (* algorithm)(MainMemory * memory, Process * process),
                       bool useMemoryCompaction) {
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
        //Perform memory compaction
        if(useMemoryCompaction && currentTime == TIME_LIMIT / 2) {
        	std::cout << "Start Compaction\n";
        	std::vector<Partition> holes = Partition::getHolesInMemory(&memory);
        	int nextProcess = 0;
        	int processSize = Partition::getPartitionsInMemoryWithProcesses(&memory).size();
        	// Loop while there are more than one holes, the last hole isn't in the last position
        	while(holes.size() != 1 && holes[holes.size() -1].getFinalMB() != 100 && nextProcess < processSize) {
        		std::vector<Partition> allProcess = Partition::getPartitionsInMemoryWithProcesses(&memory);
        		// If the process is already in the front position of memory
        		if(allProcess[nextProcess].getFirstMB() == 0) {
        			nextProcess++;
        		}
        		// If the process is directly in front of a process
        		else if(nextProcess - 1 >= 0 && allProcess[nextProcess].getFirstMB() == allProcess[nextProcess - 1].getFinalMB() + 1){
        			nextProcess++;
        		}
        		else {
        			holes[0].movePartition(&allProcess[nextProcess]);
        			nextProcess++;
        		}
        		holes = Partition::getHolesInMemory(&memory);
        	}
        	std::cout << "After Compaction\n";
        	memory.print();
        }
    }
    std::cout << "Number of processes added " << memory.getProcessAdded() << '\n';
    return memory.getProcessAdded();
}

void swappingStart() {
    std::cout << "Swapping:\n";
    const int executeTimes = 5;
    std::queue<Process *> orderedProcesses[executeTimes];
    const int queueSize = 100;
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
    int compactionAvgProcessInMemory = 0;
    for(int i = 0; i < executeTimes; i++) {
    	std::cout << "\nFirst Fit Run " << i + 1 << ":\n";
    	avgProcessInMemory += swapWithAlgorithm(orderedProcesses[i], &startFirstFitSwapping, false);
    	std::cout << "\nFirst Fit w/ Compaction Run " << i + 1 << ":\n";
    	compactionAvgProcessInMemory += swapWithAlgorithm(orderedProcesses[i], &startFirstFitSwapping, true);
    }
    std::cout << "First Fit Average number of processes: " << avgProcessInMemory / executeTimes << "\n";
    std::cout << "First Fit w/ Compaction Average number of processes: " << compactionAvgProcessInMemory / executeTimes << "\n";
    std::cout << "Memory compaction yielded in " <<
    		(compactionAvgProcessInMemory / executeTimes) - (avgProcessInMemory / executeTimes) <<
    		" process swapped than without memory compaction\n";

    avgProcessInMemory = compactionAvgProcessInMemory = 0;
    for(int i = 0; i < executeTimes; i++) {
    	std::cout << "\nNext Fit Run" << i + 1 << ":\n";
    	avgProcessInMemory += swapWithAlgorithm(orderedProcesses[i], &startNextFit, false);
    	std::cout << "\nNext Fit w/ Compaction Run " << i + 1 << ":\n";
    	compactionAvgProcessInMemory += swapWithAlgorithm(orderedProcesses[i], &startNextFit, true);
    }
    std::cout << "Next Fit Average number of processes: " << avgProcessInMemory / executeTimes << "\n";
    std::cout << "Next Fit w/ Compaction Average number of processes: " << compactionAvgProcessInMemory / executeTimes << "\n";
    std::cout << "Memory compaction yielded in " <<
    		(compactionAvgProcessInMemory / executeTimes) - (avgProcessInMemory / executeTimes) <<
    		" process swapped than without memory compaction\n";


    avgProcessInMemory = compactionAvgProcessInMemory = 0;
    for(int i = 0; i < executeTimes; i++) {
    	std::cout << "\nBest Fit Run " << i + 1 << ":\n";
    	avgProcessInMemory += swapWithAlgorithm(orderedProcesses[i], &startBestFit, false);
    	std::cout << "\nBest Fit w/ Compaction Run " << i + 1 << ":\n";
    	compactionAvgProcessInMemory += swapWithAlgorithm(orderedProcesses[i], &startNextFit, true);
    }
    std::cout << "Best Fit Average number of processes: " << avgProcessInMemory / executeTimes << "\n";
    std::cout << "Best Fit w/ Compaction Average number of processes: " << compactionAvgProcessInMemory / executeTimes << "\n";
    std::cout << "Memory compaction yielded in " <<
    		(compactionAvgProcessInMemory / executeTimes) - (avgProcessInMemory / executeTimes) <<
    		" process swapped than without memory compaction\n";

    avgProcessInMemory = compactionAvgProcessInMemory = 0;
    for(int i = 0; i < executeTimes; i++) {
        std::cout << "\nWorst Fit Run " << i + 1 << ":\n";
    	avgProcessInMemory += swapWithAlgorithm(orderedProcesses[i], &startWorstFit, false);
    	std::cout << "\nWorst Fit w/ Compaction Run " << i + 1 << ":\n";
    	compactionAvgProcessInMemory += swapWithAlgorithm(orderedProcesses[i], &startNextFit, true);
    }
    std::cout << "Worst Fit Average number of processes: " << avgProcessInMemory / executeTimes << "\n";
    std::cout << "Worst Fit w/ Compaction Average number of processes: " << compactionAvgProcessInMemory / executeTimes << "\n";
    std::cout << "Memory compaction yielded in " <<
    		(compactionAvgProcessInMemory / executeTimes) - (avgProcessInMemory / executeTimes) <<
    		" process swapped than without memory compaction\n";

    // Deleting processes when done.
    for (int j = 0; j < executeTimes; j++) {
    	for(i = 0; i < queueSize; i++) {
			Process * nextProcess = orderedProcesses[j].front();
			delete nextProcess;
			orderedProcesses[j].pop();
    	}
    }
}
