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

void findRepeat(int a[])
{
	int cnt = 0;
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			if(a[i] == a[j])
			{
				cnt++;
			}
		}
		if(cnt>1)
		{
			printf("%d ",a[i]);
			cnt = 0;
		}
	}
	printf("\n");
}

int main()
{
	int arr[SIZE];
	setArr(arr);
	getArr(arr);
	findRepeat(arr);
	revArr(arr);
	getArr(arr);
	return 0;
}


















