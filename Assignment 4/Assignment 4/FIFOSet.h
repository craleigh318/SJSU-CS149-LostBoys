//
//  FIFOSet.h
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/18/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_4__FIFOSet__
#define __Assignment_4__FIFOSet__
#include "SystemHeaders.h"
#include "SwappingAlgorithm.h"

class FIFOSet :
public SwappingAlgorithm
{
public:
    FIFOSet(PageFrameSet underlyingContainer);
    
    Page * addPage(Page * page);
};

#endif /* defined(__Assignment_4__FIFOSet__) */
