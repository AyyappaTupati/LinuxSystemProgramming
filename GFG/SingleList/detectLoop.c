#include "header.h"

// detecting the loop in the list

int detectLoop(list *head)
{
	list *slow = head;
	list *fast = head;

	while (fast != NULL && fast->link != NULL)
	{
		slow = slow->link;           // move 1 step
		fast = fast->link->link;     // move 2 steps

		if (slow == fast)
		{
			printf("Loop Detected\n");
			return 1;   // loop found
		}
	}
	printf("Loop not Detected\n");
	return 0;   // no loop
}
