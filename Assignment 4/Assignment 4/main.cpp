//
//  main.cpp
//  Assignment 4
//
//  Created by Christopher Raleigh on 2015/05/03.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "SystemHeaders.h"
#include "Swapping.h"
#include "Paging.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    srand((unsigned int)time(NULL));
    std::cout << "----------------------SWAPPING START--------------------------" << "\n";
    swappingStart();
    std::cout <<"\n---------------------------PAGING START----------------------------" << "\n";
    pagingStart();
    return 0;
}
