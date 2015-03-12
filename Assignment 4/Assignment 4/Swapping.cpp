//
//  Swapping.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/08/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Swapping.h"

void swappingStart() {
    std::cout << "Swapping:\n";
    //MainMemory mainMemory;
    /*Process * exampleProcess = newProcess();
    std::cout << "Example Process:\nSize:\t\t" << getProcessSize(exampleProcess)
    << " MB\nDuration:\t" << getProcessDuration(exampleProcess) << " s\n";
    Process ** exampleMemory = newMainMemory();
    std::vector<Partition *> holes = getHolesInMemory(exampleMemory);
    addProcessToHole(holes.at(0), exampleProcess);
    printMainMemory(exampleMemory);
    std::cout << "Hole Size: " << getPartitionSize(holes.at(0)) << '\n';
    deleteProcess(exampleProcess);
    deleteMainMemory(exampleMemory);*/

    //NextFit
    int currTime = 0;
    Process ** NextFitMemory = newMainMemory();
    while(currTime < RUNTIME) {
    	Process* passProcess = newProcess();
        std::cout << "Example Process:\nSize:\t\t" << getProcessSize(passProcess)
        << " MB\nDuration:\t" << getProcessDuration(passProcess) << " s\n";
    	if(startNextFit(NextFitMemory, passProcess)) {
    		printMainMemory(NextFitMemory);
    	}
    	currTime++;
    }

    deleteMainMemory(NextFitMemory);
}
