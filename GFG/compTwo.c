#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);

	if(!(a^b)) printf("%d and %d are equal \n",a,b);
	else printf("%d and %d are not equal\n",a,b);

	return 0;
}
