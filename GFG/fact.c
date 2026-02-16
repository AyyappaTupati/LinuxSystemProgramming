#include<stdio.h>
int main()
{
	int num;
	scanf("%d",&num);
	int fact = 1;
	while(num)
	{
		fact *=num;
		num--;
	}
	printf("%d",fact);
}	
