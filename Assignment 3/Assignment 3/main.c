//
//  main.c
//  Assignment 3
//
//  Created by Christopher Raleigh on 2015/17/02.
//  Copyright (c) 2015 Lost Boys. All rights reserved.
//

#include "system_headers.h"
#include "print_queue.h"
#include "student_queue.h"
#include "student_type.h"
#include "global_variables.h"

void create_time_stamp(int time, char * destination) {
    int minute = time / 60;
    int seconds = time % 60;
    sprintf(destination, "%i:%02d", minute, seconds);
}

void print_results()
{
    char str[30], strr[30], strrr[30];
    char *str1 = "students enrolled.";
    char *str2 = "students dropped.";
    char *str3 = "students arrived late.";
    int add = getStudentAdded();
    int drop = getStudentDropped();
    int late = 75 - (add + drop);
    sprintf(str, "%i %s " , add , str1);
    sprintf(strr,"%i %s " , drop, str2);
    sprintf(strrr,"%i %s " , late, str3);
    print_pq(str);
    print_pq(strr);
    print_pq(strrr);
    int totalTime = getTotal();
    int totalGSTime = getTotalGS();
    int totalRSTime = getTotalRS();
    int totalEETime = getTotalEE();

    float averageTimeGS = ((float)totalGSTime)/75.0f;
    char num4[100];
	sprintf(num4, "%f : average turnaround time for GS Queue seconds" , averageTimeGS);
	print_pq(num4);

    float averageTimeRS = ((float)totalRSTime)/75.0f;
    char num3[100];
	sprintf(num3, "%f : average turnaround time for RS Queue seconds" , averageTimeRS);
	print_pq(num3);

    float averageTimeEE = ((float)totalEETime)/75.0f;
    char num2[100];
	sprintf(num2, "%f : average turnaround time for EE Queue seconds" , averageTimeEE);
	print_pq(num2);

    float averageTime = ((float)totalTime)/75.0f;
    char num[100];
    sprintf(num, "%f : average turnaround time seconds" , averageTime);
    print_pq(num);
}

void start_enrollment_process() {
    Student studentList[MAX_STUDENTS];
    for(int i = 0; i < MAX_STUDENTS; i++) {
        Student currStudent = new_student(i + 1);
        studentList[i] = currStudent;
    }
    sort_students_arrival(studentList);
    
    StudentQueue mainStudentQueue = new_student_queue();
    
    
    int j;
    for (j = 0; j < MAX_STUDENTS; ++j) {
        push_student_queue(&mainStudentQueue, studentList[j]);
    }
    StudentQueue rsQueue = new_student_queue();
    StudentQueue gsQueue = new_student_queue();
    StudentQueue eeQueue = new_student_queue();
    
    Sections sect1 = newSections();
    Sections sect2 = newSections();
    Sections sect3 = newSections();
    
    while(currTime <= END_TIME)
    {
        if (peek_student_queue(mainStudentQueue).arrivalTime <= currTime)
        {
            Student currStudent = pop_student_queue(&mainStudentQueue);
            if (currStudent.type == gs) {
                (push_student_queue(&gsQueue, currStudent));
            }
            else if (currStudent.type == rs) 	{
                (push_student_queue(&rsQueue, currStudent));
            }
            else if (currStudent.type == ee) 	{
                (push_student_queue(&eeQueue, currStudent));
            }
            else
                print_pq("ERROR: Invalid Student type");
        }
        
        if(gsQueue.length > 0)
            process_student_queue(&gsQueue, &sect1, &sect2, &sect3, studentsThread,currTime);
        if(rsQueue.length > 0)
            process_student_queue(&rsQueue, &sect1, &sect2, &sect3, studentsThread,currTime);
        if(eeQueue.length > 0)
            process_student_queue(&eeQueue, &sect1, &sect2, &sect3, studentsThread,currTime);
        
        char complete[10];
        create_time_stamp(currTime, complete);
        print_pq(complete);
        currTime = currTime + 1;
        sleep(1);
    }
    
    print_pq("Section 1");
    print_section(sect1);
    print_pq("Section 2");
    print_section(sect2);
    print_pq("Section 3");
    print_section(sect3);
}


int main(int argc, const char * argv[]) {
    printf("Start of program\n");
    initialize_global_variables();
    printQueue = new_threaded_queue();
    srand((unsigned int)time(NULL));
    start_enrollment_process();
    pthread_join(printThread, NULL);
    print_pq("JOINING THREADS. PLEASE WAIT.");
    
    // insert code here above here. Not below because it won't show
    int i;
    for (i = 0; i < MAX_STUDENTS; ++i) {
        pthread_join(studentsThread[i], NULL);
    }
    print_results();
    print_pq("FINISHED");
    pthread_join(printThread, NULL);
    pthread_exit(NULL);
    return 0;
}
