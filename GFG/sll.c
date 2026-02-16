#include<stdio.h>
#include<stdlib.h>

typedef struct sll{
	int data;
	struct sll *link;
}Slist;

Slist * creatNode(int data){
	Slist *newNode = (Slist *) malloc(sizeof(Slist));
	newNode->data = data;
	newNode->link = NULL;

	return newNode;
}

void printList(Slist * Head){
	Slist * Temp = Head;
	if(Head == NULL){
		printf("List is Empty\n");
		return ;
	}
	else
	{
		while(Temp != NULL)
		{
			printf("%d ",Temp->data);
			Temp = Temp->link;
		}
	}
}

void printReverse(Slist* Head)
{
    if (Head == NULL)
        return;

    printReverse(Head->link);
    printf("%d ", Head->data);
}

		

/************ add first & delete first *********/

Slist * addFirst(Slist *Head, int data){
	Slist * newNode = creatNode(data);

	if(Head == NULL) 
	{
		Head = newNode;
	}
	else
	{
		newNode->link = Head;
		Head = newNode;
	}
	return Head;
}


Slist * deleteFirst(Slist * Head){
	Slist * Temp = NULL;
	if(Head == NULL){
		printf("List is Empty\n");
		return NULL;
	}
	if(Head->link == NULL)
	{
		free(Head);
		Head = NULL;
		return NULL;
	}
	else
	{
		Temp = Head;
		Head = Temp->link;
		free(Temp);
		Temp = NULL;
	}
	return Head;
}

/****************** add last & delete last *********************/

Slist * addLast(Slist * Head, int data)
{
	Slist * newNode = creatNode(data);
	Slist * Temp = NULL;
	if(Head == NULL)
	{
		Head = newNode;
	}
	else
	{
		Temp = Head;

		while(Temp->link != NULL)Temp = Temp->link;

		Temp->link = newNode;
	}
	return Head;
}

Slist * deleteLast(Slist * Head)
{
	Slist * Temp = Head;
	Slist * Prev = NULL;
	if(Head == NULL)
	{
		printf("List is Empty\n");
		return NULL;
	}
	if(Head->link == NULL)
	{
		free(Head);
		Head = NULL;
		return NULL;
	}
	else
	{
		while(Temp->link != NULL)
		{
			Prev = Temp;
			Temp = Temp->link;
		}

		Prev->link = NULL;
		free(Temp);
		Temp = NULL;

	}
	return Head;
}

/***************** add middle , delete middle based on the position*******************/

/*Slist* addMiddle(Slist* Head, int data, int pos)
{
    Slist *newNode = creatNode(data);
    Slist *temp = Head;

    if (pos <= 1 || Head == NULL)
    {
        newNode->link = Head;
        return newNode;
    }

    for (int i = 1; i < pos-1 && temp->link != NULL; i++)
    {
        temp = temp->link;
    }

    newNode->link = temp->link;
    temp->link = newNode;

    return Head;
}


Slist* deleteMiddle(Slist* Head, int pos)
{
    Slist *temp = Head;
    Slist *prev = NULL;

    if (Head == NULL)
    {
        printf("List is Empty\n");
        return NULL;
    }

    if (pos <= 1)
    {
        return deleteFirst(Head);
    }

    for (int i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL)
        return Head;

    prev->link = temp->link;
    free(temp);

    return Head;
}**********************************************************/

/****************** add middle & delete middle based on the pointer slow,fast*****************/
/*Slist* addMiddle(Slist* Head, int data)
{
    Slist *slow = Head;
    Slist *fast = Head;
    Slist *newNode = creatNode(data);

    if (Head == NULL)
        return newNode;

    while (fast->link != NULL && fast->link->link != NULL)
    {
        slow = slow->link;
        fast = fast->link->link;
    }

    newNode->link = slow->link;
    slow->link = newNode;

    return Head;
}

Slist* deleteMiddle(Slist* Head)
{
    Slist *slow = Head;
    Slist *fast = Head;
    Slist *prev = NULL;

    if (Head == NULL)
    {
        printf("List is Empty\n");
        return NULL;
    }

    // If only one node
    if (Head->link == NULL)
    {
        free(Head);
        return NULL;
    }

    while (fast != NULL && fast->link != NULL)
    {
        fast = fast->link->link;
        prev = slow;
        slow = slow->link;
    }

    // slow is middle node
    prev->link = slow->link;
    free(slow);

    return Head;
}
*/



Slist* addMiddle(Slist* Head, int data)
{
    int count = 0;
    Slist *temp = Head;
    Slist *newNode = creatNode(data);

    if (Head == NULL)
        return newNode;

    // 1st pass: count nodes
    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }

    int mid = count / 2;

    temp = Head;

    // 2nd pass: reach middle
    for (int i = 1; i < mid; i++)
        temp = temp->link;

    newNode->link = temp->link;
    temp->link = newNode;

    return Head;
}

Slist* deleteMiddle(Slist* Head)
{
    Slist *temp = Head;
    Slist *prev = NULL;
    int count = 0, mid = 0, i = 0;

    if (Head == NULL)
    {
        printf("List is Empty\n");
        return NULL;
    }

    // Step 1: Count nodes
    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }

    // Step 2: Find middle index
    mid = count / 2;

    // Step 3: If only one node
    if (count == 1)
    {
        free(Head);
        return NULL;
    }

    // Step 4: Traverse to middle
    temp = Head;
    while (i < mid)
    {
        prev = temp;
        temp = temp->link;
        i++;
    }

    // Step 5: Delete middle
    prev->link = temp->link;
    free(temp);

    return Head;
}


/**************** find medium *************/
void findMedian(Slist* Head)
{
    Slist *slow = Head;
    Slist *fast = Head;

    if (Head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    while (fast != NULL && fast->link != NULL)
    {
        slow = slow->link;
        fast = fast->link->link;
    }

    printf("Median = %d\n", slow->data);
}


int main()
{
	Slist * Head = NULL;
	int option;
	int ListData;

	while(1)
	{
		printf("\nEnter the option \n"
			"1) Add First\n"
			"2) Add Last\n"
			"3) Add Middle\n"
			"4) Delete First\n"
			"5) Delete Last\n"
			"6) Delete Middle\n"
			"7) Print\n"
			"8) Reverse Print\n"
			"9) Exit\n");
		scanf("%d",&option);

		switch(option)
		{
			case 1: printf("Enter data to at first\n");
				scanf("%d",&ListData);
				Head = addFirst(Head,ListData);
				break;
 
			case 2: printf("Enter data to at last\n");
				scanf("%d",&ListData);
				Head = addLast(Head,ListData);
				break;
			case 3: printf("Enter data to at middle\n");
				scanf("%d",&ListData);
				Head = addMiddle(Head,ListData);
				break;
			 
			case 4: printf("Delete at first\n");
				Head = deleteFirst(Head);
				break;

			case 5: printf("Delete at last\n");
				Head = deleteLast(Head);
				break;

			case 6: printf("Delete at middle\n");
				Head = deleteMiddle(Head);
				break;

			case 7: printList(Head);
				break;

			case 8: printReverse(Head);
				break;

			case 9: exit(0);

		}
	}
	return 0;
}




