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
	
	// Simulate each student with a thread , there will be 75 students 
	for(int i = 0; i < MAX_STUDENTS; i++) {
		Student currStudent = new_student(i + 1);
		push_student_queue(&studentList, currStudent);
	}
	sort_students_arrival(&studentList); // sort simulated students in arrival time order starting at 0 to 2 minutes 
	
	// Student enters at tail of queue and exits at head & all three work simulatenously , but can only enroll 1 student at a time 
	StudentQueue rsQueue = new_student_queue(); // A queue for regular seniors 
	StudentQueue gsQueue = new_student_queue(); // A queue for graduating seniors 
	StudentQueue eeQueue = new_student_queue(); // A queue for everyone else 

	// Create 3 sections 
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
			process_student_queue(&gsQueue, &sect1, &sect2, &sect3, studentsThread);
		if(rsQueue.length > 0)
			process_student_queue(&rsQueue, &sect1, &sect2, &sect3, studentsThread);
		if(eeQueue.length > 0)
			process_student_queue(&eeQueue, &sect1, &sect2, &sect3, studentsThread);
		printf("%s \n", create_time_stamp(currTime));
		currTime = currTime + 1;
	}

	puts("Section 1");
	print_section(sect1);
	puts("Section 2");
	print_section(sect2);
	puts("Section 3");
	print_section(sect3);
}

int main(int argc, const char * argv[]) {
    initialize_global_variables();
    srand((unsigned int)time(NULL));

	start_enrollment_process();
	printf("FINISHED");

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
