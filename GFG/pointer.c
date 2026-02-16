#include<stdio.h>
int main()
{
	int a = 0x12345678;
	char * p =(char*) &a;

	char * p1 =(char*) &a+1;
	char * p2 =(char*) &a+2;
	char * p3 =(char*) &a+3;
	

	printf("%x\n",(char *)*p);
	printf("%x\n",(char *)*p1);
	printf("%x\n",(char *)*p2);
	printf("%x\n",(char *)*p3);
	return 0;
}
