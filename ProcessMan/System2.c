#include "header.h"

int main()
{
	printf("P1 PID =  %d  PPID = %d\n",getpid(), getppid());
	printf("Executing the P1 process\n");
	while(1);
}
