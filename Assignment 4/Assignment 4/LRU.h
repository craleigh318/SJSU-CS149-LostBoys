/*
 * LRU.h
 *
 *  Created on: Mar 18, 2015
 *      Author: Steve
 */

#ifndef LRU_H_
#define LRU_H_

#include "SystemHeaders.h"
#include "SwappingAlgorithm.h"

class LRU:
public SwappingAlgorithm {
public:
	LRU(PageFrameSet underlyingContainer);
	Page* addPage(Page* page);
private:
	int getLowestCountArrayPOS();
	void decrementCountArray();
	void referencePageInCountArray(int position);
    int countArray[NUM_PAGES];
};


#endif /* LRU_H_ */
