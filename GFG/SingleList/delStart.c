#include"header.h"
// delete element at start of the list

list * DelAtStart(list * head)
{
	list * temp = head;
	if(head == NULL)
	{
		printf("List is empty..\n");
		return NULL;
	}
	temp = head;
	head = head->link;
	printf("%d is deleted\n",temp->data);
	free(temp);
	temp = NULL;
	return head;
}
