#include "header.h"

void abc()
{
	printf("ABC function is called at the exit of the main function 1\n");
}
void xyz()
{
	printf("XYZ function is callled at the exit of the main function 2\n");
}
int main()
{
	printf("Main is executing ....\n");
	sleep(10);
	//here the at exit is executing the calling fuctions in last will be firs
	//atexit(xyz);
	//atexit(abc);
	
	atexit(abc);
	atexit(xyz);
	printf("Main register ABC to call at exit\n");

	printf("At the main last\n");
	sleep(5);
	exit(0);
}

