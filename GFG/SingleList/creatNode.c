#include "header.h"

// node creation

list * createNode(int data)
{
	list * newNode = (list *) malloc(sizeof(list));
	if(newNode == NULL)
	{
		return NULL;
	}
	else
	{
		newNode->data = data;
		newNode->link = NULL;
		return newNode;
	}
}
