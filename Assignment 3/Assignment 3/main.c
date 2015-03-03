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
    char str[30], strr[30];
    char *str1 = "students enrolled.";
    char *str2 = "students dropped.";
    int add = getStudentAdded();
    int drop = getStudentDropped();
    sprintf(str, "%i %s " , add , str1);
    sprintf(strr,"%i %s " , drop, str2);
    print_pq(str);
    print_pq(strr);
    int totalTime = getTotal();
    char num2[50];
    sprintf(num2,"%i : total turnaround time seconds", totalTime);
    print_pq(num2);
    float averageTime = ((float)totalTime)/75.0f;
    char num[50];
    sprintf(num, "%f : average turnaround time seconds" , averageTime);
    print_pq(num);
}

void start_enrollment_process() {
    pthread_t studentsThread[MAX_STUDENTS];
    Student studentList[MAX_STUDENTS];
    for(int i = 0; i < MAX_STUDENTS; i++) {
        Student currStudent = new_student(i + 1);
        studentList[i] = currStudent;
    }
    sort_students_arrival(studentList);
    
    StudentQueue mainStudentQueue = new_student_queue();
    
    int currTime = 0;
    int j;
    for (j = 0; j < MAX_STUDENTS; ++j) {
        push_student_queue(&mainStudentQueue, studentList[j], currTime);
    }
    StudentQueue rsQueue = new_student_queue();
    StudentQueue gsQueue = new_student_queue();
    StudentQueue eeQueue = new_student_queue();
    
    Sections sect1 = newSections();
    Sections sect2 = newSections();
    Sections sect3 = newSections();
    
    while(currTime <= END_TIME)
    {
        while(mainStudentQueue.length > 0 & peek_student_queue(mainStudentQueue).arrivalTime == currTime)
        {
            Student currStudent = pop_student_queue(&mainStudentQueue);
            if (currStudent.type == gs) {
                addTotal(push_student_queue(&gsQueue, currStudent, currTime));
            }
            else if (currStudent.type == rs) 	{
                addTotal(push_student_queue(&rsQueue, currStudent, currTime));
            }
            else if (currStudent.type == ee) 	{
                addTotal(push_student_queue(&eeQueue, currStudent, currTime));
            }
            else
                print_pq("ERROR: Invalid Student type");
        }
        
        if(gsQueue.length > 0)
            process_student_queue(&gsQueue, &sect1, &sect2, &sect3, studentsThread);
        if(rsQueue.length > 0)
            process_student_queue(&rsQueue, &sect1, &sect2, &sect3, studentsThread);
        if(eeQueue.length > 0)
            process_student_queue(&eeQueue, &sect1, &sect2, &sect3, studentsThread);
        
        char complete[10];
        create_time_stamp(currTime, complete);
        print_pq(complete);
        currTime = currTime + 1;
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
    print_pq("FINISHED");
    print_results();
    // insert code here above here. Not below because it won't show
    pthread_join(printThread, NULL);
    pthread_exit(NULL);
    return 0;
}
