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

void create_time_stamp(int time, char * destination) {
	int minute = time / 60;
	int seconds = time % 60;
	sprintf(destination, "%i:%02d", minute, seconds);
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
                add_print_job(&mainPrintQueue, "ERROR: Invalid Student type");
		}

		if(gsQueue.length > 0)
			process_student_queue(&gsQueue, &sect1, &sect2, &sect3, studentsThread);
		if(rsQueue.length > 0)
			process_student_queue(&rsQueue, &sect1, &sect2, &sect3, studentsThread);
		if(eeQueue.length > 0)
			process_student_queue(&eeQueue, &sect1, &sect2, &sect3, studentsThread);
        char complete[10];
        create_time_stamp(currTime, complete);
        add_print_job(&mainPrintQueue, complete);
		currTime = currTime + 1;
	}

    add_print_job(&mainPrintQueue, "Section 1");
	print_section(sect1);
    add_print_job(&mainPrintQueue, "Section 2");
	print_section(sect2);
    add_print_job(&mainPrintQueue, "Section 3");
	print_section(sect3);
}

int main(int argc, const char * argv[]) {
    mainPrintQueue = new_print_queue();
    initialize_global_variables();
    srand((unsigned int)time(NULL));

	start_enrollment_process();
    add_print_job(&mainPrintQueue, "FINISHED");

    // insert code here...
    PrintQueue * mainPrintQueuePtr = &mainPrintQueue;
    add_print_job(mainPrintQueuePtr, string1);
    add_print_job(mainPrintQueuePtr, string2);
    pthread_join(mainPrintThread, NULL);

    pthread_exit(NULL);

    return 0;
}
