#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
typedef struct
{
    int id;
    char *message;
} ThreadData;
void *printData(void *arg)
{
    ThreadData *data = (ThreadData *)arg;
    printf("Thread %d says: %s\n", data->id, data->message);
    return NULL;
}
int main()
{
    pthread_t threads[3];
    ThreadData thread_args[3] = {{1, "Hello"},{2, "World"},{3, "from here"}};
    // Create 5 threads
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&threads[i], NULL, printData, &thread_args[i]);
    }
    // Wait for all threads to complete
    for (int i = 0; i < 3; i++)
    {
        pthread_join(threads[i], NULL);
    }
    printf("All threads completed!\n");
    return 0;
}