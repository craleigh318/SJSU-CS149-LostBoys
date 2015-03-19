/*
 * LRU.cpp
 *
 *  Created on: Mar 18, 2015
 *      Author: Steve
 */
#include "LRU.h"

LRU::LRU(PageFrameSet container):
SwappingAlgorithm(container) {
	for(int i = 0; i < NUM_PAGES; i++)
		countArray[i] = 0;
}

int LRU::getLowestCountArrayPOS() {
	int lowestVal = 0;
	int POS = -1;
	PageFrameSet* frames = getUnderlyingContainer();
	for(int i = 0; i < frames->getSize(); i++) {
		Page* page = frames->getPage(i);
		if(!page) {
			return -1;
		}
		else if(countArray[page->getName()] < lowestVal) {
			lowestVal = countArray[page->getName()];
			POS = page->getName();
		}
	}
	return POS;
}

void LRU::decrementCountArray() {
	PageFrameSet* frames = getUnderlyingContainer();
	int frameSize = frames->getSize();
	for(int i = 0; i < frameSize; i++){
		Page* page = frames->getPage(i);
		if(page)
			countArray[page->getName()]--;
	}
}

void LRU::referencePageInCountArray(int position) {
	countArray[position] = 0;
}

Page* LRU::addPage(Page* page) {
	PageFrameSet* frames = getUnderlyingContainer();
	int frameSize = frames->getSize();

	Page* victim;
	decrementCountArray();
	if(frames->containsPage(page)) {
		referencePageInCountArray(page->getName());
		return NULL;
	}
	else {
		int lowestPOS = getLowestCountArrayPOS();
		for(int i = 0; i < frameSize; i++) {
			if(!frames->getPage(i)) {
				frames->setPage(i, page);
				referencePageInCountArray(page->getName());
				return NULL;
			}
			else if(frames->getPage(i)->getName() == lowestPOS) {
				victim = frames->getPage(i);
				frames->setPage(i, page);
				referencePageInCountArray(page->getName());
			}
		}
	}
	return victim;
}


