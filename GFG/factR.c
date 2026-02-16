#include<stdio.h>
unsigned long int fact(unsigned long int n)
{
	if(n==0) return 1;
	else return n* fact(n-1);
}
int main()
{
	unsigned long int num;
	scanf("%lu",&num);
	printf("%lu\n",fact(num));
	return 0;
}
	
