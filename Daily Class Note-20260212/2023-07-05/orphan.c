#include"headers.h"
void child()
{
	sleep(10);
	exit(0);
}

void parent()
{
	sleep(5);
	exit(0);
}

int main()
{
	if(fork()==0)
		child();
	else
		parent();

}
