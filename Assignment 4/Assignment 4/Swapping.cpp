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

    //NextFit
    /*int currTime = 0;
    Process ** NextFitMemory = newMainMemory();
    while(currTime < RUNTIME) {
    	Process passProcess;
        std::cout << "Example Process:\nSize:\t\t" << passProcess.getSize()
        << " MB\nDuration:\t" << passProcess.getDuration() << " s\n";
    	if(startNextFit(NextFitMemory, &passProcess)) {
    		printMainMemory(NextFitMemory);
    	}
    	currTime++;
    }

    deleteMainMemory(NextFitMemory);*/
    startFirstFitSwapping();
    MainMemory memoryForNextFit;
    Process processForNextFit;
    startNextFit(memoryForNextFit, &processForNextFit);
    //runBestFit();
}
