//Dawar Abbas # Reg No. 1144
//Thread for calculating square, cube and number it self

#include <stdio.h>
#include <pthread.h>
void *print_number(void *arg)
{
    // We know that we've passed an integer pointer
    int num = *(int *)arg; // Cast void* back to int*
    printf("Thread received number: %d\n", num);
    printf("Square: %d\n", num * num);
    printf("Cube: %d\n", num * num *num);
    return NULL;
}
int main()
{
    pthread_t thread_id;
    int number ;
    printf("Enter a number:");
    scanf("%d", &number);
    printf("Creating thread with argument: %d\n", number);
    // Pass address of 'number' to thread
    pthread_create(&thread_id, NULL, print_number, &number);
    pthread_join(thread_id, NULL);
    printf("Main thread: Work completed\n");
    return 0;
}