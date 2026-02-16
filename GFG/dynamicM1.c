#include<stdio.h>
int main()
{
	int * p = (int *)malloc(5*sizeof(int));

	srand(getpid());
	for(int i=0;i<5;i++)
	{
		*(p+i) = rand()%10;
	}
	for(int j=0;j<5;j++)
	{
		printf("%d ",*p+j);
	}
	printf("\n");
	free(p);
	p = NULL;
	p = (int *) realloc(p,10*sizeof(int));

	srand(getpid());
	for(int i=0;i<10;i++)
	{
		*(p+i) = rand()%10;
	}
	for(int j=0;j<10;j++)
	{
		printf("%d ",*p+j);
	}
	printf("\n");
        free(p);
	p = NULL;

	return 0;
}
