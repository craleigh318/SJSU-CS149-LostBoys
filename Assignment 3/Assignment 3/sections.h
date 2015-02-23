/*
 * sections.h
 *
 *  Created on: Feb 18, 2015
 *      Author: Saurav
 */

#ifndef SECTIONS_H_
#define SECTIONS_H_
#include "system_headers.h"


typedef struct {
    int seats_left;

    pthread_mutex_t lock;
} Sections;

/*
 Returns a new set of sections with the specified ID.
 */
Sections newSections();

/*
 Returns a random section
 1 = Section 1
 2 = Section 2
 3 = Section 3
 4 = no preference
 */
int get_random_section();


#endif /* SECTIONS_H_ */
