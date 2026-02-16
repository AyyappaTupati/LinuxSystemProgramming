#include"headers.h"
int g=10;
void p()
{	
	printf("parent Job:%d...parent:%d\n",getpid(),getppid());
	printf("in parent:g=%d\n",g);
	sleep(1);
	printf("in parent g=%d... exiting\n",g);

exit(0);
}

void c()
{
	printf("child job:%d...parent:%d\n",getpid(),getppid());
	g+=20;
	printf("in child:g=%d\n",g);
	sleep(3);
	printf("child...g=%d exiting\n",g);


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
