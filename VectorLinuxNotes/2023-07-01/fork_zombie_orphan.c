#include"headers.h"
void p()
{	
	printf("parent Job:%d...parent:%d\n",getpid(),getppid());
	sleep(20);
	printf("parent g=%d(%d)... exiting\n",getpid(),getppid());

exit(0);
}

void c()
{
	printf("child job:%d...parent:%d\n",getpid(),getppid());
	sleep(5);
	printf("child...%d(%d) exiting\n",getpid(),getppid());


exit(0);
}
int main()
{
	int ret;
	ret=fork();
	//new job created will have PC, as a copy of parent.
	//fork() call happening in parent only..
	//But the assignment executed in parent and child both.
	//on success,the fork() returns 0 to child, and non-zero to parent.  
	//on failure, -1 returns.
	if(ret==-1){perror("fork");exit(0);}
	else if(ret==0)
		c();
	else
		p();

}
