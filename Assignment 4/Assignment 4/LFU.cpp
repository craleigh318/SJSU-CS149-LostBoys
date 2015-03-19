/*
 * LFU.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: Saurav
 */




#include "LFU.h"


LFU::LFU(PageFrameSet underlyingContainer) :
SwappingAlgorithm(underlyingContainer)
{
}

Page * LFU::addPage(Page * page) {
    PageFrameSet * frames = getUnderlyingContainer();
    int framesSize = frames->getSize();
    int repeatIndex = 0;

    if (!canAddPage(page)) {
    	int k;
    	for(k = 0; k < framesSize; k++) {
    		Page * currentPage = frames->getPage(k);
    		if(currentPage == page) {
    			repeatIndex = k;
    		}
    	}
    Page * temp = frames->getPage(repeatIndex);
    temp->increaseNumTimesUsed();
   	return NULL;
    }

    int j = 0;
    int lfuPage = 0;
    for(j = 0; j < framesSize; j++) {
    	Page * currentPage = frames->getPage(j);
    	if(currentPage == NULL) {
    		frames->setPage(j, page);
    		currentPage = frames->getPage(j);
    		currentPage->increaseNumTimesUsed();
    		return NULL;
    	}
    	else {
    		if(frames->getPage(j)->getNumTimesUsed() < frames->getPage(lfuPage)->getNumTimesUsed()) {
    			lfuPage = j;
    		    	}
    	}
    }
    Page * victim = frames->getPage(lfuPage);
    frames->setPage(lfuPage, page);
    Page * newCcurrentPage = frames->getPage(lfuPage);
    newCcurrentPage = frames->getPage(lfuPage);
    newCcurrentPage->increaseNumTimesUsed();
    return victim;
}
