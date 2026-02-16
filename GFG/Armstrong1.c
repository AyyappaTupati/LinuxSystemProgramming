#include<stdio.h>
int main()
{
	int num1,num2,temp,res,cnt;

	scanf("%d",&num1);

	num2 = temp = num1;

	while(temp)
	{
		temp /= 10;
		cnt++;
	}

	while(num2)
	{
		for(int i=1;i<=cnt;i++) temp *= num2%10;
		res += temp;
		num2 /= 10;
	}
	if(res == num1) printf("%d is armstrong\n",res);
	else printf("%d is not armstrong\n",res);
	return 0;
}
