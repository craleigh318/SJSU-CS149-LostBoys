#include "RandomPage.h"

RandomPage::RandomPage(PageFrameSet underlyingContainer) :
SwappingAlgorithm(underlyingContainer)
{
}

Page * RandomPage::addPage(Page * page) {
    if(!canAddPage(page))
    {
        return NULL;
    }
    PageFrameSet * frames = getUnderlyingContainer(); // Get the 4 physical page memory 
    for(int i = 0; i < frames->getSize(); i++)
    {
        Page *currentFrame = frames->getPage(i);
        if(currentFrame == NULL) // If the current frame is filled and not null
        {
            frames ->setPage(i , page);
            return currentFrame; 
        }
    }
    int randomPage = rand() % (frames -> getSize()); // Gets a random page from the frames to remove
    Page * victim = frames->getPage(randomPage); // Getting the actual page and accessing it 
    frames->setPage(randomPage, page);
    return victim;
}
