#include"headers.h"
int main()
{
	int fd,i;
	char str[]="ABCDEFGHIJ";
	struct flock var;
	fd=open("datafile",O_RDWR|O_APPEND);
//////writing starts here..
printf("Enter to write:"); getchar();
////apply test and set operation.
	var.l_type=F_WRLCK;
	var.l_whence=0;//SEEK_SET
	var.l_start=0;
	var.l_len=0;//entire file , as the file grows, the new data also in the lock region
	fcntl(fd,F_SETLKW,&var);
	//fcntl will test for lock.
	//if lock is applied already, then process blocked
	//if lock not applied, then, apply the lock, and pprocess continues.
	for(i=0;str[i];i++)
	{
		printf("job:%d is writing\n",getpid());
		write(fd,str+i,1);
		sleep(1);
	}
	///writing ends here.
//	printf("enter to close fd");getchar();
	close(fd);
//	printf("enter to exit");getchar();
}
