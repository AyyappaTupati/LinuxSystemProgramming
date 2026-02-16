// process_demo.c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child PID: %d\n", getpid());
        execl("/bin/ls", "ls", NULL);  // Replace process image
    } else {
        // Parent process
        wait(NULL);  // Wait for child
        printf("Parent PID: %d\n", getpid());
    }

    return 0;
}

