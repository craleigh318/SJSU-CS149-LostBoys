//
//  Paging.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/08/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Paging.h"

void pagingStart() {
    PageFrameSet physicalMemory(4);
    PageFrameSet disk(10);
    std::vector<Page> pages;
    int i;
    for (i = 0; i < 10; ++i) {
        pages.push_back(Page(i));
    }
    // Add pages to memory.
    for (i = 0; i < 4; ++i) {
        physicalMemory.setPage(i, &pages.at(i));
    }
    physicalMemory.print();
    physicalMemory.movePageTo(0, 2);
    physicalMemory.print();
}