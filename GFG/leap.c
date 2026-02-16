#include<stdio.h>
int main()
{
	int num;
	scanf("%d",&num);
	if(num%400 == 0 || num%4==0)
		printf("leap\n");
	else if(num%100 == 0)
		printf("not leap\n");
	else
		printf("not leap\n");
	return 0;
}

