#include<stdio.h>
int main()
{
	int a=10,b=20,tmp;
	printf("%d %d\n",a,b);
	tmp = a;
	a = b;
	b = tmp;
	printf("%d %d\n",a,b);
}
