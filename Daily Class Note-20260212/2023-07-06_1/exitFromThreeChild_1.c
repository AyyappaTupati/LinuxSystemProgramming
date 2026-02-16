#include"headers.h"
void childCode()
{
	int r;
	srand(getpid());
	r=rand()%9+1;
	printf("child:%d..delay %d\n",getpid(),r);
	sleep(r);
	exit(r);

}
int main()
{
	int i;
	int var;
	for(i=1;i<=3;i++)
	{
		if(fork()==0)
		{	
		  childCode();
		}
	}

	printf("in parent...code...waiting...\n");
while(wait(&var)!=-1)
{
	var>>=8;
	printf("child exited..exit value:%d\n",var);
}

}
