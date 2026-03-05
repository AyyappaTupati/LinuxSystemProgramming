#include"headers.h"
int main(int argc,char **argv)
{
	printf("jobID:%d....parentJobID:%d\n",getpid(),getppid());
	printf("enter to continue:");
	getchar();

	if(execlp(argv[1],argv[1],NULL)==-1)
		perror("execlp");
	else
		printf("success");

	return 0;


}
