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
    pthread_t studentsThread[MAX_STUDENTS]; // Creating 75 student threads 
    StudentQueue studentList = new_student_queue(); // Create a student thread queue 
	
	// Simulate each student with a thread , there will be 75 students 
	for(int i = 0; i < MAX_STUDENTS; i++) {
		Student currStudent = new_student(i + 1); // Gets an ID number with random student_type, section , and arrival time 
		push_student_queue(&studentList, currStudent); // Get currStudent and push them into their respectful queue depending on student_type 
	}
	sort_students_arrival(&studentList); // sort simulated students in arrival time order starting at 0 to 2 minutes in student_queue.c file
	
	// Student enters at tail of queue and exits at head & all three work simulatenously , but can only enroll 1 student at a time 
	StudentQueue rsQueue = new_student_queue(); // A queue for regular seniors 
	StudentQueue gsQueue = new_student_queue(); // A queue for graduating seniors 
	StudentQueue eeQueue = new_student_queue(); // A queue for everyone else 

	// Create 3 sections 
	Sections sect1 = newSections(); 
	Sections sect2 = newSections();
	Sections sect3 = newSections();

	int currTime = 0;
	while(currTime <= END_TIME) // while 0 seconds <= 180 seconds 
		 {
		while(studentList.length > 0 & peek_student_queue(studentList).arrivalTime == currTime) // While students in studentList and one of them arrive
		 {
			Student currStudent = pop_student_queue(&studentList); // Pop that student from their respectful queue & // Identify are they GS,RS,EE 
			if (currStudent.type == gs) 
				push_student_queue(&gsQueue, currStudent); // push into GS queue 
			else if (currStudent.type == rs) // Push into RS queue 
				push_student_queue(&rsQueue, currStudent);
			else if (currStudent.type == ee) // Push into EE queue 
				push_student_queue(&eeQueue, currStudent);
			else
                print_pq("ERROR: Invalid Student type"); // There was a problem with the student's type, they were not a GS,RS,EE 
		}

		if(gsQueue.length > 0)
			process_student_queue(&gsQueue, &sect1, &sect2, &sect3, studentsThread);
		if(rsQueue.length > 0)
			process_student_queue(&rsQueue, &sect1, &sect2, &sect3, studentsThread);
		if(eeQueue.length > 0)
			process_student_queue(&eeQueue, &sect1, &sect2, &sect3, studentsThread);
        char complete[10];
        create_time_stamp(currTime, complete);
        print_pq(complete);
		currTime = currTime + 1;
	}

    print_pq("Section 1");
	print_section(sect1);
    print_pq("Section 2");
	print_section(sect2);
    print_pq("Section 3");
	print_section(sect3);
}

int main(int argc, const char * argv[]) {
    initialize_global_variables(); // set ProgramIsEnding to false;
    printQueue = new_threaded_queue(); // Create threads for queues 
    srand((unsigned int)time(NULL));

	start_enrollment_process(); // Add students from queues into sections 
    print_pq("FINISHED");

    // insert code here...
    pthread_join(printThread, NULL);

    pthread_exit(NULL);

    return 0;
}
