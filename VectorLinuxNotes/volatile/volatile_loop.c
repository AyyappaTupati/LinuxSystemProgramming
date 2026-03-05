#include<stdio.h>
//program to be compiled with  gcc -g -O3 -faggressive-loop-optimizations   prog.c
//should use single stepping in gdb, to observe  the behaviour.
volatile int a=0;//using volatile, the optimisation on variable a is prohibited
//int a=0;
int b=0;
int main()
{
	++a;
	++b;
	printf("a=%d b=%d\n",a,b);
	while(a<100)
	{
		b=a;
		a++;
	}
	printf("after loop: a=%d b=%d\n",a,b);
}









