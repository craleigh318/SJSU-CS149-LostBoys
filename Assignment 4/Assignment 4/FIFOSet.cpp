//
//  FIFOSet.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/18/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "FIFOSet.h"

FIFOSet::FIFOSet(PageFrameSet underlyingContainer) :
SwappingAlgorithm(underlyingContainer)
{
}

Page * FIFOSet::addPage(Page * page) {
    PageFrameSet * frames = getUnderlyingContainer();
    bool cannotAdd= page && frames->containsPage(page);
    if (cannotAdd) {
        return NULL;
    }
    int framesSize = frames->getSize();
    Page * victim = frames->getPage(framesSize - 1);
    int i;
    for (i = (framesSize - 2); i >= 0; --i) {
        Page * currentPage = frames->getPage(i);
        frames->setPage(i + 1, currentPage);
    }
    frames->setPage(0, page);
    return victim;
}