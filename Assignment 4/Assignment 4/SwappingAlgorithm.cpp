//
//  SwappingAlgorithm.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/18/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "SwappingAlgorithm.h"

SwappingAlgorithm::SwappingAlgorithm(PageFrameSet underlyingContainer) :
underlyingContainer(underlyingContainer)
{
}

bool SwappingAlgorithm::canAddPage(Page * page) {
    return !page || !getUnderlyingContainer()->containsPage(page);
}

void SwappingAlgorithm::print() {
    underlyingContainer.print();
}

PageFrameSet * SwappingAlgorithm::getUnderlyingContainer() {
    return &underlyingContainer;
}