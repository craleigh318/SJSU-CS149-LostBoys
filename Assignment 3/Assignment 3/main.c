//
//  main.c
//  Assignment 3
//
//  Created by Christopher Raleigh on 2015/17/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "system_headers.h"
#include "print_queue.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    srand((unsigned int)time(NULL));
    struct print_queue myQueue = new_print_queue();
    char string1[] = "Hello, World!";
    char string2[] = "Hello, Self!";
    add_print_job(&myQueue, string1);
    add_print_job(&myQueue, string2);
    print_next_job(&myQueue);
    print_next_job(&myQueue);
    return 0;
}
