/* 
 * File:   RandomPage.h
 * Author: will
 *
 * Created on March 18, 2015, 4:24 PM
 */

#ifndef RANDOMPAGE_H
#define	RANDOMPAGE_H

#include "SystemHeaders.h"
#include "SwappingAlgorithm.h"

class RandomPage :
public SwappingAlgorithm
{
public:
    RandomPage(PageFrameSet underlyingContainer);
    
    Page * addPage(Page * page);
};

#endif /* defined(__Assignment_4__FIFOSet__) */


#endif	/* RANDOMPAGE_H */

