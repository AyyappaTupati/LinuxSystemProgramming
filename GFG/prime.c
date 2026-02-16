#include<stdio.h>
#include<stdbool.h>
bool isPrime(int num)
{
	int i=1,cnt=0;
	if(num<=1)return false;
	for(;i<=num;i++)
	{
		if(num%i == 0) cnt++;
	}
	if(cnt>2) return false;
	else return true;
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
