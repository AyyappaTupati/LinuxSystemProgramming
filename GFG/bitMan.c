#define setbit(bata,pos) bata = bata | (1<<pos)
#define clrbit(bata,pos) bata = bata & (~(1<<pos))
#define togbit(bata,pos) data = data ^ (1<<pos)

#define setbit2(bata,pos) bata = bata | (3<<pos)
#define clrbit2(bata,pos) bata = bata & (~(3<<pos))
#define togbit2(bata,pos) data = data ^ (3<<pos)

#define setbit3(bata,pos) bata = bata | (7<<pos)
#define clrbit3(bata,pos) bata = bata & (~(7<<pos))
#define togbit3(bata,pos) data = data ^ (7<<pos)

#define setbit4(bata,pos) bata = bata | (15<<pos)
#define clrbit4(bata,pos) bata = bata & (~(15<<pos))
#define togbit4(bata,pos) data = data ^ (15<<pos)

#include<stdio.h>

void printB(int n,int s)
{
	printf("%d\n",n);
	for(int i = s-1; i >= 0 ;i--)
	{
		if( (n>>i)&1) printf("1");
		else printf("0");
	}
	printf("\n");
}

int main()
{
	int a = -128;
	printB(a,32);
	clrbit(a,31);
	printB(a,32);


	setbit4(a,0);
	printB(a,32);

	return 0;
}
