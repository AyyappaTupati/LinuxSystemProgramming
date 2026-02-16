#include"header.h"
int main()
{
	int c1,c2, res, st;
	c1 = fork();
	if(c1 == 0)
	{
		while(1)
		{
		   printf("This is the child one process PID = %d | PPID = %d\n",getpid(),getppid());
		   sleep(5);
		}

	}
	else
	{
		c2 = fork();
		if(c2 == 0)
		{
			while(1){
			printf("This is the child two process PID = %d | PPID = %d\n",getpid(),getppid());
			sleep(3);
			}
		}
		else
		{
			res = waitpid(c1,&st,WUNTRACED|WCONTINUED|WNOHANG);
			if(WIFEXITED(st))
			{
				printf(" The process %d is exited normally the status is %d\n",res,WEXITSTATUS(st));
			}
			if(WIFSIGNALED(st))
			{
				printf(" The process %d is terminated by the signal is %d\n",res,WTERMSIG(st));
			}
		}
	}
}
					

