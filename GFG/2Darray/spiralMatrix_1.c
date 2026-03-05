#include<stdio.h>

int main()
{
	int a[][3] ={
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	int top =0;
	int bottom = (sizeof(a) / sizeof(a[0])) -1 ;
	int left =0;
	int right = ( sizeof(a[0]) / sizeof(a[0][0])) -1;


	while(top <= bottom && left <= right)
	{
		// left - right
		for(int i=left;i<=right;i++)
		{
			printf("%d ",a[top][i]);
		}
		top++;
		// top to bottom
		for(int i=top;i<=bottom;i++)
		{
			printf("%d ",a[i][right]);
		}
		right--;

		// right to left 
		if(top <= bottom)
		{
			for(int i=right;i >= left;i--)
			{
				printf("%d ",a[bottom][i]);
			}
			bottom--;
		}

		// bottom to top
		if(left <= right)
		{
			for(int i=bottom;i >= top;i--)
			{
				printf("%d ",a[i][left]);
			}
			left++;
		}
	}
	return 0;
}
