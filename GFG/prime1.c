#include<stdio.h>
#include<stdbool.h>
bool isPrime(int num)
{
	int i=2,cnt=0;
	if(num<=1)return false;
	for(;i*i<=num;i++)
	{
		if(num%i == 0) return false;
	}
	return true;
}
int main()
{
	int n;
	scanf("%d",&n);
	if(isPrime(n))
	{
		printf("%d is prime\n",n);
	}
	else
	{
		printf("%d is not prime\n",n);
	}
	return 0;
}
