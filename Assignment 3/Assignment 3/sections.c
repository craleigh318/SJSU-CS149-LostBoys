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

bool add_student_to_section(Sections* section, Student student) {
	if(section->seatsLeft > 0)
	{
        addStudent(); // succesfully added student
		pthread_mutex_t *mutex = &section->lock;
        pthread_mutex_lock(mutex);
        // TODO: pass student queue into this function and uncomment the line below.
        int seatsTaken = SIZE_OF_CLASS - section->seatsLeft;
        section->addedStudents[seatsTaken] = student;
        section->seatsLeft--;
        // printf("Student: %d enrolled\n", student.idNumber);
        pthread_mutex_unlock(mutex);
		return true;
	}
    /*
	else if (student.idNumber == 4) // No more open sections
    {
        return false;
    }
    */
    else // All are filled
    {
    dropStudent();
    // printf("Student: %d dropped\n", student.idNumber);
    return false;
    }
}

void print_section(Sections section) {
	for(int i = 0; i < SIZE_OF_CLASS - section.seatsLeft;i++)
		print_student(section.addedStudents[i]);
}

int get_random_section() {
	return (rand() % 4) + 1;
}
