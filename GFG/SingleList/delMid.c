#include "header.h"

list * DelAtMid(list * head)
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
	if(NodeCount > 1) NodeCount /=2;
	temp = head;
	prev = NULL;
	while(i <= NodeCount)
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
