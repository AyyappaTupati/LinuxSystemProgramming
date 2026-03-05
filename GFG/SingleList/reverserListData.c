#include "header.h"

list * ReverseListData(list * head)
{
    if (head == NULL)
    return NULL;

    // Step 1: count nodes
    int count = 0;
    list *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }

    // Step 2: store data in array
    int arr[count];
    temp = head;
    for (int i = 0; i < count; i++)
    {
        arr[i] = temp->data;
        temp = temp->link;
    }

    // Step 3: rewrite data in reverse order
    temp = head;
    for (int i = count - 1; i >= 0; i--)
    {
        temp->data = arr[i];
        temp = temp->link;
    }

    return head;
}
