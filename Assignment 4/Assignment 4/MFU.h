/*
 * MFU.h
 *
 *  Created on: Mar 19, 2015
 *      Author: Saurav
 */

#ifndef MFU_H_
#define MFU_H_

#include "SystemHeaders.h"
#include "SwappingAlgorithm.h"
#include "Paging.h"
#include "Page.h"

class MFU :
public SwappingAlgorithm
{
public:
    MFU(PageFrameSet underlyingContainer);

    Page * addPage(Page * page);
};


#endif /* MFU_H_ */
