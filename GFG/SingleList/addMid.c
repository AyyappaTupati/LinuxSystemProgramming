#include"header.h"

list * AddAtMid(list * head, int data)
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
	if(NodeCount > 1) NodeCount /=2;
	temp = head;
	while(i <= NodeCount)
	{
		prev = temp;
		temp = temp->link;
		i++;
	}
	prev->link = newNode;
	newNode->link = temp;
	return head;
}
