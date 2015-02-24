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
#include "student.h"
#include "sections.h"
#include "global_variables.h"

#define END_TIME 120

int main(int argc, const char * argv[]) {
    initialize_global_variables();
    srand((unsigned int)time(NULL));

    pthread_t studentsThread[MAX_STUDENTS];
	StudentQueue rsQueue = new_student_queue();
	StudentQueue gsQueue = new_student_queue();
	StudentQueue eeQueue = new_student_queue();

	Sections sect1 = newSections();
	Sections sect2 = newSections();
	Sections sect3 = newSections();

	for(int i = 0; i < MAX_STUDENTS; i++) {
		Student currStudent = new_student(i + 1);

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

//	int i = 0;
//	ThreadParams pass = {
//			rsQueue.students[0],
//			{sect1, sect2, sect3}
//	};
//	ThreadParams* passed = &pass;
//	pthread_t thread = pthread_create(&studentsThread[i], NULL, process_student, passed);
//	if(thread) {
//		printf("ERROR: Could not create thread. Error code %i\n", (int) thread);
//		return -1;
//	}

//	int currTime = 0;
//	while(currTime < END_TIME) {
//		Student currStudent;
//		if(peek_student_queue(gsQueue).arrivalTime < currTime) {
//			currStudent = pop_student_queue(&gsQueue);
//
//			threadParams pass = {
//					currStudent,
//					{sect1, sect2, sect3}
//			};
//			threadParams* passed = &pass;
//			currStudent.thread = pthread_create(&studentsThread[i], NULL, process_student, passed);
//			if(currStudent.thread) {
//				printf("ERROR: Could not create thread. Error code %i\n", (int) currStudent.thread);
//				return -1;
//			}
//			i++;
//		}
//		currTime++;
//	}

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
