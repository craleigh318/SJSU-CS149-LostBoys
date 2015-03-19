/* 
 * File:   LRU.cpp
 * Author: will
 * 
 * Created on March 18, 2015, 5:56 PM
 */

#include "LRU.h"

LRU::LRU(PageFrameSet underlyingContainer): SwappingAlgorithm(underlyingContainer)
{
}


    Page *LRU::addPage(Page * page)
    {
        PageFrameSet *set = getUnderlyingContainer();
        for(int j = 0; j < set->getSize(); j++)
        {
            if(page == set->getPage(j))
            {
                set->movePageTo(j,0);
                return NULL;
            }
        }
        Page *victim = set->getPage(set->getSize()-1); // Get the last page as the victim to be removed 
        
        for (int i = (set->getSize() - 2); i >= 0; --i)
        {
        Page * currentPage = set->getPage(i);
        set->setPage(i + 1, currentPage);
        }
        
        return victim;
    }
