/*
 * sections.c
 *
 *  Created on: Feb 18, 2015
 *      Author: Saurav
 */
#include "sections.h"

Sections newSections() {
    // Creat a new section
    Sections new_Sections = {
        SIZE_OF_CLASS // 20????
    };
    return new_Sections; // return a new section
}

/*
pthread_create | Create a new thread
pthread_exit | Terminate the calling thread
pthread_join | Wait for a specific thread to exit
pthread_yield | Release the CPU to let another thread run
pthread_attr_init | Create and initialize a thread's attribute structure
pthread_attr_destory | Remove a thread's attribute structure
 
Sem_wait(&emptySlotsAvailable) - wait on the emptySlotsAvailable semaphore (lock)
sem_post(&filledSlotsAvailable) - signal the "filledslotsavailable semaphore wake up (unlock)
*/



bool add_student_to_section(Sections* section, Student student) {
	if(section->seatsLeft > 0) // If the section the student is trying to add into has seats open to be added into 
	{
		pthread_mutex_t *mutex = &section->lock;
        pthread_mutex_lock(mutex); // Lock this method so no other processes or queues can come in
        // TODO: pass student queue into this function and uncomment the line below.
        int seatsTaken = SIZE_OF_CLASS - section->seatsLeft;
        if( seatsTaken != 0 ) // If there is still room in the section
        {
            section->addedStudents[seatsTaken] = student; // Add the student into the section
            section->seatsLeft--;
        }
		pthread_mutex_unlock(mutex); // Unlock so other processes or queus can come in
		return true;
	}
	else
        ++studentsDropped; // Student unable to be added into section
		return false;
	
}

void print_section(Sections section) {
    int i;
	for(i = 0; i < SIZE_OF_CLASS - section.seatsLeft; i++) // i = 0; i < 20 - section.seatsLeft; i++
    {
		print_student(section.addedStudents[i]); // print out the students that were added into the given section
	}
}


int get_random_section() {
	return (rand() % 4) + 1; // returns random int from 1 -> 4
}
