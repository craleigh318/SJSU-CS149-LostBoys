#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <sys/time.h>

#define ID_BASE 101

#define CHAIR_COUNT 60
#define STUDENT_COUNT 75

//#define MAX_MEETING_DURATION 5
#define SYSTEM_ENROLLMENT_DURATION 120

// Built based on by an example multithreaded program
// by Ron Mak
// Department of Computer Science
// San Jose State University
//


int chairs[CHAIR_COUNT];     // circular buffer of chairs
pthread_mutex_t chairMutex;  // mutex protects chairs and wait count
pthread_mutex_t printMutex;  // mutex protects printing
sem_t filledChairs;          // system waits on this semaphore

struct itimerval sysTimer;  // system's enrollment period timer
time_t startTime;

int in = 0, out = 0;
int enrollmentId = 0;
int enrolledChairs = 0;
int sections[3] = {20,20,20};

int arrivalsCount = 0;
int waitCount = 0;
int dropCount = 0;
int enrollmentCount = 0;
    if (enrollmentId > 0) {
        printf("%5d   |", enrollmentId);
        dropCount++;
        sprintf(event, "Student %d arrives and leaves", id);
        print(event);
    }
}

// The student thread.
void *student(void *param)
{
    int id = *((int *) param);
//    int priority = rand()%4;

    // Students will arrive at random times during the enrollment period.
    sleep(rand()%SYSTEM_ENROLLMENT_DURATION);
    studentArrives(id);

    return NULL;
}

int timesUp = 0;  // 2 = enrollment period is over

// The system enrolls a student (or waits on a student).
void SystemEnrollsStudent()
{
    if (!timesUp && ((sections[0] + sections[1] + sections[2]) > 0 )) {

        // Wait on the "filledChairs" semaphore for a student.
        sem_wait(&filledChairs);

        // Acquire the mutex lock to protect the chairs and the wait count.
        pthread_mutex_lock(&chairMutex);

        // Critical region: Remove a student from a chair.
        enrollmentId = chairs[out];
        out = (out+1)%CHAIR_COUNT;
        waitCount--;

        // Release the mutex lock.
        pthread_mutex_unlock(&chairMutex);

        //Set the priority and section for each student at this point
        int priority = rand()%3; //GS = 0, RS = 1, EE = 2
        int section = (rand()%4); // sec1 = 0, sec2 = 1, sec3 = 2, Any = 3

        //For option '3': checks if there is space in sec1 and sec2, if not then section = sec3
        if(section == 3) {
            if(sections[0] > 0)
                section = 0;
            else if(sections[1] > 0)
                section = 1;
            else
                section = 2;
        }

        //Checks for available space in section and starts to enroll student
        if(sections[section] > 0) {
            char event[80];
            sprintf(event, "System begins processing student %d",  enrollmentId);
            print(event);

            // Enroll the student based on priority.
            if(priority == 0) {
            sleep(rand()%2 + 1);
            }
            else if(priority == 1) {
            sleep(rand()%3 + 2);
            }
            else {
            sleep(rand()%4 + 3);
            }

            //Completing enrollment of student
            enrollmentCount++;
            sprintf(event, "System finished enrolling student %d in section %d",  enrollmentId, section + 1);
            enrolledChairs++;
            enrollmentId = 0;
    enrollmentId = 0;
    while (waitCount-- > 0) {
        int studentId = chairs[out];
        out = (out+1)%CHAIR_COUNT;
        dropCount++;

        char event[80];
        sprintf(event, "Student %d was not enrolled",  studentId);
        print(event);
    }

    // Final statistics.
    printf("\n");
    printf("%5d students arrived\n", arrivalsCount);
    printf("%5d students were enrolled\n", enrollmentCount);
    printf("%5d students were unable to enroll\n", dropCount);
    printf("%5d students enrolled in section 1\n", 20 - sections[0]);
    printf("%5d students enrolled in section 2\n", 20 - sections[1]);
    printf("%5d students enrolled in section 3\n", 20 - sections[2]);

    return 0;
}