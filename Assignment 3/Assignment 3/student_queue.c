/*
 * student_queue.c
 *
 *  Created on: Feb 18, 2015
 *      Author: Steve
 */

#include "student_queue.h"

StudentQueue new_student_queue() {
	StudentQueue new_queue = {
			0,
			-1
	};
	return new_queue;
}

void push_student_queue(StudentQueue* queue, Student student) {
	if (queue->length < MAX_STUDENTS) {
		queue->students[queue->length] = student;
		queue->length++;
	} else
		puts("ERROR: Could not push Student to Queue. Enlarge the queue.");
}

Student pop_student_queue(StudentQueue* queue)  {
	Student ret_student = new_student(-1);
	if(queue->length > 0) {
		ret_student = queue->students[0];
		queue->length--;
		memmove(&queue->students[0], &queue->students[1], sizeof(queue->students) - sizeof(*queue->students));
	}
	else
		puts("ERROR: Could not pop a Student from queue. No more students in queue.");
	return ret_student;
}

void print_student_queue(StudentQueue queue) {
	for(int i = 0; i < queue.length; i++) {
		Student curr_student = queue.students[i];
		printf("Student %2i   Type: %i\n", curr_student.idNumber, curr_student.type);
	}
}

void* process_student(void* threadId) {
	   long tid;
	    tid = (long)threadId;
	    printf("last thread #%ld!\n", tid);
	    pthread_exit(NULL);
}

