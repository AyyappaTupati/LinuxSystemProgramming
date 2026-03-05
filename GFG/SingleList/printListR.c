#include"header.h"
void printListR(list * head)
{
    if(head == NULL) return;

    printListR(head->link);
    printf("%d ", head->data);
}
