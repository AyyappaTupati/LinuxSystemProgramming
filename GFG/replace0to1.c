#include<stdio.h>
#include<math.h>
int main()
{
	int j = 1002012;
	int res = 0;
	int i = 0;

	printf("%d\n",j);
	while(j)
	{
		if(j%10 == 0)
			res += 1*pow(10,i);
		else
			res += (j%10)*pow(10,i);
		j /= 10;
		i++;
	}
	printf("%d\n",res);
	return 0;
}
