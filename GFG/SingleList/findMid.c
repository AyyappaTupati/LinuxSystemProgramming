#include"header.h"

// find total count ,middle node

int findMiddle(list * head)
{
	list * temp = head;
	int NodeCount = 0, i = 1;

	while(temp != NULL)
	{
		NodeCount++;
		temp = temp->link;
	}
	printf("Total nodes are %d\n",NodeCount);
	NodeCount /=2;
	temp = head;
	while(i < NodeCount)
	{
		temp = temp->link;
		i++;
	}
	printf("Middle of the node is %d\n",temp->data);
	return temp->data;
}
