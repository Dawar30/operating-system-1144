#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void *checkPrimeNumber(void *arg)
{
    int n = *(int *)arg;
    int *result = malloc(sizeof(int)); // Allocate memory for result
    *result = 0;
    if (n <= 1)
    {
        *result = 0; // Numbers less than or equal to 1 are not prime
    }
    else if (n == 2)
    {
        *result = 1; // 2 is the only even prime number
    }
    else if (n % 2 == 0)
    {
        *result = 0; // Other even numbers are not prime
    }
    else
    {
        *result = 1;
        // Check for divisibility by odd numbers up to the square root of n
        for (int i = 3; i * i <= n; i += 2)
        {
            if (n % i == 0)
            {
                *result = 0; // If divisible, it's not prime
                break;       // Exit the loop early
            }
        }
    }
    return (void *)result; // Return the result
}
int main()
{
    pthread_t thread_id;
    int n = 17;
    void *result;
    pthread_create(&thread_id, NULL, checkPrimeNumber, &n);
    // Get the return value from thread
    pthread_join(thread_id, &result);
    if (*(int*)result == 0)
    {
        printf("%d is not a prime number\n",n);
    }
    else
    {
        printf("%d is a prime number\n",n);
    }
    free(result); // Don't forget to free allocated memory
    return 0;
}