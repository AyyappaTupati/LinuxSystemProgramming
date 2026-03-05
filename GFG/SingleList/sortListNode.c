#include "header.h"

list* SortListNode(list *head)
{
    if(head == NULL || head->link == NULL)
        return head;

    int swapped;
    list *ptr1;
    list *prev = NULL;

    do
    {
        swapped = 0;
        ptr1 = head;
        prev = NULL;

        while(ptr1->link != NULL)
        {
            list *next = ptr1->link;

            if(ptr1->data > next->data)
            {
                // Swap nodes

                if(prev == NULL)
                    head = next;
                else
                    prev->link = next;

                ptr1->link = next->link;
                next->link = ptr1;

                swapped = 1;

                prev = next;
            }
            else
            {
                prev = ptr1;
                ptr1 = ptr1->link;
            }
        }
    }
    while(swapped);

    return head;
}
