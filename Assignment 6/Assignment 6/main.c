//
//  main.c
//  Assignment 6
//
//  Created by Christopher Raleigh on 2015/15/04.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "SystemHeaders.h"
#include "GlobalVariables.h"
#include "Child.h"

double startTime;
bool finished;

//void writeToFile(char* message) {
//    FILE *fp;
//    fp = fopen("output.txt", "a+");
//	fprintf(fp, message);
//}

double getTimeInMilli() {
    struct timeval  tv;
    double retTimeInMilli;
    gettimeofday(&tv, NULL);
    retTimeInMilli = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
    return retTimeInMilli;
}

void createTimestamp(char *buf) {
    char retString[10];
    double curTime;
    curTime = getTimeInMilli();
    int difference = curTime - startTime;
    int second = (int) floor((double) (difference / 1000));
    sprintf(retString, "%i:%02i.%03i", second / 60, second % 60, difference);
    strcpy(buf,retString);
}

void sendMessages(int * pipe, int childID) {
    char passString[100];
    int messageCount = 0;
    if(close(pipe[READ]) == -1) {
        perror("ERROR: Child Closing Read");
        exit(1);
    }
    while(!finished) {
        randomSleepTime();
        createTimestamp(passString);
        sprintf(passString, "%s: Child %i message %i\n", passString, childID, ++messageCount);
        write(pipe[WRITE], passString, strlen(passString) + 1);
    }
    
    if(close(pipe[WRITE]) == -1) {
        perror("ERROR: Child Closing Write");
        exit(1);
    }
    //Not sure if this exit call is needed
    exit(0);
}

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
    int pipe[2];
    Child c = newChild(1, pipe);
    runChild(&c);
}

int main2(int argc, const char * argv[]) {
    time(&initialTime);
    struct timeval  tv;
    gettimeofday(&tv, NULL);
    double time_in_mill = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;
    startTime = time_in_mill;
    printf("Hello, World!\n");
    
    /*
     Create 5 pipes.
     Each pipe has 2 integers.
     */
    finished = false;
    int pipes[NUM_CHILDREN][2];
    pid_t parentID = getpid();
    pid_t childID[NUM_CHILDREN];
    
    int i = 0;
    for (i = 0; i < NUM_CHILDREN; ++i) {
        //Open pipe
        if(pipe(pipes[i]) == -1) {
            perror("ERROR: Pipe Creation");
            exit(1);
        }
        //Create new child
        fflush(0);
        if((childID[i] = fork()) == -1) {
            perror("ERROR: Fork");
            exit(1);
        }
        //Child process
        if (parentID != getpid()) {
        	if(i == 4)
        		inputMessage(pipes[i], i + 1);
        	else
        		sendMessages(pipes[i], i + 1);
        }
    }
    //Parent process
    if(parentID == getpid()) {
    	char readBuffer[100];
		int activity, nbytes, max_fd;
    	fd_set readfds;
		FD_ZERO(&readfds);
		for(i = 0; i < NUM_CHILDREN; i++) {
	    	if(close(pipes[i][WRITE]) == -1){
	    		perror("ERROR: Parent Closing Write");
	    		exit(1);
	    	}
	    	int flags = fcntl(pipes[i][READ], F_GETFL, 0);
	    	fcntl(pipes[i][READ], F_SETFL, flags | O_NONBLOCK);

			FD_SET(pipes[i][READ], &readfds);

			if(max_fd < pipes[i][READ])
				max_fd = pipes[i][READ];
		}

		//Temporary while condition, change when we get timing solved
		//Currently exiting when all children ports are read from
		int count = 0;
    	while(!finished) {
    		//Timeout struct
    		struct timeval tv;
    		tv.tv_sec = 4;
    		tv.tv_usec = 0;

    		activity = select(max_fd + 1, &readfds, NULL, NULL, &tv);
    		if(activity == 0) {
    			printf("Timed out\n");
    			count++;
    		}
    		else if(activity < 0) {
    			printf("Error\n");
    			exit(1);
    		}
    		else {
				//Is there a way for select to give us which File Descriptor that woke it?
				for(i = 0; i < NUM_CHILDREN; i++) {
					nbytes = read(pipes[i][READ], readBuffer, sizeof(readBuffer));
					if(nbytes > 0) {
						printf(readBuffer);
						//writeToFile(readBuffer);
						count++;
					}
				}
    		}
    		//1000 converts seconds to milliseconds
    		if(getTimeInMilli() - startTime >= terminateProcessTime * 1000) {
    			finished = true;
    		}
    	}
    }
    return 0;
}
