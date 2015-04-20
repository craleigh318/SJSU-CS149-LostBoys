//
//  main.c
//  Assignment 6
//
//  Created by Christopher Raleigh on 2015/15/04.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "SystemHeaders.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    /*
     Create 5 pipes.
     Each pipe has 2 integers.
     */
    int pipes[2][5];
    if (pipe(pipes[0])) {
        printf("Pipe 0 failed.");
    } else {
        printf("Pipe 0 succeeded");
    }
    pid_t parentID = getpid();
    if (parentID != fork()) {
        /*
         Child 1.
         */
        
    } else if (parentID != fork()) {
        /*
         Child 2.
         */
    } else if (parentID != fork()) {
        /*
         Child 3.
         */
    } else if (parentID != fork()) {
        /*
         Child 4.
         */
    } else if (parentID != fork()) {
        /*
         Child 5.
         */
    }
    return 0;
}
