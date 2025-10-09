#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process runs 'top'
        execlp("top", "top", "-b" , NULL);
        printf("This will not print if exec succeeds.\n");
    } else {
        // Parent process message
        printf("Parent still running...\n");
    }

    return 0;
}
