/*
 * round_robin.h
 *
 *  Created on: Feb 12, 2015
 *      Author: Saurav
 */

#ifndef ROUND_ROBIN_H_
#define ROUND_ROBIN_H_
#include "system_headers.h"
#include "ready_queue.h"
#include "scheduler_statistics.h"

/*
 First come, first served scheduling alogirthm.
 */
void exec_round_robin(struct ready_queue readyQueue, struct scheduler_statistics statistics);

void round_robin(struct ready_queue readyQueue);

#endif /* ROUND_ROBIN_H_ */
