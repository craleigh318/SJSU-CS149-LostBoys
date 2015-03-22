//
//  Paging.h
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/08/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#ifndef __Assignment_4__Paging__
#define __Assignment_4__Paging__
#include "SystemHeaders.h"
#include "PageFrameSet.h"
#include "FIFOSet.h"
#include "RandomPage.h"
#include "LRU.h"
#include "MFU.h"
#include "LFU.h"

bool addPage(SwappingAlgorithm * algorithm, Page * page);

int addAllPages(SwappingAlgorithm * algorithm, std::vector<Page *> * pageVector);

void clearAllPages(std::vector<Page *> * pageVector);

void clearPage(Page * page);


/*
 Starts the paging part of the assignment.
 */
void pagingStart();

#endif /* defined(__Assignment_4__Paging__) */
