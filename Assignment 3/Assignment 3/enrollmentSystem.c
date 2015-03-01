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
//int parforeCount = 0;

int firstPrint = 1;

// Print a line for each event:
//   elapsed time
//   who is enrolling with the system
//   who is waiting in the chairs
//   what event occurred
void print(char *event)
{
    time_t now;
    time(&now);
    double elapsed = difftime(now, startTime);
    int min = 0;
    int sec = (int) elapsed;

    if (sec >= 60) {
        min++;
        sec -= 60;
    }

    // Acquire the mutex lock to protect the printing.
    pthread_mutex_lock(&printMutex);

    if (firstPrint) {
        printf("TIME |ENROLLING| WAITING                 | EVENT\n");
        firstPrint = 0;
    }

    if (sec >= 60) {
            min++;
            sec -= 60;
        }

    // Elapsed time.
    printf("%1d:%02d | ", min, sec);

    // Who's enrolling with the system.
    if (enrollmentId > 0) {
        printf("%5d   |", enrollmentId);
    }
    else {
        printf("        |");
    }

    // Acquire the mutex lock to protect the chairs and the wait count.
    pthread_mutex_lock(&chairMutex);

    int i = out;
    int j = waitCount;
    int k = 0;

    // Who's waiting in the chairs.
    while (j-- > 0 && k < 5) {
        printf("%4d", chairs[i]);
        i = (i+1)%CHAIR_COUNT;
        k++;
    }

    // Release the mutex lock.
    pthread_mutex_unlock(&chairMutex);

    // What event occurred.
    while (k++ < 5) printf("    ");
    if(j > 0) {
    printf(" ...");
    }
    else {
    printf("    ");
    }

    printf(" | %s\n", event);

    // Release the mutex lock.
    pthread_mutex_unlock(&printMutex);
}

// A student arrives.
void studentArrives(int id)
{
    char event[80];
    arrivalsCount++;

    if (waitCount < CHAIR_COUNT) {

        // Acquire the mutex lock to protect the chairs and the wait count.
        pthread_mutex_lock(&chairMutex);

        // Seat a student into a chair.
        chairs[in] = id;
        in = (in+1)%CHAIR_COUNT;
        waitCount++;

        // Release the mutex lock.
        pthread_mutex_unlock(&chairMutex);

        sprintf(event, "Student %d arrives and waits", id);
        print(event);

        // Signal the "filledSlots" semaphore.
        sem_post(&filledChairs);  // signal
    }
    else {
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
			print(event);
			sections[section]--;
        }
    }
}

// The enrollment system thread.
void *enroll_System(void *param)
{
    print("System begins enrollment period");

    // Set the timer for enrollment period.
    sysTimer.it_value.tv_sec = SYSTEM_ENROLLMENT_DURATION;
    setitimer(ITIMER_REAL, &sysTimer, NULL);

    // Enroll students until the enrollment period is over.
    do {
    SystemEnrollsStudent();
    } while (!timesUp && enrolledChairs < CHAIR_COUNT);

    print("Enrollment period ends");
    return NULL;
}

// Timer signal handler.
void timerHandler(int signal)
{
    timesUp = 1;  // office hour is over
}

// Main.
int main(int argc, char *argv[])
{
    int studentIds[STUDENT_COUNT];
    int systemId = 0;

    // Initialize the mutexes and the semaphore.
    pthread_mutex_init(&chairMutex, NULL);
    pthread_mutex_init(&printMutex, NULL);
    sem_init(&filledChairs, 0, 0);

    srand((unsigned int)time(0));
    time(&startTime);

    // Create the system thread.
    pthread_t systemThreadId;
    pthread_attr_t profAttr;
    pthread_attr_init(&profAttr);
    pthread_create(&systemThreadId, &profAttr, enroll_System, &systemId);

    // Create the student threads.
    int i;
    for (i = 0; i < STUDENT_COUNT; i++) {
        studentIds[i] = ID_BASE + i;
        pthread_t studentThreadId;
        pthread_attr_t studentAttr;
        pthread_attr_init(&studentAttr);
        pthread_create(&studentThreadId, &studentAttr, student, &studentIds[i]);
    }

    // Set the timer signal handler.
    signal(SIGALRM, timerHandler);

    // Wait for the enrollment system to complete the enrollment period.
    pthread_join(systemThreadId, NULL);

    // Remaining waiting students leave.
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
