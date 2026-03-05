#include "header.h"

list * AddAtPos(list * head, int data,int pos)
{
	list * newNode = createNode(data);
	list * temp = NULL, *prev = NULL;
	int NodeCount = 0, i = 1;

	if(newNode == NULL)
	{
		printf("Unable to create node\n");
		return NULL;
	}
	if(head == NULL)
	{
		return newNode;
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
	    newNode->link = head;
	    head = newNode;
	    return head;
	}
	temp = head;
	while(i < pos)
	{
		prev = temp;
		temp = temp->link;
		i++;
	}
	prev->link = newNode;
	newNode->link = temp;
	return head;
}
