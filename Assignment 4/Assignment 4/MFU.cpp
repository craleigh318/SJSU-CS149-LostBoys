/*
 * MFU.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: Saurav
 */



#include "MFU.h"


MFU::MFU(PageFrameSet underlyingContainer) :
SwappingAlgorithm(underlyingContainer)
{
}

Page * MFU::addPage(Page * page) {
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
    int mfuPage = 0;
    for(j = 0; j < framesSize; j++) {
    	Page * currentPage = frames->getPage(j);
    	if(currentPage == NULL) {
    		frames->setPage(j, page);
    		currentPage = frames->getPage(j);
    		currentPage->increaseNumTimesUsed();
    		return NULL;
    	}
    	else {
    		if(frames->getPage(j)->getNumTimesUsed() > frames->getPage(mfuPage)->getNumTimesUsed()) {
    		    		mfuPage = j;
    		    	}
    	}
    }
    Page * victim = frames->getPage(mfuPage);
    frames->setPage(mfuPage, page);
    Page * newCcurrentPage = frames->getPage(mfuPage);
    newCcurrentPage = frames->getPage(mfuPage);
    newCcurrentPage->increaseNumTimesUsed();
    return victim;
}
