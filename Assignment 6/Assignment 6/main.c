//
//  main.c
//  Assignment 6
//
//  Created by Christopher Raleigh on 2015/15/04.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "SystemHeaders.h"

void sendMessages(int * pipe, int childID) {
    /*
     pipe[0] is for reading.
     pipe[1] is for writing.
     */
    printf("This is Child %d.\n", childID);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    /*
     Create 5 pipes.
     Each pipe has 2 integers.
     */
    int pipes[2][5];
    pid_t parentID = getpid();
    const int NUM_CHILDREN = 5;
    int i = 0;
    for (i = 0; i < NUM_CHILDREN; ++i) {
        fork();
        if (parentID != getpid()) {
            sendMessages(pipes[i], i + 1);
            break;
        }
    }
    return 0;
}
