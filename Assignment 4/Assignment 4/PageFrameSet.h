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
     Returns the number of frames in this set.
     */
    int getSize();
    
    /*
     Returns the page at the specified index.
     */
    Page * getPage(int index);
    
    /*
     Sets the page pointer at the specified index.
     Returns false if page cannot be set.
     */
    void setPage(int index, Page * value);
    
    /*
     Moves the page at the specified index to a new index.
     For example, the page at index 0 can be moved to 2,
     shifting pages 1 and 2 to the front.
     */
    void movePageTo(int index, int destination);
    
    /*
     Returns true if this set already contains the specified page.
     */
    bool containsPage(Page * page);
    
    /*
     Prints the names of the pages in this set.
     */
    void print();
    
private:
    std::vector<Page *> frames;
    
    std::vector<Page *> initializeFramesVector(int vectorSize);
    
    int size;
};

#endif /* defined(__Assignment_4__PageFrameSet__) */
