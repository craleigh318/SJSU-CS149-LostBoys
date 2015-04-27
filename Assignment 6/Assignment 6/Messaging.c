//
//  Messaging.c
//  Assignment 6
//
//  Created by Christopher Raleigh on 2015/22/04.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "Messaging.h"

void initializeStartTime() {
    struct timeval  tv;
    gettimeofday(&tv, NULL);
    double time_in_mill = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;
    startTime = time_in_mill;
}

double getTimeInMilli() {
    struct timeval  tv;
    double retTimeInMilli;
    gettimeofday(&tv, NULL);
    retTimeInMilli = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
    return retTimeInMilli;
}

void createTimestamp(char *buf) {
    char retString[128];
    double curTime;
    curTime = getTimeInMilli();
    int difference = curTime - startTime;
    int second = (int) floor((double) (difference / 1000));
    sprintf(retString, "%i:%02i.%03i", second / 60, second % 60, difference);
    strcpy(buf,retString);
}

void createMessage(char * passString, Child * child) {
    sprintf(passString, "Child %i message %i", child->id, ++(child->numMessages));
}

void createTimestampMessage(char * passString, char * originalMessage) {
	char timestamp[128];
    createTimestamp(timestamp);
    sprintf(passString, "%s: %s\n", timestamp, originalMessage);
}

void runChild(Child * child) {
    char passString[100];
    char tempString[100];
    if(close(child->pipe[READ]) == -1) {
        perror("ERROR: Child Closing Read");
        exit(1);
    }
    while(!finished) {
		if(!child->input) {
			randomSleepTime();
			createMessage(tempString, child);
			createTimestampMessage(passString, tempString);
    	}
		else{
			char msg[100];
            fgets(msg,100, stdin);
            createTimestamp(passString);
			sprintf(passString, "%s: %s", passString, msg);
		}
		write(child->pipe[WRITE], passString, strlen(passString) + 1);
    }
    
    if(close(child->pipe[WRITE]) == -1) {
        perror("ERROR: Child Closing Write");
        exit(1);
    }
    //Not sure if this exit call is needed
    exit(0);
}

void runParent(Child *pipes) {
		char readBuffer[100];
		int activity, nbytes, max_fd, i;
		fd_set readfds, reads;
		FD_ZERO(&readfds);
		for(i = 0; i < NUM_CHILDREN; i++) {
			if(close(pipes[i].pipe[WRITE]) == -1){
				perror("ERROR: Parent Closing Write");
				exit(1);
			}
			//Makes the pipes nonblocking
			int flags = fcntl(pipes[i].pipe[READ], F_GETFL, 0);
			fcntl(pipes[i].pipe[READ], F_SETFL, flags | O_NONBLOCK);

			FD_SET(pipes[i].pipe[READ], &readfds);

			if(max_fd < pipes[i].pipe[READ])
				max_fd = pipes[i].pipe[READ];
		}

		//Temporary while condition, change when we get timing solved
		//Currently exiting when all children ports are read from
		int count = 0;
		while(!finished) {
			reads = readfds;
			//Timeout struct
			struct timeval tv;
			tv.tv_sec = 4;
			tv.tv_usec = 0;
			activity = select(max_fd + 1, &reads, NULL, NULL, &tv);
			if(activity == 0) {
				printf("Timed out\n");
				count++;
			}
			else if(activity < 0) {
				printf("Error On Select\n");
				exit(1);
			}
			else {
				//Is there a way for select to give us which File Descriptor that woke it?
				for(i = 0; i < NUM_CHILDREN; i++) {
					if(FD_ISSET(pipes[i].pipe[READ], &reads)) {
						nbytes = read(pipes[i].pipe[READ], readBuffer, sizeof(readBuffer));
						if(nbytes > 0) {
							printf(readBuffer);
							//writeToFile(readBuffer);
							count++;
						}
					}
				}
			}
			//1000 converts seconds to milliseconds
			if(getTimeInMilli() - startTime >= terminateProcessTime * 1000) {
				finished = true;
			}
		}
}
