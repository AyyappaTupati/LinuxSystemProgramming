#include"headers.h"
int main()
{
	int fd,i;
	char str[]="0123456789";
	struct flock var;
	fd=open("datafile",O_RDWR|O_APPEND);
printf("Enter to write.in job %d:",getpid()); getchar();
////apply test and set operation.
var.l_type=F_WRLCK;var.l_whence=0;var.l_start=0;var.l_len=0;
	fcntl(fd,F_SETLKW,&var);
	//if lock is applied already, then process blocked
	//if lock not applied, then, apply the lock, and process continues.
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
