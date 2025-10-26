//Dawar Abbas # Reg No. 1144
//Q1 creating 5 threads and printing their ids

#include<stdio.h>
#include<pthread.h>  //Library providing built in functions for thread related activities 
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

//pointer function for creating threads
void *threadCreator_function(void *arg){
    int thread_number = *(int *)arg;    //Cast void back to integer
    printf("This is thread number: %d and with ID started: %lu\n",thread_number,pthread_self());
    int sleepTime = (rand() % 4) + 1;
    sleep(sleepTime);

    printf("Thread %d completed after %d\n",thread_number,sleepTime);
    return NULL;
}

int main( ) {
    pthread_t thread_id[5];
    int thread_number[5];

    for (int i = 0; i < 5; i++)
    {
        thread_number[i] = i + 1;  //initializing thread numbers
        pthread_create(&thread_id[i],NULL,threadCreator_function,&thread_number[i]);  //Creating threads


    }

    //Now we will wait for all threads to complete
    for (int i = 0; i < 5; i++)
    {
        pthread_join(thread_id[i], NULL);
    }
    printf("All threads completed\n");  //Message when all threads complete
    return 0;
}
