/*
Write a C program that demonstrates and fixes a race condition:



1.    Create a shared global variable                   initialized to 0

2.  Create 3 threads, each thread increments

3.  First version WITHOUT mutex:

  Create and run the 3 threads


1000 times in a loop

  Print the final counter value

  Run multiple times and observe inconsistent results

4.  Second version WITH mutex:

  Use mutex to protect the counter increment   Create and run the 3 threads

   Print the final counter value (should always be 3000)
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3
#define NUM_OF_INCREMENTS 100000

int counter = 0; // A global variable for shared memory

// A function for threads to increment the counter
void *counter_function(void *arg)
{

  for (int i = 0; i < NUM_OF_INCREMENTS; i++)
  {

    // counter increment
    counter++;
  }

  
  return NULL;
}

int main()
{
  pthread_t thread[NUM_THREADS];

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

  return 0;
}