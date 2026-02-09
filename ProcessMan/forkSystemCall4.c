#include "header.h"

int main()
{
	if(fork() == 0)
	{
		printf("This is child process executing the LS command\n");
		system("ls");
	}
	else
	{
		printf("This is the parent process excuting the Cal command\n");
		system("cal");
	}

	return 0;
}
