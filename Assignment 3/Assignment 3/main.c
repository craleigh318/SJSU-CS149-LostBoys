//
//  main.c
//  Assignment 3
//
//  Created by Christopher Raleigh on 2015/17/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "system_headers.h"
#include "print_queue.h"
#include "student_queue.h"
#include "student_type.h"
#include "global_variables.h"

typedef struct threadParams {

};

int main(int argc, const char * argv[]) {
    initialize_global_variables();
    srand((unsigned int)time(NULL));

    pthread_t studentsThread[MAX_STUDENTS];
	StudentQueue rsQueue = new_student_queue();
	StudentQueue gsQueue = new_student_queue();
	StudentQueue eeQueue = new_student_queue();

	for(int i = 0; i < MAX_STUDENTS; i++) {
		Student currStudent = new_student(i + 1);
		currStudent.thread = pthread_create(&studentsThread[i], NULL, process_student, (void *) i);
		if(currStudent.thread) {
			printf("ERROR: Could not create thread. Error code %i\n", (int) currStudent.thread);
			return -1;
		}

		if(currStudent.type == gs)
			push_student_queue(&gsQueue, currStudent);
		else if(currStudent.type == rs)
			push_student_queue(&rsQueue, currStudent);
		else if(currStudent.type == ee)
			push_student_queue(&eeQueue, currStudent);
		else
			puts("ERROR: Invalid Student type");
	}

	puts("rsQueue");
	print_student_queue(rsQueue);
	puts("gsQueue");
	print_student_queue(gsQueue);
	puts("eeQueue");
	print_student_queue(eeQueue);

    // insert code here...
    
    char string1[] = "Hello, World!";
    char string2[] = "Hello, Self!";
    PrintQueue mainPrintQueue = new_print_queue();
    PrintQueue * mainPrintQueuePtr = &mainPrintQueue;
    add_print_job(mainPrintQueuePtr, string1);
    add_print_job(mainPrintQueuePtr, string2);
    pthread_join(mainPrintThread, NULL);

    pthread_exit(NULL);

    return 0;
}
