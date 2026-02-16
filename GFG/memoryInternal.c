// memory_demo.c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = malloc(1000000 * sizeof(int));

    for(int i = 0; i < 1000000; i++)
        ptr[i] = i;  // Physical memory assigned here (page fault)

    free(ptr);
    return 0;
}

