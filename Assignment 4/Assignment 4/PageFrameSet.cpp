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

void PageFrameSet::movePageTo(int index, int destination) {
    int i;
    size_t framesSize = frames.size();
    for (i = 0; i < framesSize; ++i) {
        bool startSwapping = ((i <= index) || (i <= destination));
        if (startSwapping) {
            bool stopSwapping = ((i >= index) && (i >= destination));
            if (stopSwapping) {
                return;
            }
            Page * tempPage = frames.at(i);
            frames.at(i) = frames.at(i + 1);
            frames.at(i + 1) = tempPage;
        }
    }
}

void PageFrameSet::print() {
    std::cout << '[';
    int i;
    size_t framesSize = frames.size();
    bool putComma = false;
    for (i = 0; i < framesSize; ++i) {
        if (putComma) {
            std::cout << ", ";
        }
        std::cout << frames.at(i)->getName();
        putComma = true;
    }
    std::cout << "]\n";
}