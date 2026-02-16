// pipe_demo.c
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        // Child reads
        close(fd[1]);
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
    } else {
        // Parent writes
        close(fd[0]);
        write(fd[1], "Hello from parent", 18);
    }

    return 0;
}

