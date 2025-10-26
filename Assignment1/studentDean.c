// Dawar Abbas # Reg No. 1144
// using structure and checking deans list eligibility

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct
{
    int studentId;
    char name[40];
    float gpa;
} studentList;

int deanCounter = 0;       // shared variable
pthread_mutex_t synchLock; // object of mutex

void *checkDeanList(void *arg)
{
    studentList *student = (studentList *)arg;

    printf("Student ID: %d\nStudent Name: %s\nStudent GPA: %.2f\n", student->studentId,student->name,student->gpa);

    if (student->gpa >= 3.5)
    {
        printf("Status: Eligible for Dean's List \n");

        pthread_mutex_lock(&synchLock); // protect shared variable
        deanCounter++;
        pthread_mutex_unlock(&synchLock); // Now unlock so next thread can work
    }
    else
    {
        printf("Status: Not Eligible\n\n");
    }

    return NULL;
}

int main()
{
    pthread_t threads[3];  //thread ids

    pthread_mutex_init(&synchLock, NULL);
    studentList students[3] = {    // initializing students list or database
        {101, "Ahmad Fawad", 3.8},
        {102, "Dawar Abbas", 3.2},
        {103, "Hussain Naveed", 3.6},
    };

    for (int i = 0; i < 3; i++)
    {
        pthread_create(&threads[i],NULL,checkDeanList,&students[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        pthread_join(threads[i],NULL);
    }

    printf("Total number of students in dean's list are: %d\n",deanCounter);
    pthread_mutex_destroy(&synchLock);   //Destroye mutex object
    return 0;
}
