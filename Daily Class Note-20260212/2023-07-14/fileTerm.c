#include"headers.h"
int main()
{
	int fd;
	char str[20];
	fd=open("/dev/pts/1",O_RDWR|O_APPEND);
	if(fd<0){perror("open");exit(0);}

	do{
		puts("enter a string:");
		fgets(str,20,stdin);
		write(fd,str,strlen(str)+1);		
	}while(!strstr(str,"QUIT"));
	
	exit(0);

}
