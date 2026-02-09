#include "header.h"
int main()
{
	if(fork() ==0 )
	{
		printf("In child PID = %d PPID = %d\n",getpid(),getppid());
		sleep(10);
		printf("In child after sleep()\n");
		exit(1);
	}
	else
	{
		int res,status;
		printf("Waiting for child to complete\n");
		res = wait(&status);
		printf("The wait status of child is res = %d status = %d\n",res,status);
		while(1);
	}
}

