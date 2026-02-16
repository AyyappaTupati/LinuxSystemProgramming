#include"header.h"
int main()
{
	if(fork()==0)
	{
		printf("this is the child to call ls cmd\n");
		execl("/bin/ls","ls",NULL);
	}
	else
	{
		printf("This is the parent to call cal cmd\n");
		execl("/usr/bin/cal","cal",NULL);
	}
	return 0;
}
