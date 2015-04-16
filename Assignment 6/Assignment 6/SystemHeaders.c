#include "SystemHeaders.h"

void randomSleepTime()
{
  int number = random() * 3; // sleep for a random time of 0,1, or 2 seconds 
  sleep(number);
}
