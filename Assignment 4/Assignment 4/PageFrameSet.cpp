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
frames(initializeFramesVector(numFrames)),
size(numFrames)
{
}

int PageFrameSet::getSize() {
    return size;
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

bool PageFrameSet::containsPage(Page * page) {
    if (!page) {
        return false;
    }
    int i;
    for (i = 0; i < size; ++i) {
        if ((frames.at(i)) && (page->getName() == frames.at(i)->getName())) {
            return true;
        }
    }
    return false;
}

void PageFrameSet::print() {
    std::cout << '[';
    int i;
    bool putSpace = false;
    for (i = 0; i < size; ++i) {
        Page * currentPage = frames.at(i);
        if (putSpace) {
            std::cout << " ";
        }
        if (currentPage) {
            std::cout << currentPage->getName();
        } else {
            std::cout << ".";
        }
        putSpace = true;
    }
    std::cout << "]\n";
}
