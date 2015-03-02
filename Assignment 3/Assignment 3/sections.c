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
            studentAdded++; // Student succesfully added to class
        }
		pthread_mutex_unlock(mutex);
		return true;
	}
	else
        ++studentsDropped;
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
