#include<stdio.h>
int main()
{
	int num1=0,num2=0,temp=0,res=0,cnt=0;

	scanf("%d",&num1);

	num2 = temp = num1;
	if(num1 == 0) cnt = 1;
	else
	{
	while(temp)
	{
		temp /= 10;
		cnt++;
	}
	}
	temp = 1;
	while(num2)
	{
		for(int i=1;i<=cnt;i++) 
		{
			temp *= num2%10;
		}
		res += temp;
		temp = 1;
		num2 /= 10;
	}
	if(res == num1) printf("%d is armstrong\n",res);
	else printf("%d is not armstrong\n",res);
	return 0;
}
