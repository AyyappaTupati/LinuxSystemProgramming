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
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		if(isPrime(i))
		{
			printf("%d is prime\n",i);
		}
		else
		{
			printf("%d is not prime\n",i);
		}
	}
	return 0;
}
