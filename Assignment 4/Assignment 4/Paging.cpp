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
    algorithm->print();
    if (victim) {
        std::cout << "Victim: " << victim->getName() << '\n';
    }
    std::cout << '\n';
}

void pagingStart() {
    PageFrameSet physicalMemory(4);
    PageFrameSet disk(10);
    FIFOSet fifoSet(physicalMemory);
    RandomPage randomSet(physicalMemory);
    std::vector<Page> pages;
    int i;
    for (i = 0; i < 10; ++i) {
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
}