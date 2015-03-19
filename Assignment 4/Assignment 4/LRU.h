/* 
 * File:   LRU.h
 * Author: will
 *
 * Created on March 18, 2015, 5:56 PM
 */

#ifndef LRU_H
#define	LRU_H
#include "SwappingAlgorithm.h"

class LRU: public SwappingAlgorithm {
public:
    LRU(PageFrameSet underlyingContainer);
    
        Page * addPage(Page * page);
        
private:

};

#endif	/* LRU_H */

