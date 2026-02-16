#include"headers.h"
int main()
{
	if(fork()==0)
	{//child code....
		int r;
		srand(getpid());
		r=rand()%10;
		printf("child...r=%d\n",r);
		sleep(r);
		exit(r);
	}
	else
	{
	int v;
	printf("in parent...waiting...\n");
	wait(&v);//the exit value will be collected in bit 15-8
	v>>=8;
	printf("parent...v=%d\n",v);
	exit(0);
	}

}
