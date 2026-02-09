#include"header.h"

int main()
{
	printf("Fome one parent we need to creat 3 childs processes\n");

	if(fork() == 0)
	{
		printf("This is the child 1 process PID = %d PPID = %d \n",getpid(), getppid());
	}
	else
	{
		if(fork()==0)
		{
			printf("This is the child 2 process PID = %d PPID = %d\n",getpid(),getppid());
		}
		else
		{
			if(fork()==0)
			{
				printf("This is the child 3 process PID = %d PPID = %d\n",getpid(),getppid());
			}
			else
			{
				printf("This is the Parent process PID = %d PPID = %d\n",getpid(),getppid());
			}
		}
		//printf("Im also Parent process PID = %d PPID = %d\n",getpid(),getppid());
	}
	return 0;
}

