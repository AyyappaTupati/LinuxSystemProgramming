#include "header.h"

int main()
{
	printf("Fork system call is usde to creat a child procees inside a parent process\n");
	printf("This pecice of code is parent code PID is %d\n",getpid());
	pid_t child = fork();

	printf("The fork retun Child PID to parent and o to Child so Result = %d\n", child);
	if(child == 0)
	{
		printf("Im the child PID = %d PPID = %d\n",getpid(),getppid());
	}
	else
	{
		printf("Im the parent code PID = %d PPID = %d\n",getpid(),getppid());
	}

	printf("Im the comman code parent and child are executes me\n");
	return 0;
}

