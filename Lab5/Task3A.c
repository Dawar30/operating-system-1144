#include <stdio.h> //In this task we are passing multiple arguments using cgpa and name
#include <pthread.h>
typedef struct
{
    int id;
    char *message;
    float cgpa;
} ThreadData;
void *printData(void *arg)
{
    ThreadData *data = (ThreadData *)arg;
    printf("Thread %d name: %s cgpa: %f\n", data->id, data->message, data->cgpa);
    return NULL;
}
int main()
{
    pthread_t t1, t2;
    ThreadData data1 = {1, "Dawar", 3.35};
    pthread_create(&t1, NULL, printData, &data1);
    //pthread_create(&t2, NULL, printData, &data2);
    pthread_join(t1, NULL);
    //pthread_join(t2, NULL);
    printf("All threads done.\n");
    return 0;
}