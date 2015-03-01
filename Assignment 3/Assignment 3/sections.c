/*
 * sections.c
 *
 *  Created on: Feb 18, 2015
 *      Author: Saurav
 */
#include "sections.h"

Sections newSections() {
    Sections new_Sections = {
        SIZE_OF_CLASS
    };
    return new_Sections;
}

/*
Pthread_create | Create a new thread
Pthread_exit | Terminate the calling thread
Pthread_join | Wait for a specific thread to exit
Pthread_yield | Release the CPU to let another thread run
Pthread_attr_init | Create and initialize a thread's attribute structure
Pthread_attr_destory | Remove a thread's attribute structure 
Actually, the PThreads function names are all in lower case:
pthread_create, pthread_exit, pthread_attr_init
Sem_wait(&emptySlotsAvailable) - wait on the emptySlotsAvailable semaphore (lock)
sem_post(&filledSlotsAvailable) - signal the "filledslotsavailable semaphore wake up (unlock)
*/



bool add_student_to_section(Sections* section, Student student) {
	if(section->seatsLeft > 0) // If the section the student is trying to add into has seats open to be added into 
	{
		pthread_mutex_lock(&mutex);
		Student std = pop_student_queue(student); // Pop the student from the head of the queue 
		section->addedStudents[SIZE_OF_CLASS - section->seatsLeft] = std; // Add the student into the section 
		section->seatsLeft--;
		pthread_mutex_unlock(&mutex);
		return true;
	}
	else
		++studentsDropped;
		return false; // Student unable to be added into section
	
}

void print_section(Sections section) {
	for(int i = 0; i < SIZE_OF_CLASS - section.seatsLeft; i++) {
		print_student(section.addedStudents[i]);
	}
}


int get_random_section() {
	return (rand() % 4) + 1;
}
