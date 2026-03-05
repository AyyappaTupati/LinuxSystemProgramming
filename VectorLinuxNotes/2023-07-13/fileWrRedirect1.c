#include"headers.h"
int main()
{
	int fd1,fd2;
	fd1=open("datafile.txt",O_RDWR);
	if(fd1==-1){perror("open");exit(0);}

	printf("fd1=%d...in %d\n",fd1,getpid());
	//fd2=fcntl(fd1,F_DUPFD,0);
	fd2=dup(fd1);//creates a duplicate of existing descriptor.
		     //the new number will be the least-unused-filedescriptor.
	if(fd2<0){perror("dup");exit(0);}

	printf("fd1=%d fd2=%d\n",fd1,fd2);
lseek(fd1,0,2);
	if(write(fd1,"hello\n",6)<=0)
	{
		perror("write");
		exit(0);
	}
	printf("writing done successully\n");


	lseek(fd2,0,0);
	if(write(fd2,"HAI",3)<0){perror("write");exit(0);}




	close(fd1);
	close(fd2);
	exit(0);


}
