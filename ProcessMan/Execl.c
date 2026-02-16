#include"header.h"
int main()
{
	printf("This is the execl call\n");
	execl("/bin/ls","ls","-l","-a",NULL);
	return 0;
}
