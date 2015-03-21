//
//  Paging.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/08/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Paging.h"

bool addPage(SwappingAlgorithm * algorithm, Page * page) {
	bool hit = true;
    std::cout << "Adding Page " << page->getName() << ".\n";
    Page * victim = algorithm->addPage(page);
    if (victim) {
        std::cout << "Victim page is: " << victim->getName() << '\n';
        hit = false;
    }
    algorithm->print();
    std::cout << '\n';
    return hit;
}

int addAllPages(SwappingAlgorithm * algorithm, std::vector<Page> * pageVector) {
	int numHits = 0;
    size_t vectorSize = pageVector->size();
    for (int i = 0; i < vectorSize; ++i) {
        bool hit = addPage(algorithm, &pageVector->at(i));
        numHits += hit ? 1 : 0;
    }
    return numHits;
}

void pagingStart() {
    PageFrameSet physicalMemory(PHYS_NUM_FRAMES);
    PageFrameSet disk(DISK_NUM_FRAMES);
    FIFOSet fifoSet(physicalMemory);
    RandomPage randomSet(physicalMemory);
    LRU lruSet(physicalMemory);
    MFU mfuSet(physicalMemory);
    LFU lfuSet(physicalMemory);

    int i;
    int executeTimes = 5;
    int pageReferences = 100;
    int delta = rand() % 10;
    std::vector<std::vector<Page> > pages;
    // Create all the page references
    for(int j = 0; j < executeTimes; j++) {
    	std::vector<Page> currentVector;
    	for (i = 0; i < pageReferences; ++i) {
    		int randNum = rand() % 10;
    		if(randNum < 7) {
    			delta += (rand() % 3) - 1;
    		}
    		else {
    			delta += (rand() % 7) + 2;
    		}
    		if(delta < 0)
    			delta = 9;
    		delta %= NUM_PAGES;
    		currentVector.push_back(Page(delta));
    	}
        pages.push_back(currentVector);
     }
    // Add pages to memory.
    int numHits;
    for (i = 0; i < executeTimes; ++i) {
    	std::cout << "First in, First Out. Run " << i + 1 << "\n";
        numHits += addAllPages(&fifoSet, &pages[i]);
        numHits = (numHits < 0) ? 0 : numHits;
    }
    std::cout << "Average Hit Ratio: " << numHits / executeTimes << "\n";

    numHits = 0;
    for (i = 0; i < executeTimes; ++i) {
    	std::cout << "Random Pick. Run " << i + 1 << "\n";
        numHits += addAllPages(&randomSet, &pages[i]);
        numHits = (numHits < 0) ? 0 : numHits;
    }
    std::cout << "Average Hit Ratio: " << numHits / executeTimes << "\n";

    numHits = 0;
    for (i = 0; i < executeTimes; ++i) {
    	std::cout << "LRU Paging. Run " << i + 1 << "\n";
        numHits += addAllPages(&lruSet, &pages[i]);
        numHits = (numHits < 0) ? 0 : numHits;
    }
    std::cout << "Average Hit Ratio: " << numHits / executeTimes << "\n";

    numHits = 0;
   	for (i = 0; i < executeTimes; ++i) {
   		std::cout << "MFU Paging. Run " << i + 1 << "\n";
        numHits += addAllPages(&mfuSet, &pages[i]);
        numHits = (numHits < 0) ? 0 : numHits;
	}
   	std::cout << "Average Hit Ratio: " << numHits / executeTimes << "\n";

	numHits = 0;
	for (i = 0; i < executeTimes; ++i) {
		std::cout << "LFU Paging. Run " << i + 1 << "\n";
        numHits += addAllPages(&lfuSet, &pages[i]);
        numHits = (numHits < 0) ? 0 : numHits;
	}
	std::cout << "Average Hit Ratio: " << numHits / executeTimes << "\n";
}
