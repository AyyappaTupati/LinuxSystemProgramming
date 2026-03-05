#include"header.h"
// add element at start of the list

list * AddAtStart(list * head, int data)
{
	list * newNode = createNode(data);
	if(newNode == NULL)
	{
		printf("Unable to create node\n");
		return NULL;
	}
	if(head == NULL)
	{
		return newNode;
	}
	newNode->link = head;
	return newNode;
}
