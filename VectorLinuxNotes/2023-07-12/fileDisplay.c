#include"headers.h"
int main(int argc,char **argv)
{
	int fd;
	char ch;
	fd=open(argv[1],O_RDONLY);
	if(fd<0)
	{
		perror("open");
		exit(0);
	}
	printf("fd=%d\n",fd);
	while(read(fd,&ch,1)==1)
		printf("%c",ch);


	close(fd);
}
