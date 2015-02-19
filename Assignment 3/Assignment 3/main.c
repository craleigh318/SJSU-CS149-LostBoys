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

int main(int argc, const char * argv[]) {
    pthread_t printerThread;
    
    pthread_create(&printerThread, NULL, &thread_for_print_queue, NULL);
    
    srand((unsigned int)time(NULL));

	Student studentList[MAX_STUDENTS];
	for(int i = 0; i < MAX_STUDENTS; i++) {
		studentList[i] = new_student(i + 1);
	}

	StudentQueue rsQueue = new_student_queue();
	StudentQueue gsQueue = new_student_queue();
	StudentQueue eeQueue = new_student_queue();

	for(int i = 0; i < MAX_STUDENTS; i++) {
		Student currStudent = studentList[i];
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
    add_print_job(&mainPrintQueue, string1);
    add_print_job(&mainPrintQueue, string2);
    return 0;
}
