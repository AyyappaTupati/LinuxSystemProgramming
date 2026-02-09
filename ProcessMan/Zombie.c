#include "header.h"

int main()
{
	if(fork() == 0)
	{
		printf("In child PID = %d PPID = %d\n",getpid(),getppid());
		sleep(1);
		printf("In child PID = %d PPID = %d\n",getpid(),getppid());
	}
	else
	{
		printf("In parent PID = %d PPID = %d\n",getpid(),getppid());
		while(1);
	}
}
