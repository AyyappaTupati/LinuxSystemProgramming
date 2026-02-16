// shm_demo.c
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    int *shared = mmap(NULL, sizeof(int),
                       PROT_READ | PROT_WRITE,
                       MAP_SHARED | MAP_ANONYMOUS,
                       -1, 0);

    if (fork() == 0) {
        *shared = 100;
    } else {
        sleep(1);
        printf("Shared value = %d\n", *shared);
    }

    return 0;
}

