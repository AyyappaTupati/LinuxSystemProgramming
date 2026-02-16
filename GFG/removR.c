#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define S 10

void setArr(int a[])
{
	srand(getpid());
	for(int i=0;i<S;i++)
	{
		a[i] = rand()%10+1;
	}
}

void getArr(int a[])
{
	for(int i=0;i<S;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void sort(int a[]) // desending order
{
	int tmp;
	for(int i=0;i<S;i++)
	{
		for(int j=0;j<S;j++)
		{
			if(a[i] > a[j])
			{
				tmp  = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}	

void sortA(int a[]) // asending order
{
	int tmp;
	for(int i=0;i<S;i++)
	{
		for(int j=0;j<S;j++)
		{
			if(a[i] < a[j])
			{
				tmp  = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}	

void remRep(int a[])
{
	int tmp[1000] = {0};

	for(int i=0;i<S;i++)
		tmp[a[i]]++;

	for(int i=0;i<S;i++)
	{
		if(tmp[a[i]] > 1)
		{
			printf("%d ",a[i]);
			tmp[a[i]] = 0;
		}
	}
	printf("\n");
}

void remNRep(int a[])
{
	int tmp[1000] = {0};

	for(int i=0;i<S;i++)
		tmp[a[i]]++;

	for(int i=0;i<S;i++)
	{
		if(tmp[a[i]] == 1)
		{
			printf("%d ",a[i]);
		}
	}
	printf("\n");
}

void rev(int a[])
{
	int tmp;
	for(int i=0, j=S-1; i<j; i++, j--)
	{	
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}

void findH(int a[])
{
	int h = a[0];
	for(int i=0;i<S;i++)
	{
		if(a[i] > h)
		{
			h = a[i];
		}
	}
	printf("Highest = %d\n",h);
}
void findSH(int a[])
{
	int h = a[0];
	int sh = 0;

	for(int i=0;i<S;i++)
	{
		if(a[i] > h)
		{
			sh = h;
			h = a[i];
		}
		else if(a[i] > sh && a[i] < h)
		{
			sh = a[i];
		}
	}
	printf("Heighest = %d\n",h);
	printf("Second Highest = %d\n",sh);
}

void findL(int a[])
{
	int l = a[0];
	for(int i=0;i<S;i++)
	{
		if(a[i] < l)
		{
			l = a[i];
		}
	}
	printf("Lowest = %d\n",l);
}
void findSL(int a[])
{
	int l = a[0];
	int sl = 100;

	for(int i=0;i<S;i++)
	{
		if(a[i] < l)
		{
			sl = l;
			l = a[i];
		}
		else if(a[i] < sl && a[i] > l)
		{
			sl = a[i];
		}
	}
	printf("Lowest = %d\n",l);
	printf("Second Lowest = %d\n",sl);
}

	

int main()
{
	int a[S];
	setArr(a);
	getArr(a);
	rev(a);
	getArr(a);
	remRep(a);
	remNRep(a);
	sortA(a);
	getArr(a);
	findH(a);
	findSH(a);
	findL(a);
	findSL(a);
	return 0;
	//exit(1);
}





