#include "header.h"

list* SortListData(list *head)
{
    if(head == NULL)
        return NULL;

    list *i, *j;
    int temp;

    for(i = head; i->link != NULL; i = i->link)
    {
        for(j = i->link; j != NULL; j = j->link)
        {
            if(i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    return head;
}
