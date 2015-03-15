//
//  PageFrameSet.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/14/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "PageFrameSet.h"

std::vector<Page *> PageFrameSet::initializeFramesVector(int vectorSize) {
    std::vector<Page *> frameVector;
    int i;
    for (i = 0; i < vectorSize; ++i) {
        frameVector.push_back(NULL);
    }
    return frameVector;
}

PageFrameSet::PageFrameSet(int numFrames) :
frames(initializeFramesVector(numFrames))
{
}

Page * PageFrameSet::getPage(int index) {
    return frames.at(index);
}

void PageFrameSet::setPage(int index, Page * value) {
    frames.at(index) = value;
}