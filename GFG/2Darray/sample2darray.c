#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define COL 2
#define ROW 2

void setArr(int arr[][COL])
{
	for(int i=0;i<ROW;i++)
	{
		srand(getpid());
		for(int j=0;j<COL;j++)
		{
			arr[i][j] = rand()%20;
		}
	}
}

void getArr(int arr[][COL])
{
	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COL;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int arr[ROW][COL];
	setArr(arr);
	getArr(arr);
	return 0;
}







