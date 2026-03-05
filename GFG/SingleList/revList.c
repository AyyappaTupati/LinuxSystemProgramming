#include "header.h"

list * ReverseList(list * head)
{
    list * prev = NULL;
    list * current = head;
    list * next = NULL;

    while(current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    return prev;
}
