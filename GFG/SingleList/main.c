#include "header.h"

int main()
{
	list * head = NULL;
	int choice = 0;
	int data = 0;
	while(1)
	{
		printf("Enter the choice \n"
			"1) AddStart\n"
			"2) AddEnd\n"
			"3) AddMid\n"
			"4) AddPos\n"
			"5) DelStart\n"
			"6) DelEnd\n"
			"7) DelMid\n"
			"8) DelPos\n"
			"9) PrintList\n"
			"10) reverse printList\n"
			"11) Delete Full List\n"
			"12) find Mid\n"
			"13) detect Loop\n"
		        "14) Reverse List Nodes\n"
			"15) Reverse List Data\n"
			"16) Sort Nodes\n"
			"17) Sort Data\n"
		      );
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter data to add in List at Start\n");
				scanf("%d",&data);
			       	head = AddAtStart(head,data);
				break;
			case 2: printf("Enter data to add in List at End\n");
				scanf("%d",&data);
			       	head = AddAtEnd(head,data);
				break;
			case 3: printf("Enter data to add in List at Middle\n");
				scanf("%d",&data);
			       	head = AddAtMid(head,data);
				break;
			case 4: printf("Enter data to add in List at Position\n");
				printf("Enter the Postion to add\n");
				int pos ;
				scanf("%d%d",&data,&pos);
			       	head = AddAtPos(head,data,pos);
				break;
			case 5: head = DelAtStart(head);
				break;
			case 6: head = DelAtEnd(head);
				break;
			case 7: head = DelAtMid(head);
				break;
			case 8: printf("Enter the positoin to delete node\n");
				int pos1;
				scanf("%d",&pos1);
				head = DelAtPos(head,pos1);
				break;
			case 9: printList(head);
				break;
			case 10: printListR(head);
				 break;
			case 11: head = deleteList(head);
				 break;
			case 12: findMiddle(head);
				 break;
			case 13: detectLoop(head);
				 break;
			case 14: head = ReverseListNode(head);
				 break;
			case 15: head = ReverseListData(head);
				 break;
			case 16: head = SortListNode(head);
				 break;
			case 17: head = SortListData(head);
				 break;
		}
	}
	return 0;
}
