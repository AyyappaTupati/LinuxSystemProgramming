#include<stdio.h>
#include<stdlib.h>

// list data type
typedef struct s {
	int data;
	struct s * link;
} list;

void printList(list * head);
void printListR(list * head);
list* deleteList(list * head);
list * createNode(int data);
int findMiddle(list * head);
int detectLoop(list *head);
list * AddAtStart(list * head, int data);
list * DelAtStart(list * head);
list * AddAtEnd(list * head, int data);
list * DelAtEnd(list * head);
list * AddAtMid(list * head, int data);
list * DelAtMid(list * head);
list * AddAtPos(list * head, int data,int pos);
list * DelAtPos(list * head, int pos);
list * ReverseListData(list * head);
list * ReverseListNode(list * head);
list* SortListNode(list *head);
list* SortListData(list *head);


