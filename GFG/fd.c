// file_demo.c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("test.txt", O_CREAT | O_WRONLY, 0644);
    write(fd, "Linux Internals\n", 16);
    close(fd);
    return 0;
}

