#include<stdio.h>
int main()
{
	int num,rev=0;
	scanf("%d",&num);
	//printf("%d\n",num);
	int t = num;
	while(num)
	{
		rev = (rev*10) + (num%10); 
		num /= 10;
	}
	if(rev == t)
		printf("%d is pallandrom\n",rev);
	else 
		printf("%d is not pallindrome\n",rev);

	return 0;
}
