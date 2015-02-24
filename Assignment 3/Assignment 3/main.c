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

#define END_TIME 120

char* create_time_stamp(int time) {
	char complete[10];
	int minute = time / 60;
	int seconds = time % 60;
	sprintf(complete, "%i:%02d", minute, seconds);
	return (char*) complete;
}

void start_enrollment_process() {
    pthread_t studentsThread[MAX_STUDENTS];
    StudentQueue studentList = new_student_queue();

	for(int i = 0; i < MAX_STUDENTS; i++) {
		Student currStudent = new_student(i + 1);
		push_student_queue(&studentList, currStudent);
	}
	sort_students_arrival(&studentList);

	StudentQueue rsQueue = new_student_queue();
	StudentQueue gsQueue = new_student_queue();
	StudentQueue eeQueue = new_student_queue();

	Sections sect1 = newSections();
	Sections sect2 = newSections();
	Sections sect3 = newSections();

	int currTime = 0;
	while(currTime <= END_TIME) {
		while(studentList.length > 0 &&
				peek_student_queue(studentList).arrivalTime == currTime) {
			Student currStudent = pop_student_queue(&studentList);
			if (currStudent.type == gs)
				push_student_queue(&gsQueue, currStudent);
			else if (currStudent.type == rs)
				push_student_queue(&rsQueue, currStudent);
			else if (currStudent.type == ee)
				push_student_queue(&eeQueue, currStudent);
			else
				puts("ERROR: Invalid Student type");
		}

		if(gsQueue.length > 0)
			process_student_queue(&gsQueue);
		if(rsQueue.length > 0)
			process_student_queue(&rsQueue);
		if(eeQueue.length > 0)
			process_student_queue(&eeQueue);
//		printf("%s \n", create_time_stamp(currTime));
		currTime = currTime + 1;
	}
}

int main(int argc, const char * argv[]) {
    initialize_global_variables();
    srand((unsigned int)time(NULL));

	start_enrollment_process();

//	threadParams pass = {
//			rsQueue.students[0],
//			{sect1, sect2, sect3}
//	};
//	threadParams* passed = &pass;
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
