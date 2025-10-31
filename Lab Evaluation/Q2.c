// Solution to previous problem

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3
#define NUM_OF_INCREMENTS 1000

int counter = 0; // A global variable for shared memory


// Make the Object of mutex
pthread_mutex_t mutex;

// A function for threads to increment the counter
void *counter_function(void *arg)
{

    pthread_mutex_lock(&mutex);
    for (int i = 0; i < NUM_OF_INCREMENTS; i++)
    {
        // counter increment
        counter++;
    }
    pthread_mutex_unlock(&mutex);
    return NULL;

}

int main()
{
    pthread_t thread[NUM_THREADS];

    pthread_mutex_init(&mutex,NULL);

    // Creation of thread function and passing arguments
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&thread[i], NULL, counter_function, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        // Thread joining
        pthread_join(thread[i], NULL);
    }

    // Printing the value of shared variable counter
    printf("The final value of counter function is: %d\n", counter);


    pthread_mutex_destroy(&mutex);

    return 0;
}