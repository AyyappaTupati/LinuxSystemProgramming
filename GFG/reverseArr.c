#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#define SIZE 10
void setArr(int a[])
{
	srand(getpid());
	for(int i=0;i<SIZE;i++)
	{
		a[i] = rand()%10+1;
	}
}
void getArr(int a[])
{
	for(int i=0;i<SIZE;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void revArr(int a[])
{
	for(int i=0,j=SIZE-1;i<j;i++,j--)
	{
		a[i] = a[i] + a[j];
		a[j] = a[i] - a[j];
		a[i] = a[i] - a[j];
	}
}


int main()
{
	int arr[SIZE];
	setArr(arr);
	getArr(arr);
	revArr(arr);
	getArr(arr);
	return 0;
}


















