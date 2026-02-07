#include "header.h"

int main()
{
	printf("P2 PID = %d PPID = %d\n",getpid(), getppid());
	printf("Using system execute the P1 Process\n");
	system("./P1");
}	
