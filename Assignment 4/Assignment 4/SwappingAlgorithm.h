//
//  SwappingAlgorithm.h
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/18/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_4__SwappingAlgorithm__
#define __Assignment_4__SwappingAlgorithm__
#include "SystemHeaders.h"
#include "PageFrameSet.h"

/*
 Abstract class for FIFO, LRU, LFU, MFU and random pick.
 */
class SwappingAlgorithm {
    
public:
    /*
     Constructs a new algorithm that uses a copy of the specified page frame set.
     */
    SwappingAlgorithm(PageFrameSet underlyingContainer);
    
    /*
     Adds the specified page pointer to a frame.
     Returns a pointer to the evicted page, if applicable.
     Subclasses must override this method.
     */
    virtual Page * addPage(Page * page) = 0;
    
    /*
     Prints the names of the pages in this set.
     */
    void print();
    
protected:
    /*
     Returns the underlying container.
     */
    PageFrameSet * getUnderlyingContainer();
    
private:
    PageFrameSet underlyingContainer;
};

#endif /* defined(__Assignment_4__SwappingAlgorithm__) */
