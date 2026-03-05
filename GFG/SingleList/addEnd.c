#include"header.h"

list * AddAtEnd(list * head, int data)
{
	list * newNode = createNode(data);
	list * temp = NULL;
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
	while(temp->link !=NULL) temp = temp->link;
	temp->link = newNode;
	return head;
}
