#include<stdio.h>
int main()
{
	int a=-100,b=500;
	printf("%d %d\n",a,b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("%d %d\n",a,b);
}
