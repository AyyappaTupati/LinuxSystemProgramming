#include"headers.h"
int main(int argc,char **argv)
{
	int fd;
	char ch;
	fd=open(argv[1],O_WRONLY);
if(fd==-1){  	perror("open");exit(0);}
else
	printf("open success\n");


	if(write(fd,"xy",2)==-1)
		perror("write");
	else
		printf("write success\n");

	if(read(fd,&ch,1)==-1)
		perror("read");
	else{
		printf("read success\n");
		printf("ch=%c\n",ch);
	}

	close(fd);
	exit(0);


}
