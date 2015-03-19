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
        std::cout << "Victim at index: " << victim->getName() << '\n';
    }
    algorithm->print();
    std::cout << '\n';
}

void pagingStart() {
    PageFrameSet physicalMemory(PHYS_NUM_FRAMES);
    PageFrameSet disk(DISK_NUM_FRAMES);
    FIFOSet fifoSet(physicalMemory);
    RandomPage randomSet(physicalMemory);
    LRU lruSet(physicalMemory);
    std::vector<Page> pages;
    int i;
    for (i = 0; i < NUM_PAGES; ++i) {
        pages.push_back(Page(i));
    }
    // Add pages to memory.
    std::cout << "First in, First Out\n";
    for (i = 0; i < 8; ++i) {
        addPage(&fifoSet, &pages.at(i));
    }
    addPage(&fifoSet, &pages.at(6));
    std::cout << "Random Pick\n";
    for (i = 0; i < 8; ++i) {
        addPage(&randomSet, &pages.at(i));
    }
    
    std::cout << "LRU Paging\n";
    for (i = 0; i < 8; ++i) {
        addPage(&lruSet, &pages.at(i));
    }
    addPage(&lruSet, &pages.at(6));
    addPage(&lruSet, &pages.at(1));
    addPage(&lruSet, &pages.at(2));
    addPage(&lruSet, &pages.at(3));
}
