#include "header.h"

list * DelAtEnd(list * head)
{
	list * temp = head;
	list * prev = head;
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
	while(temp->link !=NULL)
	{
		prev = temp;
		temp = temp->link;
	}
	printf("%d is deleted\n",temp->data);
	prev->link = NULL;
	free(temp);
	temp = NULL;
	return head;
}
