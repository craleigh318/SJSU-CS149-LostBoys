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

int addAllPages(SwappingAlgorithm * algorithm, std::vector<Page *> * pageVector) {
	int numHits = 0;
    size_t vectorSize = pageVector->size();
    for (int i = 0; i < vectorSize; ++i) {
        bool hit = addPage(algorithm, pageVector->at(i));
        numHits += hit ? 1 : 0;
    }
    return numHits;
}

void clearAllPages(std::vector<Page *> * pageVector) {
    size_t vectorSize = pageVector->size();
    for (int i = 0; i < vectorSize; ++i) {
        clearPage(pageVector->at(i));
    }
}

void clearPage(Page * page) {
	page->resetNumTimesUsed();
}



void pagingStart() {
    PageFrameSet physicalMemory(PHYS_NUM_FRAMES);
    std::vector<Page> pages;
    FIFOSet fifoSet(physicalMemory);
    RandomPage randomSet(physicalMemory);
    LRU lruSet(physicalMemory);
    MFU mfuSet(physicalMemory);
    LFU lfuSet(physicalMemory);

    int i;
    int executeTimes = 5;
    int pageReferences = 100;
    int delta = rand() % 10;
    std::vector<std::vector<Page *> > disk;
    // Create all the page references
    for (int j = 0; j < DISK_NUM_FRAMES; ++j) {
        pages.push_back(Page(j));
    }
    // Add page references to disk.
    for(int j = 0; j < executeTimes; j++) {
    	std::vector<Page *> currentVector;
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
    		currentVector.push_back(&pages.at(delta));
    	}
        disk.push_back(currentVector);
     }
    // Add pages to memory.

    int numHits = 0;
    for (i = 0; i < executeTimes; ++i) {
    	std::cout << "--------------------First in, First Out. Run " << i + 1 << "--------------------\n";
        numHits += addAllPages(&fifoSet, &disk.at(i));
        numHits = (numHits < 0) ? 0 : numHits;
        clearAllPages(&disk.at(i));
		SwappingAlgorithm * algorithm = &fifoSet;
		algorithm->clearMain();
    }
    std::cout << "Average Hit Ratio: " << numHits / executeTimes << "%\n";

    numHits = 0;
    for (i = 0; i < executeTimes; ++i) {
    	std::cout << "--------------------Random Pick. Run " << i + 1 << "--------------------\n";
        numHits += addAllPages(&randomSet, &disk.at(i));
        numHits = (numHits < 0) ? 0 : numHits;
        clearAllPages(&disk.at(i));
		SwappingAlgorithm * algorithm = &randomSet;
		algorithm->clearMain();
    }
    std::cout << "Average Hit Ratio: " << numHits / executeTimes << "%\n";

    numHits = 0;
    for (i = 0; i < executeTimes; ++i) {
    	std::cout << "--------------------LRU Paging. Run " << i + 1 << "--------------------\n";
        numHits += addAllPages(&lruSet, &disk.at(i));
        numHits = (numHits < 0) ? 0 : numHits;
        clearAllPages(&disk.at(i));
		SwappingAlgorithm * algorithm = &lruSet;
		algorithm->clearMain();
    }
    std::cout << "Average Hit Ratio: " << numHits / executeTimes << "%\n";

    numHits = 0;
   	for (i = 0; i < executeTimes; ++i) {
   		std::cout << "--------------------MFU Paging. Run " << i + 1 << "--------------------\n";
        numHits += addAllPages(&mfuSet, &disk.at(i));
        numHits = (numHits < 0) ? 0 : numHits;
        clearAllPages(&disk.at(i));
        SwappingAlgorithm * algorithm = &mfuSet;
        algorithm->clearMain();
	}
   	std::cout << "Average Hit Ratio: " << numHits / executeTimes << "%\n";

	numHits = 0;
	for (i = 0; i < executeTimes; ++i) {
		std::cout << "--------------------LFU Paging. Run " << i + 1 << "--------------------\n";
        numHits += addAllPages(&lfuSet, &disk.at(i));
        numHits = (numHits < 0) ? 0 : numHits;
        clearAllPages(&disk.at(i));
        SwappingAlgorithm * algorithm = &lfuSet;
        algorithm->clearMain();
	}
	std::cout << "Average Hit Ratio: " << numHits / executeTimes << "%\n";
}
