//Dawar Abbas # Reg No. 1144
//Q2 creating greeting thread

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
// Thread function - for creating new threads
void *thread_function(void *arg)
{
    char *name = (char *) arg;
    printf("Hello! %s from the new thread!\n",name);
    printf("Thread ID: %lu\n", pthread_self());
    return NULL;
}
int main()
{
    pthread_t thread_id;

    char name[] = "Dawar";

    printf("Main thread waiting for greeting...\n");
    // Create a new thread
    pthread_create(&thread_id, NULL, thread_function, &name);
    // Wait for the thread to finish
    pthread_join(thread_id, NULL);
    printf("Main thread: Greeting Completed...\n");
    return 0;
}