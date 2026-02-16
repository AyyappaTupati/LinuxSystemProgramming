#include<stdio.h>
int main()
{
	int num1=0,num2=0;
	scanf("%d",&num1);
	while(num1)
	{
		num2  = (num1%10) + (num2*10);
		num1 /= 10;
	}
	printf("%d",num2);
}
