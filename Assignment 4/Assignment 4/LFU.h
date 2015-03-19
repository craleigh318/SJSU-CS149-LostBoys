/*
 * LFU.h
 *
 *  Created on: Mar 19, 2015
 *      Author: Saurav
 */

#ifndef LFU_H_
#define LFU_H_

#include "SystemHeaders.h"
#include "SwappingAlgorithm.h"
#include "Paging.h"
#include "Page.h"

class LFU :
public SwappingAlgorithm
{
public:
    LFU(PageFrameSet underlyingContainer);

    Page * addPage(Page * page);
};



#endif /* LFU_H_ */
