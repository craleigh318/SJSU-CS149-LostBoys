/*
 * WorstFitSwapping.cpp
 *
 *  Created on: Mar 11, 2015
 *      Author: Saurav
 */

#include "WorstFitSwapping.h"


bool startWorstFit(MainMemory * memory, Process* process) {
	std::vector<Partition> holes = Partition::getHolesInMemory(memory);
	int holeSize = 0;
	int maxSize = 0;
	int maxindex = 0;
	for (int i=0; i < holes.size(); i++) {
			holeSize = holes.at(i).getSize();
			if(holeSize > maxSize) {
				maxSize = holeSize;
				maxindex = i;
			}
		}
    if (process->getSize() <= maxSize) {
        holes.at(maxindex).addProcess(process);
        return true;
    }
    else {
    	return false;
    }
}


