#include"header.h"
int main()
{
	char * arg[] = {"/bin/ls","-l",NULL};

	execv(arg[0],arg);
	return 0;

}
