#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define COL 5
#define ROW 5
#include <stdio.h>

void spiralPrint(int rows, int cols, int (*arr)[cols])
{
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right)
    {
        // Left → Right
        for (int i = left; i <= right; i++)
            printf("%d ", arr[top][i]);
        top++;

        // Top → Bottom
        for (int i = top; i <= bottom; i++)
            printf("%d ", arr[i][right]);
        right--;

        // Right → Left
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                printf("%d ", arr[bottom][i]);
            bottom--;
        }

        // Bottom → Top
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                printf("%d ", arr[i][left]);
            left++;
        }
    }
}
void setArr(int arr[][COL])
{
	for(int i=0;i<ROW;i++)
	{
		srand(i);
		for(int j=0;j<COL;j++)
		{
			arr[i][j] = rand()%10;
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
	spiralPrint(ROW,COL,arr);
	//getArr(arr);
	return 0;
}







