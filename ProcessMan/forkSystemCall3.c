#include"header.h"

int main()
{
	printf("Creat process tree like parent->child1 | child1->child2 | child2->child3\n");
	printf("This is the parent code PID = %d PPID = %d \n",getpid(),getppid());
	if(fork()==0)
	{
		printf("This is the child1 process PID = %d PPID = %d\n",getpid(), getppid());
		if(fork() == 0)
		{
			printf("This is the child2 process PID = %d PPID = %d\n",getpid(), getppid());
		}
		else
		{

		}
	}
	else
	{

	}
}



