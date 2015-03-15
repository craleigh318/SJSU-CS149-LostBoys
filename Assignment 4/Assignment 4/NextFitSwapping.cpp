/*
 * NextFitSwapping.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: jr
 */

#include "NextFitSwapping.h"

static int LASTPOS = 0;

bool startNextFit(MainMemory * memory, Process* process) {
	std::vector<Partition> holes = Partition::getHolesInMemory(memory);
    int holesSize = (signed) holes.size();
    if (holesSize <= 0) {
        return false;
    }
    int i;
    for (i = LASTPOS; i < holesSize; ++i) {
        Partition & currentPartition = holes.at(i);
        if ((currentPartition.getFinalMB() >= LASTPOS)
            && currentPartition.addProcess(process)) {
            LASTPOS = currentPartition.getFirstMB();
            return true;
        }
    }
    // Loop if processes not added.
    for (i = 0; i < holesSize; ++i) {
        Partition & currentPartition = holes.at(i);
        if (currentPartition.addProcess(process)) {
            LASTPOS = currentPartition.getFirstMB();
            return true;
        }
    }
	return false;
}
