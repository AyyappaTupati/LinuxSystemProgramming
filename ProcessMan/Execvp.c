#include"header.h"
int main()
{
	printf("This is the execvp system call\n");
	char *arg[] = {"cal","2","2026",NULL};

	execvp(arg[0],arg);
	return 0;
}
