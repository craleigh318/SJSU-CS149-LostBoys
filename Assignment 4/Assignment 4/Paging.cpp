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

void addAllPages(SwappingAlgorithm * algorithm, std::vector<Page *> * pageVector) {
    size_t vectorSize = pageVector->size();
    for (int i = 0; i < vectorSize; ++i) {
        addPage(algorithm, pageVector->at(i));
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

    std::vector<Page> pages;
    int i;
    int pageReferences = 100;
    int delta = rand() % 10;
    // Create all the page references
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
        pages.push_back(Page(delta));
    }
    // Add pages to memory.
    std::cout << "First in, First Out\n";
    for (i = 0; i < pageReferences; ++i) {
        addPage(&fifoSet, &pages.at(i));
    }
    std::cout << "Random Pick\n";
    for (i = 0; i < pageReferences; ++i) {
        addPage(&randomSet, &pages.at(i));
    }

    std::cout << "LRU Paging\n";
    for (i = 0; i < pageReferences; ++i) {
        addPage(&lruSet, &pages.at(i));
    }

    //Pages should be referenced randomly
    std::cout << "MFU Paging\n";
	for (i = 0; i < pageReferences; ++i) {
		addPage(&mfuSet, &pages.at(i));
	}

	std::cout << "LFU Paging\n";
	for (i = 0; i < pageReferences; ++i) {
		addPage(&lfuSet, &pages.at(i));
	}
}
