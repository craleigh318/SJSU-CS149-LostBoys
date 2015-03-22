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


/*void MFU::clearMain() {
	PageFrameSet * frames = getUnderlyingContainer();
	for(int i = 0; i < frames->getSize(); i++) {
		frames->setPage(i, NULL);
	}
}*/

Page * MFU::addPage(Page * page) {
    PageFrameSet * frames = getUnderlyingContainer();
    int framesSize = frames->getSize();
    int repeatIndex = 0;
    //page->increaseNumTimesUsed();

    //std::cout << "Page frequency: " << page->getNumTimesUsed() << "\n";

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
		std::cout << "Page frequency: " << temp->getNumTimesUsed() << "\n";
		return NULL;
    }

    int j;
    int mfuPage = 0;
    for(j = 0; j < framesSize; j++) {
    	Page * currentPage = frames->getPage(j);
    	if(currentPage == NULL) {
    		frames->setPage(j, page);
    		currentPage = frames->getPage(j);
    		currentPage->increaseNumTimesUsed();
    		std::cout << "Page frequency: " << currentPage->getNumTimesUsed() << "\n";
    		//page->increaseNumTimesUsed();
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
    //newCcurrentPage = frames->getPage(mfuPage);
    newCcurrentPage->increaseNumTimesUsed();
    std::cout << "Page frequency: " << newCcurrentPage->getNumTimesUsed() << "\n";
    return victim;
}
