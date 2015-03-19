//
//  Paging.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/08/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Paging.h"

void addPage(SwappingAlgorithm * algorithm, Page * page) {
    std::cout << "Adding Page " << page->getName() << ".\n";
    Page * victim = algorithm->addPage(page);
    if (victim) {
        std::cout << "Victim page is: " << victim->getName() << '\n';
    }
    algorithm->print();
    std::cout << '\n';
}

void addAllPages(SwappingAlgorithm * algorithm, std::vector<Page> * pageVector) {
    size_t vectorSize = pageVector->size();
    for (int i = 0; i < vectorSize; ++i) {
        addPage(algorithm, &pageVector->at(i));
    }
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
    std::vector<Page> pages[executeTimes];
    // Create all the page references
    for(int j = 0; j < executeTimes; j++) {
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
			pages[j].push_back(Page(delta));
		}
    }
    // Add pages to memory.
    std::cout << "First in, First Out\n";
    for (i = 0; i < executeTimes; ++i) {
        addAllPages(&fifoSet, &pages[i]);
    }
    std::cout << "Random Pick\n";
    for (i = 0; i < executeTimes; ++i) {
        addAllPages(&randomSet, &pages[i]);
    }

    std::cout << "LRU Paging\n";
    for (i = 0; i < executeTimes; ++i) {
        addAllPages(&lruSet, &pages[i]);
    }

    std::cout << "MFU Paging\n";
	for (i = 0; i < executeTimes; ++i) {
        addAllPages(&mfuSet, &pages[i]);
	}

	std::cout << "LFU Paging\n";
	for (i = 0; i < executeTimes; ++i) {
        addAllPages(&lfuSet, &pages[i]);
	}
}
