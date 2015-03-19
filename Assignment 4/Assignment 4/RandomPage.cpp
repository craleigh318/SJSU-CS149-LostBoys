#include "RandomPage.h"

RandomPage::RandomPage(PageFrameSet underlyingContainer) :
SwappingAlgorithm(underlyingContainer)
{
}

Page * RandomPage::addPage(Page * page) {
    PageFrameSet * frames = getUnderlyingContainer(); // Get the 4 physical page memory 
    int randomPage = rand() % (frames -> getSize()); // Gets a random page from the frames to remove
    Page * victim = frames->getPage(randomPage); // Getting the actual page and accessing it 
    frames->setPage(randomPage, page);
    return victim;
}