#include"headers.h"
int main()
{
	int fd;
	char str[20];
	
	fd=open("fifo1",O_WRONLY);
	if(fd==-1){perror("open");exit(0);}

	printf("fd=%d\n",fd);

	do
	{
		printf("Enter msg(QUIT to stop):");
		gets(str);
	write(fd,str,strlen(str)+1);
	printf("%d:%s\n",getpid(),str);

	}while(strcmp(str,"QUIT"));

	close(fd);

}

