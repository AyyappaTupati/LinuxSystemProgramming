#include"headers.h"
//f1 and f2 are two works to be done simultaneously... 
//Let f1 and f2 execute as two different(conurrent) jobs(process or thread)
void f1()
{
	printf("in f1\n");
	while(1);//some work

}

void f2()
{
	printf("in f2\n");
	while(1);//some work

}

int main()
{
	printf("enter to continue:");
	getchar();

	if(fork())
	       f1();
	else
	        f2();

}
