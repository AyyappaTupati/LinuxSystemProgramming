#include"headers.h"
void child()
{
	int x=5;
	sleep(5);
	printf("Bye.. from ..child\n");
	exit(5);
}

void parent()
{
	int y;
//	sleep(10);
	wait(NULL);
	sleep(10);
//	y>>=8;
//	printf("y=%d\n",y);
	exit(0);
}

int main()
{
	if(fork()==0)
		child();
	else
		parent();

}
