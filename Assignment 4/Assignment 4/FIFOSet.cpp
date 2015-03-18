//
//  FIFOSet.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/18/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "FIFOSet.h"

Page * FIFOSet::addPage(Page * page) {
    PageFrameSet * frames = getUnderlyingContainer();
    int framesSize = frames->getSize();
    Page * victim = frames->getPage(framesSize - 1);
    int i;
    for (i = 0; i < (framesSize - 1); ++i) {
        Page * currentPage = frames->getPage(i);
        frames->setPage(i + 1, currentPage);
    }
    frames->setPage(0, page);
    return victim;
}