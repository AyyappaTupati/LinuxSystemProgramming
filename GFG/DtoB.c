#include<stdio.h>
int main()
{
	int n = 10001101;
	int a = 1;
	int res = 0;
	while(n)
	{
		res = res + (n%10) *a;
		n /= 10;
		a *=2;
	}
	printf("%d\n",res);
	return 0;
}
