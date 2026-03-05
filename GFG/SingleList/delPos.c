#include "header.h"

list * DelAtPos(list * head, int pos)
{
	list * temp = head;
	list * prev = head;
	int NodeCount = 0, i = 1;
	if(head == NULL)
	{
		printf("List is empty..\n");
		return NULL;
	}
	if(head->link == NULL)
	{
		printf("%d is deleted\n", head->data);
		free(head);
		head = NULL;
		return head;
	}
	temp = head;
	while(temp != NULL)
	{
		NodeCount++;
		temp = temp->link;
	}
	if(pos > NodeCount || pos <= 0)
	{
	    printf("Invalid position\n");
	    return head;
	}
	if(pos == 1)
	{
	    temp = head;
	    head = head->link;
	    printf("%d is deleted\n",temp->data);
	    free(temp);
	    temp = NULL;
	    return head;
	}
	temp = head;
	prev = NULL;
	while(i < pos)
	{
		prev = temp;
		temp = temp->link;
		i++;
	}
	printf("%d is deleted\n",temp->data);
	prev->link = temp->link;
	free(temp);
	temp = NULL;
	return head;
}
