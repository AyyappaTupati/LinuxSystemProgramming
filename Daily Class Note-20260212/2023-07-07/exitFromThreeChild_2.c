#include"headers.h"
void myIsr(int n)
{
	//waitpid(-1,NULL,0);
}
void childCode()
{
	int r;
	srand(getpid());
	r=rand()%9+5;
	printf("child:%d..delay %d\n",getpid(),r);
	sleep(r);
	exit(r);

}
int main()
{
	struct sigaction newAct;
	int i;
	int var;
	for(i=1;i<=3;i++)
	{
		if(fork()==0)
		{	
		  childCode();
		}
	}
//signal(SIGCHLD,myIsr);	
newAct.sa_flags=SA_NOCLDWAIT;
newAct.sa_handler=myIsr;
sigemptyset(&newAct.sa_mask);
sigaction(17,&newAct,NULL);
	printf("in parent...\n");
	while(1);

}
