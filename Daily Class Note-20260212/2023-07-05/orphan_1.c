#include"headers.h"
void child()
{
	sleep(10);
	exit(0);
}

void parent()
{
	sleep(5);

	wait(NULL);//wait systemcall, makes the parent block.
		   //Blocked until, child status change..
	exit(0);
}

int main()
{
	if(fork()==0)
		child();
	else
		parent();

}
