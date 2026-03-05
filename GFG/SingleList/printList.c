// printing the list
#include"header.h"
void printList(list * head)
{
	if(!head)
	{
		printf("List is empty\n");
	}
	else
	{
		while(head !=NULL)
		{
			printf("%d ",head->data);
			head = head->link;
		}
		printf("\n");
	}
}
