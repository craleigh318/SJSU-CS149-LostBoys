/*
 * NextFitSwapping.h
 *
 *  Created on: Mar 9, 2015
 *      Author: jr
 */

#ifndef NEXTFITSWAPPING_H_
#define NEXTFITSWAPPING_H_

#include "SystemHeaders.h"
#include "Partition.h"
#include "Process.h"
#include "MainMemory.h"

int incrementI(int i, int addition, int numHoles);

bool startNextFit(MainMemory * memory, Process* process);

#endif /* NEXTFITSWAPPING_H_ */
