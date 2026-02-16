//using read and write system calls, we need to implement cp command.
#include"headers.h"
int main(int argc,char **argv)
{
	
	int sFd,dFd;
	char ch;
	///process has 3 file descriptors 0,1,2
//	printf("Process Id: %d\n",getpid());
//	printf("enter to continue:");
//	getchar();
	sFd=open(argv[1],O_RDONLY);//src
	//process has four number of fds 0,1,2,3
//	printf("enter to continue:");
//	getchar();
	dFd=creat(argv[2],0660);//dest
	//dFd=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC, 0660);//dest
	//0,1,2,3,4
	while(read(sFd,&ch,1)==1)
		write(dFd,&ch,1);
//	printf("enter to continue:");
//	getchar();

	close(sFd);
	//0,1,2,4
//	printf("enter to continue:");
//	getchar();
	close(dFd);
	//0,1,2
//	printf("enter to continue:");
//	getchar();
printf("copy success\n");
}
