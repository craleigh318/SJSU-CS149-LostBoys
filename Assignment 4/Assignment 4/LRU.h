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
	/*
	 Returns the page number that is currently in the page frame, that has the lowest value in the countArray
	 */
	int getLowestCountArrayPOS();
	/*
	 Decrements the current pages in the count array that are in the page frame
	 */
	void decrementCountArray();
	/*
	 Resets the page's countArray position to 0, meaning that page was just called
	 */
	void referencePageInCountArray(int position);
	/*
	 Holds the count of which pages have been called and how long they've been in the page frame
	 */
    int countArray[NUM_PAGES];
};


#endif /* LRU_H_ */
