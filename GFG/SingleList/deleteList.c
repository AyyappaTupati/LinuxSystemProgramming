#include"header.h"

// deleting the list

list* deleteList(list * head)
{
	list * temp = NULL;
	while(head != NULL)
	{
		temp = head;
		head = head->link;
		free(temp);
		temp = NULL;
	}
	printf("List deleted...\n");
	return head;
}
