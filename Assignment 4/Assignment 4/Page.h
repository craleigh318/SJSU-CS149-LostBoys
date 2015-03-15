//
//  Page.h
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/14/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_4__Page__
#define __Assignment_4__Page__
#include "SystemHeaders.h"

class Page {
    
public:
    /*
     Constructor.
     */
    Page(int name);
    
    /*
     Returns name as number.
     */
    int getName();
    
    /*
     Returns last time used.
     */
    int getLastTimeUsed();
    
    /*
     Sets last time used.
     */
    int setLastTimeUsed(int time);
    
    /*
     Returns number of times used.
     */
    int getNumTimesUsed();
    
    /*
     Increases number times used by 1.
     */
    int increaseNumTimesUsed();
    
private:
    int name;
    
    int lastTimeUsed;
    
    int numTimesUsed;
};

#endif /* defined(__Assignment_4__Page__) */
