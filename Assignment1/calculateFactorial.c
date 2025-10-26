//Dawar Abbas # Reg No. 1144
// In this program thread is calculating the factorial and returning its value

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void *calculateFactoraial(void *arg)
{
    int n = *(int *)arg;
    int *result = malloc(sizeof(int)); // Allocate memory for result
    *result = 1;
    for (int i = 1; i <= n; i++)
    {
        *result *= i; // factorial = factorial * i;
    }

    return (void *)result; // Return the result
}
int main()
{
    pthread_t thread_id;
    int n;
    printf("Enter a number greater than 0 to calculate factorial:");
    scanf("%d", &n);
    void *result;
    pthread_create(&thread_id, NULL, calculateFactoraial, &n);
    // Get the return value from thread
    pthread_join(thread_id, &result);

    printf("factorial of %d is %d\n", n, *(int *)result);
    free(result); // Don't forget to free allocated memory
    return 0;
}