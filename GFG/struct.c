#include<stdio.h>
/*
struct st
{
	int a;
	float b;
	double d;
	char c;
};
// 24 bytes
*/


struct st
{
	char c ;
	char dd;
	short d;
	//char dd;
	int a;
	//char dcc;
	double ddd;
};
//16 bytes

int main()
{
	printf("%ld\n",sizeof(struct st));
	return 0;
}
