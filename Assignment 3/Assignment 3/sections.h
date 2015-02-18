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
    int section1_chairs;
    int section2_chairs;
    int section3_chairs;
}Sections;

/*
 Returns a new set of sections with the specified ID.
 */
Sections newSections();


#endif /* SECTIONS_H_ */
