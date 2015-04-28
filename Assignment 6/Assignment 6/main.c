//
//  main.c
//  Assignment 6
//
//  Created by Christopher Raleigh on 2015/15/04.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Child.h"
#include "GlobalVariables.h"
#include "Messaging.h"
#include "SystemHeaders.h"

void inputMessage(int * pipe, int childID) {
	char passString[100];
	if(close(pipe[READ]) == -1) {
		perror("ERROR: Child Closing Read");
		exit(1);
	}
	while(!finished) {
		char msg[100];
		gets(msg);
		createTimestamp(passString);
		sprintf(passString, "%s: %s", passString, msg);
		write(pipe[WRITE], passString, strlen(passString) + 1);
	}

	if(close(pipe[WRITE]) == -1) {
		perror("ERROR: Child Closing Write");
		exit(1);
	}
	//Not sure if this exit call is needed
	exit(0);
}

int main(int argc, const char * argv[]) {
    Child children[NUM_CHILDREN];
    pid_t childIDs[NUM_CHILDREN];
    int i;
    pid_t parent = getpid();
    initializeStartTime();
    int fd[NUM_CHILDREN][2];
    for(i = 0; i < NUM_CHILDREN; i++) {
    	if(i == NUM_CHILDREN - 1)
    		children[i] = newChild(i + 1, fd[i], true);
    	else
    		children[i] = newChild(i + 1, fd[i], false);
    }
    for(i = 0; i < NUM_CHILDREN; i++) {
		if(pipe(fd[i]) == -1) {
			perror("ERROR: Pipe Creation");
			exit(1);
		}
        fflush(0);
        childIDs[i] = fork();
        if(childIDs[i] == -1) {
            perror("ERROR: Fork");
            exit(1);
        }
		if(parent != getpid()) {
            srand(getpid());    // Seed random values.
			runChild(&children[i]);
		}
    }

    if(parent == getpid()) {
    	runParent(children);
        int j;
        for (j = 0; j < NUM_CHILDREN; ++j) {
            kill(j, SIGTERM);
        }
    }
    return 0;
}