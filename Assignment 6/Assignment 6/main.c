//
//  main.c
//  Assignment 6
//
//  Created by Christopher Raleigh on 2015/15/04.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "SystemHeaders.h"
#include "GlobalVariables.h"

void sendMessages(int * pipe, int childID) {
    /*
     pipe[0] is for reading.
     pipe[1] is for writing.
     */
    /*char stringWrite[128];
    char stringRead[128];
    sprintf(stringWrite, "This is Child %d.\n", childID);
    close(pipe[0]);
    write(pipe[1], stringWrite, strlen(stringWrite + 1));
    close(pipe[1]);
    read(pipe[0], stringRead, sizeof(stringRead));
    printf("%s\n", stringRead);*/
    printf("This is Child %d.\n", childID);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    time(&initialTime);
    printf("Hello, World!\n");
    /*
     Create 5 pipes.
     Each pipe has 2 integers.
     */
    int pipes[NUM_CHILDREN][2];
    pid_t parentID = getpid();
    int i = 0;
    for (i = 0; i < NUM_CHILDREN; ++i) {
        pipe(pipes[i]);
        fork();
        if (parentID != getpid()) {
            sendMessages(pipes[i], i + 1);
            break;
        }
    }
    return 0;
}
