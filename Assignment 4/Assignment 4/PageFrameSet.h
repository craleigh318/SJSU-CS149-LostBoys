//
//  PageFrameSet.h
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/14/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_4__PageFrameSet__
#define __Assignment_4__PageFrameSet__
#include "SystemHeaders.h"
#include "Page.h"

class PageFrameSet {
    
public:
    /*
     Constructs a new page with the specified number of allowable frames.
     */
    PageFrameSet(int numFrames);
    
    /*
     Returns the page at the specified index.
     */
    Page * getPage(int index);
    
    /*
     Sets the page pointer at the specified index.
     */
    void setPage(int index, Page * value);
    
private:
    std::vector<Page *> frames;
    
    std::vector<Page *> initializeFramesVector(int vectorSize);
};

#endif /* defined(__Assignment_4__PageFrameSet__) */
